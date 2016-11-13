/////////////////////////////////////////////
// OOP345 milestone 1: 
// Name: Sanghun Kim
// Date: 11/13/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////

#pragma once
#include <string>
#include <fstream>

class Utilities {
	size_t field_width;           // maximum field width needed 
	static char delimiter;        // field delimiter character
	static std::ofstream logFile; // log file
public:
	Utilities();
	size_t getFieldWidth() const;
	const std::string nextToken(const std::string&, size_t&, bool&);
	static void setDelimiter(const char);
	static void setLogFile(const char*);
	static std::ofstream& getLogFile();
};

