#include "Sale.h"

namespace w7 {
	Sale::Sale()
	{
	}

	Sale::Sale(const char* filename)
	{
		std::ifstream fn;
		iProduct* item = readProduct(fn);
		int tt = item->getValue();
		vecProduct.push_back(item);
	}


	Sale::~Sale()
	{
	}


	void Sale::display(std::ostream& os) const
	{

	}
}
