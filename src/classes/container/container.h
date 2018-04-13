#pragma once

#include "classes/item/item.h"

class Container : public Item {
    public:
	Container(std::string name, std::string description, double rawCost, double retailPrice, int maxScoops)
	    : Item(name, description, rawCost, retailPrice), m_maxScoops{maxScoops} { }
	int getMaxScoops();

	// POLYMORPHISM
	// I am turning this program in partially working, so I
	// don't actually have the necessary methods to demonstrate
	// polymorphism. So, here's an override.
	std::string getType() override;

    private:
	int m_maxScoops;
};
