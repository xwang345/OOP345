#include "Task.h"
#include "Utilities.h"

Task::Task(const std::string& strRecord)
{
	slots = "1";
	pNextTask[0] = pNextTask[1] = nullptr;
}

Task::~Task()
{
}

const std::string& Task::getName() const
{
	return name;
}

unsigned int Task::getSlots() const
{
	return (unsigned int)atoi(slots.data());
}

const Task* Task::getNextTask(Quality quantity) const
{
	return pNextTask[quantity];
}

bool Task::validate(const Task& task)
{
	bool valid = true;
	for (unsigned int i = passed; i <= redirect; i++){
		if (nextTask[static_cast<Quality>(i)] == task.getName()){
			pNextTask[i] = task.getNextTask(static_cast<Quality>(i));
			valid = false;
		}
	}
	return valid;
}

void Task::display(std::ostream&) const
{

}