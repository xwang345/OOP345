#pragma once


#include <string>
namespace w2{

	enum PassType  { _STUDENT, _ADULT };
	class Station
	{
	public:
		Station();
		~Station();

		void set(const std::string& , unsigned  _numOfStuentPass, unsigned  _numOfAdultPass);
		void update(PassType,   int );
		unsigned inStock(PassType ) const;
		const std::string& getStnName() const;

	private:
		std::string strStnName;
		unsigned int numOfStuentPass;
		unsigned int numOfAdultPass;
	};

}

