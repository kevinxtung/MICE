#pragma once

#include "classes/item/item.h"

class Scoop : public Item {
    public:
	Scoop(std::string name, std::string description, double rawCost, double retailPrice)
	    : Item(name, description, rawCost, retailPrice) { }
	
	std::string getType() const override;
};
