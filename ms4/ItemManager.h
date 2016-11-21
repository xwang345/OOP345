/////////////////////////////////////////////
// OOP345 milestone 3: 
// Name: Sanghun Kim
// Date: 20/11/2106
// email: ksanghun@myseneca.ca
/////////////////////////////////////////////

#pragma once
#include <iostream>
#include <vector>

class Item;
class ItemManager : public std::vector<Item>
{
public:
	void display(std::ostream& os, bool isFull= false) const;
};

