#include "process.h"

void process(const char* pCStyleStr)
{
	ksh::CString a(pCStyleStr);
	std::cout << a << std::endl;
}

