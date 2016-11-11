/////////////////////////////////////////////
// Workshop 7 - STL Containers
// Name: Sanghun Kim
// Date: 11/10/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////

#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#pragma once
#include "iProduct.h"
#include <string>

namespace w7 {
	class Product : public iProduct
	{
	protected:
		unsigned int pnumber;
		double pcost;		
		
	public:
		Product();
		Product(const unsigned int pnum, const double cost);
		~Product();
		double getCharge() const;
		void display(std::ostream& os) const;
	};


	// Taxiable Class==================//
	class TaxableProduct : public Product
	{
	private:
		std::string taxable;
		double taxrate[2];
	public:
		TaxableProduct();
		TaxableProduct(const unsigned int pnum, const double cost, const char* tax);
		~TaxableProduct();
		virtual double getCharge() const;
		virtual void display(std::ostream& os) const;
	};
}

#endif

