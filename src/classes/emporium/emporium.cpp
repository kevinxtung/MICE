#include "emporium.h"

void Emporium::addScoop(Scoop scoop) {
    scoops.push_back(scoop);
}

void Emporium::addContainer(Container container) {
    containers.push_back(container);
}

void Emporium::addTopping(Topping topping) {
    toppings.push_back(topping);
}
