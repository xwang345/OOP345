/////////////////////////////////////////////
// OOP345 Workshop 2: Compound Types
// Name: Sanghun Kim
// Date: 10/10/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////

#include "process.h"

void process(const char* pCStyleStr)
{
	ksh::CString a(pCStyleStr);
	std::cout << a << std::endl;
}

