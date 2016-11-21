/////////////////////////////////////////////
// OOP345 milestone 3: 
// Name: Sanghun Kim
// Date: 20/11/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////

#pragma once
// Manager Milestone - TaskManager Interface
// TaskManager.h
// Chris Szalwinski
// v1.0 - 14/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <vector>

class Task;
class ItemManager;

class TaskManager : public std::vector<Task> {
public:
	void validate(std::ostream& os);
	void validate(const ItemManager& itemMng, std::ostream& os);
	void display(std::ostream& os) const;
};
