#include "OrderManager.h"
#include "CustomerOrder.h"
#include <algorithm>

CustomerOrder&& OrderManager::extract()
{	
	return std::move(*this->end());
}

void OrderManager::validate(const ItemManager& itemMng, std::ostream& os)
{

}
void OrderManager::display(std::ostream& os) const
{
	std::vector<CustomerOrder>::const_iterator iter = this->cbegin();
	//	auto iter = this->cbegin();
	for (; iter != this->cend(); iter++){
		iter->display(os);
	}

}