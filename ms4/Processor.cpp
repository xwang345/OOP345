#include "Processor.h"
#include <string>
#include "Item.h"


Processor::Processor()
{

}

Processor::Processor(const std::string& record, std::function<Task::Quality(int)> func) :
item_(nullptr), is_a_filler(true), Task(record)
{
	num_end_slots = Task::getSlots();  // ???
	inspector = func;
//	std::cout << "KSH-------Processor::Processor" << std::endl;
}


void Processor::load(Item& item)
{	
	std::cout << "KSH-------Processor::load" << std::endl;
	item_ = &item;
	if (!Task::getName().compare(item.getFiller())){
		is_a_filler = true;
	}	
}

bool Processor::empty() const
{
	std::cout << "KSH-------Processor::empty" << std::endl;
	if (waiting.empty() && process.empty() && complete.empty()){
		return true;
	}
	return false;
}

void Processor::accept(CustomerOrder&& order)
{
	std::cout << "KSH-------Processor::accept" << std::endl;
	waiting.push_back(std::move(order));
}

void Processor::pass(int i)
{
	std::cout << "KSH-------Processor::pass" << std::endl;
}

void Processor::advance()
{
	std::cout << "KSH-------Processor::advance" << std::endl;
}

bool Processor::readyToShip() const
{
	std::cout << "KSH-------Processor::readyToShip" << std::endl;
	return true;
}
bool Processor::readyToPass() const
{
	std::cout << "KSH-------Processor::readyToPass" << std::endl;
	return true;
}
void Processor::ship(OrderManager& finished)
{
	std::cout << "KSH-------Processor::ship" << std::endl;
}
void Processor::display(std::ostream& os) const
{
//	std::cout << "KSH-------Processor::display" << std::endl;
	Task::display(os);

	if (item_){
		os << " Item to add :" << item_->getName() << std::endl;
	}
	else{
		os << " Item to add :" << "  ---" << std::endl;
	}
	

}