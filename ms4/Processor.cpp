#include "Processor.h"
#include <string>
#include "Item.h"
#include "Utilities.h"
#include "OrderManager.h"

Processor::Processor(const std::string& record, std::function<Task::Quality(int)> func) :
item_(nullptr), is_a_filler(true), Task(record)
{
	num_end_slots = Task::getSlots();  // ???
	inspector = func;
//	std::cout << "KSH-------Processor::Processor" << std::endl;
}


void Processor::load(Item& item)
{	
//	std::cout << "KSH-------Processor::load" << std::endl;
	item_ = &item;
	if (!getName().compare(item.getFiller())){
		is_a_filler = true;
	}	
	else{
		is_a_filler = false;
	}
}

bool Processor::empty() const
{
//	std::cout << "KSH-------Processor::empty" << std::endl;
	if (waiting.empty() && process.empty() && complete.empty()){
		return true;
	}
	return false;
	//return (waiting.empty() && process.empty() && complete.empty()) ? true : false;
}

void Processor::accept(CustomerOrder&& order)
{
//	std::cout << "KSH-------Processor::accept" << std::endl;
	waiting.push_back(std::move(order));
//	process.push_back(std::move(order));
}

void Processor::pass(int i)
{
	auto checkQuality = getNextTask(passed) && getNextTask(redirect) ? inspector(i) : passed;
//	getNextTask(checkQuality)->validate;

	if (!complete.empty()){
		CustomerOrder&& order = std::move(complete.front());
		Processor* nextP = (Processor*)getNextTask(checkQuality);
		nextP->accept(std::move(order));
		complete.pop_front();
	}

	//	process.push_back(std::move(complete.front()));
	//	complete.pop_front();	

	//	accept(std::move(complete.front()));


//	str = getNextTask(checkQuality)->getName();

	//if (checkQuality == passed)
	//	Utilities::getLogFile() << "Passed to ";
	//else
	//	Utilities::getLogFile() << "Redirect to ";
	//Utilities::getLogFile() << "[" << taskName << "]\n";
	//throw taskName;

	//if (complete.size() > 0){
	//	const CustomerOrder&& order = std::move(complete[0]);
	//	try{
	//		std::string tmp = order[i];
	//		str.push_back(taskName);
	//	}
	//	catch (std::string msg){
	//		throw "error";
	//	}
	//}

//	auto checkQuality = getNextTask(passed) && getNextTask(redirect) ? inspector(i) : passed;
//
//
////	std::cout << "KSH-------Processor::pass" << std::endl;
	//if (complete.size() > 0){
	//	const CustomerOrder&& order = std::move(complete[0]);
	//	for (unsigned int i = 0; i < order.noOrders(); i++){
	//		str.push_back(order[i]);
	//	}
	//}
//	




	//auto checkQuality = getNextTask(passed) && getNextTask(redirect) ? inspector(i) : passed;

	//try{
	//	const Task* pTask = getNextTask(passed);
	//	std::string taskName = getNextTask(passed)->getName();		
	//}
	//catch{

	//}



	//std::string taskName = getNextTask(checkQuality)->getName();

	//if (checkQuality == passed)
	//	Utilities::getLogFile() << "Passed to ";
	//else
	//	Utilities::getLogFile() << "Redirect to ";
	//Utilities::getLogFile() << "[" << taskName << "]\n";
	//throw taskName;
}

void Processor::advance()
{
	if (!process.empty() && num_end_slots) {
		num_end_slots--;
		is_a_filler ? process.back().fill(*item_) : process.back().remove(*item_);
	}

	if (!num_end_slots) {
		complete.push_back(std::move(process.front()));
		process.pop_front();
		process.empty() ? num_end_slots = getSlots() : 1;
	}

	if (!waiting.empty()) {
		process.push_back(std::move(waiting.front()));
		waiting.pop_front();
	}

//	std::cout << "KSH-------Processor::advance" << std::endl;
	//if (!process.empty()) {
	//	if (num_end_slots){
	//		num_end_slots--;
	//		if (is_a_filler){
	//			for (auto& n : process)
	//				n.fill(*item_);				
	//		}
	//		else{
	//			for (auto& n : process)
	//				n.remove(*item_);
	//		//	process.front().remove(*item_);				
	//		}
	//	}
	//	else{		
	//		complete.push_back(std::move(process.front()));
	//		process.pop_front();
	//		if (process.empty()){
	//			num_end_slots = getSlots();
	//		}
	//		else{
	//			num_end_slots = 1;
	//		}
	//	}
	//}	

	//////moves an order, if any, from the front of the waiting queue to the back of the process queue
	//if (!waiting.empty()) {
	//	process.push_back(std::move(waiting.front()));
	//	waiting.pop_front();
	//}
}

bool Processor::readyToShip() const
{
	//std::cout << "KSH-------Processor::readyToShip" << std::endl;
	//return true;
	if (!complete.empty() && !getNextTask(passed)){
		return true;
	}
	return false;

//	return !complete.empty() && !getNextTask(passed);
}
bool Processor::readyToPass() const
{
	//std::cout << "KSH-------Processor::readyToPass" << std::endl;
	//return true;
	if (!complete.empty() && getNextTask(passed)){
		return true;
	}
	return false;

//	return !complete.empty() && getNextTask(passed);
}
void Processor::ship(OrderManager& finished)
{
//	std::cout << "KSH-------Processor::ship" << std::endl;
	if (!complete.empty()) {
		finished.push_back(std::move(complete.front()));
		complete.pop_front();
	}
}
void Processor::display(std::ostream& os) const
{
//	std::cout << "KSH-------Processor::display" << std::endl;
	Task::display(os);

	if (item_){
		os << " Item to add :  ";
		item_->display(os);
	}
	else{
		os << " Item to add :" << "  ---" << std::endl;
	}
	

}