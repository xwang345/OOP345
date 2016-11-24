#include "AssemblyLine.h"
#include "Processor.h"
#include "ItemManager.h"
#include "Item.h"
#include "OrderManager.h"
#include "Utilities.h"
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
		std::string strTask;
		auto lamda_vaildate = [&](const Task& task){
			return !task.getName().compare(strTask);
		};

		strTask = iter->getRemover();
		if (std::find_if(this->cbegin(), this->cend(), lamda_vaildate) == this->cend()) {
			os << strTask << " is not available\n";
		}

		strTask = iter->getFiller();
		if (std::find_if(this->cbegin(), this->cend(), lamda_vaildate) == this->cend()) {
			os << strTask << " is not available\n";
		}
	}
}
void AssemblyLine::loadItem(ItemManager& itemManager)
{
//	std::cout << "KSH-------AssemblyLine::loadItem" << std::endl;
	std::vector<Processor>::iterator iter_pro = this->begin();
	std::vector<Item>::iterator iter_itm = itemManager.begin();

	for (; iter_pro != this->end(); iter_pro++){
		for (; iter_itm != itemManager.end(); iter_itm++){
			if (iter_pro->getName() == iter_itm->getFiller() || iter_pro->getName() == iter_itm->getRemover()){
				iter_pro->load(*iter_itm);
			}
		}
	}

}
// processing
void AssemblyLine::loadOrders(OrderManager& orderManager, const std::string& entryProcessor, std::ostream& os)
{
//	std::cout << "KSH-------AssemblyLine::loadOrders" << std::endl;
	auto lamda_vaildate = [&](const Processor& p){
		return !p.getName().compare(entryProcessor);
	};	

	// Check entry processor and AssemblyLine's entryProcessor
	std::vector<Processor>::iterator iter = std::find_if(this->begin(), this->end(), lamda_vaildate);
	if (iter != this->end()){  // if entryProcrssor is exist in AssemblyLine, 
		while (!orderManager.empty()) {
			// moves the customer orders to assembly line's entryProcessor.  
			iter->accept(orderManager.extract());		
			orderManager.pop_back();
		}
	}	
}
bool AssemblyLine::process(OrderManager& finishing, unsigned int n)
{
//	std::cout << "KSH-------AssemblyLine::process" << std::endl;
	for (size_t i = 0; i < n; i++) {
		for (auto& p : *this) {
			if (!p.empty()) {
				p.advance();
				if (p.readyToPass()) {

					try {
				//	//	srand(time(NULL));
						p.pass(rand() % 100);
					}
					catch (const std::string& msg) {
						p.ship(finishing);
						loadOrders(finishing, msg, std::cerr);
					}
				}

				if (p.readyToShip()) {
					p.ship(finishing);
					Utilities::getLogFile() << "Task Completed\n";
					if (p.empty())
						return true;
				}
			}
		}
	}
	return false;
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
