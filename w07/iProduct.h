/////////////////////////////////////////////
// Workshop 7 - STL Containers
// Name: Sanghun Kim
// Date: 11/10/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////

#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_

// iProduct.h

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

namespace w7 {

	class iProduct {
	public:
		virtual double getCharge() const = 0;
		virtual void display(std::ostream&) const = 0;
	};

	std::ostream& operator<<(std::ostream& os, const iProduct& prod);
	iProduct* readProduct(std::ifstream& fs);

}
#endif