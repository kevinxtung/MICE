#pragma once

#include "classes/item/item.h"

class Topping : public Item {
    public:
	Topping(std::string name, std::string description, double rawCost, double retailPrice, std::string amount)
	: Item(name, description, rawCost, retailPrice), m_amount{amount} { }

	// Getters
	std::string getType() const override;
	std::string getAmount();
    private:
	std::string m_amount;
};
