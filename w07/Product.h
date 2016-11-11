#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#pragma once
#include "iProduct.h"

namespace w7 {
	class Product : public iProduct
	{
	protected:
		int tt;
	public:
		Product();
		~Product();

		int getValue() { return tt; }
		double getCharge() const;
		void display(std::ostream& os) const;
	};
}

#endif

