#pragma once


#include <string>
namespace w2{

	enum PassType  { _STUDENT, _ADULT };
	class Station
	{
	public:
		Station();
		~Station();

		void set(const std::string& _str, unsigned int _numOfStuentPass, unsigned int _numOfAdultPass);
		void update(PassType  type, int _numOfPass);
		unsigned int inStock(PassType  type) const;
		const std::string& getStnName() const;

	private:
		std::string strStnName;
		unsigned int numOfStuentPass;
		unsigned int numOfAdultPass;
	};

}

