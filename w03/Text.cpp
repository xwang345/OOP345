/////////////////////////////////////////////
// OOP345 Workshop 3: Move and Copy Semantics 
// Name: Sanghun Kim
// Date: 10/10/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////



#include "Text.h"
#include <new>

#include <fstream>
#include <iostream>


// file conversion //
// dos2unix filethatyouupload.txt //


using namespace std;
namespace w3
{
	Text::Text()
	{
		m_pString = nullptr;
		m_numOfString = 0;
	}

	Text::Text(const char* filename){
		ifstream fp(filename);

		m_numOfString = 0;
		std::string strRecord;
		if (fp.is_open()){
			std::string unused;
			while (getline(fp, strRecord)){
				++m_numOfString;
			}
			

			// alocate string memory //
			if (m_numOfString > 0){
				m_pString = new std::string[m_numOfString];
				
				fp.clear();
				fp.seekg(0, fp.beg);
				//	std::string* pStart = m_pString;
				int idx = 0;

				while (getline(fp, m_pString[idx])){
			//	while (getline(fp, strRecord)){
				//	m_pString[idx] = strRecord;
				//	idx++;
				}
			}
			
			fp.close();
		}
	}


	void Text::init(const Text& text)
	{
		m_numOfString = text.size();
		m_pString = new string[m_numOfString];
		unsigned i;
		for (i = 0; i < m_numOfString; i++){
			m_pString[i] = text.m_pString[i];
		}
	}

	Text::Text(const Text& text)  // copy constructor
	{
		init(text);
	}
	Text::Text(Text&& text)		// move constructor
	{
		m_numOfString = text.size();
		m_pString = text.m_pString;

		text.m_pString = nullptr;
		text.m_numOfString = 0;
	}



	Text& Text::operator=(const Text& text)	// copy assignment operator
	{
		init(text);
		return *this;
	}
	Text&& Text::operator=(Text&& text)		// move assignment operator
	{
		m_numOfString = text.size();
		m_pString = text.m_pString;

		text.m_pString = nullptr;
		text.m_numOfString = 0;

		return std::move(*this);
	}



	Text::~Text()
	{
	//	std::cout << "Destuction" << endl;
		if (m_pString != nullptr){
	//		std::cout << "Delete - Destuction" << endl;
			delete[] m_pString;
		}
	}

}
