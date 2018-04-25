#pragma once

#include "classes/scoop/scoop.h"
#include "classes/container/container.h"
#include "classes/topping/topping.h"
#include <vector>

class Serving {
    public:
		Serving();

	// Getters
	Container getContainer();
	std::vector<Scoop> getScoops();
	std::vector<Topping> getToppings();
	
	// Serving Manipulation
	void setContainer(Container container);
	void addScoop(Scoop scoop);
	void addTopping(Topping topping);
	
	void removeScoop();
	void removeTopping();
	// ADD REMOVE SCOOP/TOPPING FEATURES

    private:
		Container m_container;
		std::vector<Scoop> m_scoops;
		std::vector<Topping> m_toppings;
};
