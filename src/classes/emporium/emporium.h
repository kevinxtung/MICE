#pragma once

#include "classes/container/container.h"
#include "classes/topping/topping.h"
#include "classes/scoop/scoop.h"

#include <vector>

class Emporium {
    public:
	void addScoop(Scoop scoop);
	void addContainer(Container container);
	void addTopping(Topping topping);
    private:
	std::vector<Scoop> scoops;
	std::vector<Container> containers;
	std::vector<Topping> toppings;
};
