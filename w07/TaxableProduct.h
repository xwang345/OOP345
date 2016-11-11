#ifndef _TAXPRODUCT_H_
#define _TAXPRODUCT_H_

#pragma once
#include "Product.h"

namespace w7 {
	class TaxableProduct : public Product
	{
		
	public:
		TaxableProduct();
		~TaxableProduct();
		int getValue() { return tt; }
		virtual double getCharge() const;
		virtual void display(std::ostream&) const;
	};
}

#endif

