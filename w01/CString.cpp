#include "CString.h"


namespace ksh
{
	CString::CString()
	{
		pString[0] = 0;
	}

	CString::CString(const char* _inputStr)
	{
		if (_inputStr != NULL){
			strncpy(pString, _inputStr, MAX);
			pString[MAX] = 0;
		}
		else{
			pString[0] = 0;
		}
	}
	CString::~CString()	{}

	std::ostream& CString::display(std::ostream& os)const{
		static int count = 0;
		return os << count++ << ": " << pString;
	}

	std::ostream& operator<<(std::ostream& os, const CString& str){
		return str.display(os);
	}
}

