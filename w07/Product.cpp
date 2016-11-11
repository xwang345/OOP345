/////////////////////////////////////////////
// Workshop 7 - STL Containers
// Name: Sanghun Kim
// Date: 11/10/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////

#include "Product.h"
#include <stdlib.h>

namespace w7
{
	Product::Product() : pnumber(0), pcost(0.0)
	{
	}
	
	Product::~Product()
	{
	}

	Product::Product(const unsigned int pnum, const double cost)
	{
		pnumber = pnum;
		pcost = cost;
	}

	double Product::getCharge() const
	{		
		return pcost;
	}
	void Product::display(std::ostream& os) const 
	{
		os << std::fixed << std::right << std::setw(10) << pnumber << std::setprecision(2) << std::setw(10) << pcost << std::endl;
	}	

	//=======================================================//
	// Taxable class implementaton===========================//
	TaxableProduct::TaxableProduct() : Product()
	{
		taxrate[0] = 1.13;	 // for HTS
		taxrate[1] = 1.08;  // for PST
	}

	TaxableProduct::TaxableProduct(const unsigned int pnum, const double cost, const char* tax)
	{
		taxrate[0] = 1.13;	 // for HTS
		taxrate[1] = 1.08;  // for PST

		pnumber = pnum;
		pcost = cost;

		if (tax){
			if (tax[0] == 'H'){
				taxable = "HTS";
			}
			else if (tax[0] == 'P'){
				taxable = "PST";
			}
		}
	}

	TaxableProduct::~TaxableProduct()
	{
	}

	double TaxableProduct::getCharge() const
	{
		if (taxable == "HTS"){
			return pcost * taxrate[0];
		}
		else if (taxable == "PST"){
			return pcost * taxrate[1];
		}
		return pcost;
	}

	void TaxableProduct::display(std::ostream& os) const
	{
		os << std::fixed << std::right << std::setw(10) << pnumber << std::setprecision(2) << std::setw(10) << pcost << std::setw(8) << taxable << std::endl;
	}

	iProduct* readProduct(std::ifstream& fs)
	{
		std::string readbuff, token;
		std::string delimiter = " ";
		size_t pos;

		// get one line ===============//
		std::getline(fs, readbuff);
		unsigned int pnum = 0;
		float cost = 0;
		std::vector<std::string> readItem;

		while ((pos = readbuff.find(delimiter)) != std::string::npos) {
			token = readbuff.substr(0, pos);
			readbuff.erase(0, pos + delimiter.length());
			if (token.length()>0){
				readItem.push_back(token);
			}
		}
		if (readbuff.length() > 0){
			readItem.push_back(readbuff);
		}


		// return item =======================//
		if (readItem.size() == 2){
			Product* pItem = new Product(atoi(readItem.at(0).data()), atof(readItem.at(1).data()));
			return pItem;
		}
		else if (readItem.size() == 3){
			TaxableProduct* pItem = new TaxableProduct(atoi(readItem.at(0).data()), atof(readItem.at(1).data()), readItem.at(2).data());
			return pItem;
		}
		else if (readItem.size() == 0){  // end of file stream		
			return 0;
		}
		else{
			throw "Something is wrong in data file";
			return 0;
		}
	}
}