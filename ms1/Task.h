/////////////////////////////////////////////
// OOP345 milestone 1: 
// Name: Sanghun Kim
// Date: 11/13/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////

#pragma once
#include <iostream>
#include <string>
class Utilities;
class Task {
	std::string name;          // name of the task
	std::string slots;         // number of slots
	std::string nextTask[2];   // names of the next tasks
	const Task* pNextTask[2];  // addresses of the next tasks
	static size_t field_width; // current maximum field width 
public:
	enum Quality {
		passed,
		redirect
	};
	Task(const std::string& strRecord);
	bool validate(const Task& task);
	const std::string& getName() const;
	unsigned int getSlots() const;
	const Task* getNextTask(Quality) const;
	void display(std::ostream& os) const;
	static size_t getFieldWidth();


};

bool operator==(const Task& t1, const Task& t2);
