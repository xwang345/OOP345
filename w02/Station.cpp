#include "Station.h"

namespace w2
{
	Station::Station()
	{
	}


	Station::~Station()
	{
	}


	void Station::set(const std::string& _str, unsigned int _numOfStuentPass, unsigned int _numOfAdultPass)
	{
		strStnName = _str;
		numOfStuentPass = _numOfStuentPass;
		numOfAdultPass = _numOfAdultPass;

	}
	void Station::update(PassType  type, int _numOfPass)
	{
		int tmpNum;
		switch (type)
		{
		case w2::_STUDENT:
			tmpNum = numOfStuentPass + _numOfPass;
			if (tmpNum < 0){
				numOfStuentPass = 0;
			}
			else{
				numOfStuentPass = tmpNum;
			}
			break;
		case w2::_ADULT:
			tmpNum = numOfAdultPass + _numOfPass;
			if (tmpNum < 0){
				numOfAdultPass = 0;
			}
			else{
				numOfAdultPass = tmpNum;
			}		
			break;
		default:
			break;
		}

	}
	unsigned int Station::inStock(PassType  type) const
	{
		unsigned int res = 0;
		switch (type)
		{
		case w2::_STUDENT:
			res = numOfStuentPass;
			break;
		case w2::_ADULT:
			res = numOfAdultPass;
			break;
		default:
			break;
		}

		return res;
	}

	const std::string& Station::getStnName() const
	{
		return strStnName;
	}
}
