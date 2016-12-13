/////////////////////////////////////////////
// Workshop 10 - Multi-Threading
// Name: Sanghun Kim
// Date: 12/10/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////

// Workshop 10 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include "SecureData.h"

namespace w10 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key) {
		// open text file
		std::fstream input(file, std::ios::in);
		if (!input)
			throw std::string("\n***Failed to open file ") +
			std::string(file) + std::string(" ***\n");

		// copy from file into memory
		nbytes = 0;
		input >> std::noskipws;
		while (input.good()) {
			char c;
			input >> c;
			nbytes++;
		}
		nbytes--;
		input.clear();
		input.seekg(0, std::ios::beg);
		text = new char[nbytes + 1];

		int i = 0;
		while (input.good())
			input >> text[i++];
		text[--i] = '\0';
		std::cout << "\n" << nbytes << " bytes copied from text "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		std::cout << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key) {
		//converter(text, key, nbytes, Cryptor());
		//encoded = !encoded;

		const int numOfThreads = 4;
		const int chunkSize = nbytes / numOfThreads;
		std::thread threads[numOfThreads];
		Cryptor cryptors[numOfThreads];

		for (int i = 0; i<numOfThreads; i++) {
			unsigned int size = chunkSize;
			if (i == numOfThreads - 1){
				size = (nbytes - i*chunkSize);
			}			
			auto func = std::bind(converter, text + i * chunkSize, key, size, cryptors[i]);
			threads[i] = std::thread(func);
		}

		for (unsigned int i = 0; i < numOfThreads; i++){
			threads[i].join();
		}
		encoded = !encoded;

	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else {
			// open binary file
			std::fstream os(file, std::ios::out);
			if (!os){
				throw "failed to open file " + std::string(file);
			}
			// write binary file here
			for (int i = 0; i < nbytes; ++i){
				os << text[i];
			}

		}
	}

	void SecureData::restore(const char* file, char key) {
		// open binary file
		std::fstream ifs(file, std::ios::in);
		if (!ifs) throw "failed to open file " + std::string(file);

		// allocate memory here
		nbytes = 0;
		ifs >> std::noskipws;
		char tmpc;
		while (ifs.good()) {
			ifs >> tmpc;
			nbytes++;
		}
		if (text){
			delete[] text;
			text = nullptr;
		}
		text = new char[nbytes + 1];

		// read binary file here
		ifs.clear();
		ifs.seekg(0, std::ios::beg);
		nbytes = -1;
		while (ifs.good()){
			ifs >> text[++nbytes];
		}
		text[nbytes + 1] = '\0';


		std::cout << "\n" << nbytes+1 << " bytes copied from binary file "
			<< file << " into memory (null byte included)\n";
		encoded = true;

		// decode using key
		code(key);
		std::cout << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}

}