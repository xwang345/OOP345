#ifndef _SALE_H_
#define _SALE_H_


#pragma once
#include <vector>
#include "iProduct.h"
#include <iostream>
#include <fstream>

namespace w7 {
	class Sale
	{
		std::vector<iProduct*> vecProduct;
	public:
		Sale();
		Sale(const char* filename);

		~Sale();

		void display(std::ostream& os) const;
	};
}

#endif

