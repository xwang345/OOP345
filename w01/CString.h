
/////////////////////////////////////////////
// OOP345 Workshop 1: From One Translation Unit to Another 
// Date: 9/14/2016
// Name: Sanghun Kim
// Date: 2/10/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////

#ifndef KSH_STRING_H_
#define KSH_STRING_H_

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


const int MAX = 3;

namespace ksh
{
	class CString
	{
	private:
		char pString[MAX + 1];
	public:
		CString();
		CString(const char* _inputStr);
		~CString();
		std::ostream& display(std::ostream& os)const;
	};

	std::ostream& operator<<(std::ostream& os, const CString& str);
}


#endif
