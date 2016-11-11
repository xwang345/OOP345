/////////////////////////////////////////////
// Workshop 7 - STL Containers
// Name: Sanghun Kim
// Date: 11/10/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////

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

