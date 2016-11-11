#include "TaxableProduct.h"

namespace w7
{
	TaxableProduct::TaxableProduct()
	{
		tt = 100;
	}


	TaxableProduct::~TaxableProduct()
	{
	}

	double TaxableProduct::getCharge() const
	{
		return 0;
	}
	void TaxableProduct::display(std::ostream&) const
	{

	}


	iProduct* readProduct(std::ifstream& fs)
	{
		TaxableProduct *item;


		return item;
	}


}
