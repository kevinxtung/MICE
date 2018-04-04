#pragma once

#include <string>
#include "classes/item/item.h"

class Container : public Item {
    public:
	Container(std::string name, std::string description, double rawCost, double retailPrice, int quantity) : Item(name, description, rawCost, retailPrice, quantity) { }
    private:
	int maxScoops;
};
