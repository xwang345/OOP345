
/////////////////////////////////////////////
// OOP345 Workshop 2: Compound Types
// Name: Sanghun Kim
// Date: 10/10/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////

#pragma once
#include "Station.h"
namespace w2
{
	class Stations
	{
	public:
		Stations();
		~Stations();
		Stations(char* strfile);

		void update() const;
		void restock() const;
		void report() const;

	private:
		Station* pStation;
		unsigned m_numOfStn;
	};
}

