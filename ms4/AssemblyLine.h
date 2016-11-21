#pragma once
// Assembly Line Milestone - Assembly Line Interface
// AssemblyLine.h
// Chris Szalwinski
// v1.0 - 30/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <vector>

class Processor;
class ItemManager;
class OrderManager;

class AssemblyLine : public std::vector<Processor> {
public:
	// initialize
	void push_back(Processor&& processor);
	void validate(std::ostream& os);
	void validate(ItemManager& itemManager, std::ostream& os);
	void loadItem(ItemManager& itemManager);
	// processing
	void loadOrders(OrderManager& orderManager, const std::string& entryProcessor, std::ostream& os);
	bool process(OrderManager& finishing, unsigned int n);
	// reporting
	void display(std::ostream& os) const;
};

