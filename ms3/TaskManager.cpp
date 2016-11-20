#include <algorithm>
#include "TaskManager.h"
#include "Task.h"
#include "ItemManager.h"
#include "Item.h"


void TaskManager::validate(std::ostream& os)
{
	size_t num = this->size();  // inheritated from vector //	
	bool valid = true;
	for (auto i = 0u; i < num && valid; i++) {
		bool invalid = true;
		for (auto j = 0u; j < num && invalid; j++) {
			if (this->at(i).validate(this->at(j))){
				invalid = false;
			}
		}
		valid = !invalid;
	}
	if (!valid){
		std::cerr << "*** Not all Tasks have been validated ***\n";
	}

}
void TaskManager::validate(const ItemManager& itemMng, std::ostream& os)
{
	std::vector<Item>::const_iterator iter = itemMng.cbegin();
	for (; iter != itemMng.cend(); iter++){

		// lamda function ============================//
		auto lamda_vaildate = [&](const Task& task){
			if(task.getName().compare(iter->getRemover()) || task.getName().compare(iter->getFiller())){
				return true;
			}
			return false;
		};

		if (std::find_if(this->cbegin(), this->cend(), lamda_vaildate) == this->cend()) {
			os << iter->getRemover() << " is not available\n";
		}
	}
}
void TaskManager::display(std::ostream& os) const
{
	std::vector<Task>::const_iterator iter = this->cbegin();
//	auto iter = this->cbegin();
	for (; iter != this->cend(); iter++){
		iter->display(os);
	}
}
