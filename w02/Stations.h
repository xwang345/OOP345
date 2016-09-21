


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
		int m_numOfStn;
	};
}

