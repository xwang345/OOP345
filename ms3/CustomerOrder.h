#pragma once
// CustomerOrder Milestone - CustomerOrder Interface
// CustomerOrder.h
// Chris Szalwinski
// v1.0 - 9/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <string>
/////////////////////////////////////////////
// OOP345 milestone 2: 
// Name: Sanghun Kim
// Date: 11/13/2106
// email: ksanghun@myseneca.ca

#ifndef _MSC_VER
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

class Item;
class CustomerItem;

class CustomerOrder {
	std::string name;          // name of the customer
	std::string product;       // name of the product
	CustomerItem* order;       // address of the customer requests 
	unsigned int nOrders;      // number of requests
	static size_t field_width; // current maximum field width
public:
	CustomerOrder(const std::string& strRecord);
	CustomerOrder(const CustomerOrder& cus);
	CustomerOrder& operator=(const CustomerOrder&) = delete;		// copy operator is not permited.
	CustomerOrder(CustomerOrder&& cus) NOEXCEPT;
	CustomerOrder&& operator=(CustomerOrder&& cus)NOEXCEPT;
	~CustomerOrder();
	unsigned int noOrders() const;
	const std::string& operator[](unsigned int) const;
	void fill(Item& item);
	void remove(Item&);
	bool empty() const;
	void display(std::ostream&) const;
};

