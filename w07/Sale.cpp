/////////////////////////////////////////////
// Workshop 7 - STL Containers
// Name: Sanghun Kim
// Date: 11/10/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////

#include "Sale.h"

namespace w7 {
	Sale::Sale()
	{
	}

	Sale::Sale(const char* filename)
	{
		std::ifstream fn (filename);
		if (fn.is_open()) {
			while (fn) {
				try{
					iProduct* pProd= readProduct(fn);
					if (pProd){
						vecProduct.push_back(pProd);
					}
				}
				catch (const char* msg){
					std::cout << msg << std::endl;
				}
			}
		}		
	}


	Sale::~Sale()
	{
		std::vector<iProduct*>::iterator iter = vecProduct.begin();
		for (; iter != vecProduct.end(); iter++){
			delete[] *iter;
		}
		vecProduct.clear();
	}


	void Sale::display(std::ostream& os) const
	{
		os << "Product No" << "      Cost" << " Taxable" << std::endl;
	//	std::vector<iProduct*>::iterator iter = vecProduct.begin();  // because of const function!
		double totalcost = 0;
		for (size_t i = 0; i < vecProduct.size(); i++){
			vecProduct.at(i)->display(os);
			totalcost += vecProduct.at(i)->getCharge();
		}

		os << std::fixed << std::right << std::setw(10) << "Total" << std::setprecision(2) << std::setw(10) << totalcost << std::endl;
	}
}
