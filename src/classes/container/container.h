#pragma once

#include <string>
#include "classes/item/item.h"

class Container : public Item {
    public:
	Container(std::string name, std::string description, double rawCost, double retailPrice, int quantity, int maxScoops) : Item(name, description, rawCost, retailPrice, quantity) {maxScoops = maxScoops;}
	int getMaxScoops();
    private:
	int maxScoops;
};
