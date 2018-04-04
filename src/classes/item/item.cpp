#include <string.h>
#include "item.h"

Item::Item(string name, string description, double rawCost, double retailPrice, int quantity)
    :	name{name}, description{description}, rawCost{rawCost},
	retailPrice{retailPrice}, quantity{quantity} {
}

std::string Item::getName() {return name;}
std::string Item::getDescription() {return description;}
double Item::getRawCost() {return rawCost;}
double Item::getRetailPrice() {return retailPrice;}
int Item::getQuantity() {return quantity;}

bool Item::isInStock() {
    return (quantity) ? 1 : 0;
}
