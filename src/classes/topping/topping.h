#pragma once

#include <string>
#include "classes/item/item.h"

class Topping : public Item {
    public:
	Topping(std::string name, std::string description, double rawCost, double retailPrice, int quantity, std::string load) : Item(name, description, rawCost, retailPrice, quantity) {load = load;}
	std::string getLoad();
    private:
	std::string load;
};
