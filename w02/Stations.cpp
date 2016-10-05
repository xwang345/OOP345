#include "Stations.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>


using namespace std;
#define MAX_PATH 64
namespace w2
{
	Stations::Stations()
	{
		m_numOfStn = 0;
		pStation = 0;
	}


	Stations::~Stations()
	{
		if (pStation){
			delete[] pStation;
		}
	}


	Stations::Stations(char* strfile)
	{
		ifstream fileIn (strfile);
		if (!fileIn.is_open()){
			cerr << "File is not open" << endl;
		}
		else{
			char readBuff[MAX_PATH];

			char stnName[MAX_PATH];
			unsigned int nStudent;
			unsigned int nAdult;


		//	fileIn.ignore();
			fileIn.getline(readBuff, MAX_PATH, ';');
			m_numOfStn = atoi(readBuff);

			fileIn.ignore();

			if (m_numOfStn > 0){
				pStation = new Station[m_numOfStn];

				fileIn.ignore();
				unsigned i;
				for (i = 0; i < m_numOfStn; i++){					
					
					fileIn.getline(stnName, MAX_PATH, ';');						

					fileIn.getline(readBuff, MAX_PATH, ' ');
					nStudent = atoi(readBuff);
					
					fileIn.getline(readBuff, MAX_PATH);
					nAdult = atoi(readBuff);			


					pStation[i].set(stnName, nStudent, nAdult);
				}				
			}
			else{
				cerr << "File is empty" << endl;
			}
		}
	}

	void Stations::update() const
	{
		
		int nStudent = 0, nAdult = 0;
		
		unsigned i;
		cout << "\nPasses Sold :" << endl;
		cout << "-------------" << endl;
		for (i = 0; i < m_numOfStn; i++){
			cout << pStation[i].getStnName() << endl;
			cout << " Student Passes sold : ";		cin >> nStudent;
			cout << " Adult   Passes sold : ";		cin >> nAdult;

			pStation[i].update(_STUDENT, -nStudent);
			pStation[i].update(_ADULT, -nAdult);
		}
	}



	void Stations::restock() const
	{
		unsigned i;
		int nStudent = 0, nAdult = 0;

		cout << "\nPasses Added :" << endl;
		cout << "--------------" << endl;
		for (i = 0; i < m_numOfStn; i++){
			cout << pStation[i].getStnName() << endl;
			cout << " Student Passes added : ";		cin >> nStudent;
			cout << " Adult   Passes added : ";		cin >> nAdult;

			pStation[i].update(_STUDENT, nStudent);
			pStation[i].update(_ADULT, nAdult);
		}

	}
	void Stations::report() const
	{
		unsigned i;
		cout << "\nPasses in Stock : Student Adult" << endl;
		cout << "-------------------------------" << endl;
		//	     Spadina               100   200
		for (i = 0; i < m_numOfStn; i++){
			cout.setf(ios::left);
			cout.width(22);			
			cout << pStation[i].getStnName();

			cout.width(6);			
			cout << pStation[i].inStock(w2::_STUDENT);

			cout.width(6);			
			cout << pStation[i].inStock(w2::_ADULT) << endl;
		}
	}



}
