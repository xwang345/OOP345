#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_

// Workshop 7 - STL Containers
// iProduct.h

#include <iostream>
#include <fstream>

namespace w7 {

	class iProduct {
	public:
		virtual int getValue() = 0;
		virtual double getCharge() const = 0;
		virtual void display(std::ostream&) const = 0;
	};

	std::ostream& operator<<(std::ostream& os, const iProduct& prod);
	iProduct* readProduct(std::ifstream& fs);

}
#endif