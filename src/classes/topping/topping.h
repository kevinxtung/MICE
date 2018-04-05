#pragma once

#include <string>
#include "classes/item/item.h"

class Topping : public Item {
    public:
	Topping(std::string name, std::string description, double rawCost, double retailPrice, int quantity) : Item(name, description, rawCost, retailPrice, quantity) { }
	std::string getLoad();
    private:
	std::string load;
};
