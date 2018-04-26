#pragma once

#include "classes/item/item.h"

class Scoop : public Item {
    public:
	Scoop(std::string name, std::string description, double rawCost, double retailPrice)
	    : Item(name, description, rawCost, retailPrice) { }
	Scoop(std::string name, std::string description, double rawCost, double retailPrice, int quantity)
	    : Item(name, description, rawCost, retailPrice, quantity) { }
	
	std::string getType() const override;
};
