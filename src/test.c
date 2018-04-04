#include <iostream>
#include "classes/container/container.h"

int main(int argc, char* argv[]) {
    Container cone("Cone", "A sweet, crunchy waffle cone.", 0.75, 1.00, 50);
    Container cup("Cup", "An 8oz plastic tub.", 0.05, 0.25, 0);

    if (cup.isInStock) {
	std::cerr << "ERROR: Cup should not be in stock!";
    }

    cout << cone.getName << ": " << cone.getDescription << endl;
    cout << "Profit: " << cone.getRetailPrice - cone.getRawCost << endl;
}
