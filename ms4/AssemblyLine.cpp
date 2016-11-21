#include "AssemblyLine.h"
#include "Processor.h"
#include "ItemManager.h"
#include "Item.h"
#include <algorithm>

void AssemblyLine::push_back(Processor&& processor)
{
//	std::cout << "KSH-------AssemblyLine::push_back" << std::endl;
	vector::push_back(std::move(processor));
}

void AssemblyLine::validate(std::ostream& os)
{
//	std::cout << "KSH-------AssemblyLine::validate1" << std::endl;
	std::vector<Processor>::iterator i = this->begin();	
	bool valid = true;
	for (; i != this->end() && valid; i++){
		bool invalid = true;

		std::vector<Processor>::iterator j = this->begin();
		for (; j != this->cend() && invalid; j++){
			if (i->validate(*j)){
				invalid = false;
			}
		}
		valid = !invalid;
	}
	if (!valid){
		std::cerr << "*** Not all Tasks have been validated ***\n";
	}
}
void AssemblyLine::validate(ItemManager& itemManager, std::ostream& os)
{
//	std::cout << "KSH-------AssemblyLine::validate2" << std::endl;
	std::vector<Item>::const_iterator iter = itemManager.cbegin();
	for (; iter != itemManager.cend(); iter++){

		// lamda function ============================//
		auto lamda_vaildate1 = [&](const Task& task){
			return !task.getName().compare(iter->getRemover());
		};

		auto lamda_vaildate2 = [&](const Task& task){
			return !task.getName().compare(iter->getFiller());
		};

		if (std::find_if(this->cbegin(), this->cend(), lamda_vaildate1) == this->cend()) {
			os << iter->getRemover() << " is not available\n";
		}

		if (std::find_if(this->cbegin(), this->cend(), lamda_vaildate2) == this->cend()) {
			os << iter->getFiller() << " is not available\n";
		}
	}
}
void AssemblyLine::loadItem(ItemManager& itemManager)
{
	std::cout << "KSH-------AssemblyLine::loadItem" << std::endl;



}
// processing
void AssemblyLine::loadOrders(OrderManager& orderManager, const std::string& entryProcessor, std::ostream& os)
{
	std::cout << "KSH-------AssemblyLine::loadOrders" << std::endl;
	
	
}
bool AssemblyLine::process(OrderManager& finishing, unsigned int n)
{
	std::cout << "KSH-------AssemblyLine::process" << std::endl;
	return true;
}
// reporting
void AssemblyLine::display(std::ostream& os) const
{
//	std::cout << "KSH-------AssemblyLine::display" << std::endl;
	std::vector<Processor>::const_iterator iter = this->cbegin();
	for (; iter != this->cend(); iter++){
		iter->display(os);		
	}

}
