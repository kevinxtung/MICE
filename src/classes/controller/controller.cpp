#include "controller.h"
#include <string>
#include <iostream>

void Controller::cli() {
    int cmd = -1;
    while (cmd != 0) {
	cmd = view.select();
	execute(cmd);
    }
}

void Controller::execute(int cmd) {
    if (!cmd) {
	return;
    }
    std::string name, description;
    double rawCost, retailPrice;
    int quantity;		// REFRACTOR LATER
    std::cout << "Name?" << std::endl;
    std::cin >> name;
    std::cout << "Description? " << std::endl;
    std::cin >> description;
    std::cout << "Material cost? " << std::endl;
    std::cin >> rawCost;
    std::cout << "Retail price? " << std::endl;
    std::cin >> retailPrice;
    std::cout << "Stock? " << std::endl;
    std::cin >> quantity;
    switch (cmd) {
	case 0:	    // Exit
	    break;
	case 1:	    // Create flavor
	    emporium.addScoop(Scoop(name, description, rawCost, retailPrice, quantity));
	    break;
	case 2:	    // Create container	    
	    {
	    int maxScoops;
	    std::cout << "Max scoops? " << std::endl;
	    std::cin >> maxScoops;
	    emporium.addContainer(Container(name, description, rawCost, retailPrice, quantity, maxScoops));
	    break;
	    }
	case 3:	    // Create topping
	    {
	    std::string load;
	    std::cout << "Amount of topping? " << std::endl;
	    std::cin >> load;
	    emporium.addTopping(Topping(name, description, rawCost, retailPrice, quantity, load));
	    break;
	    }
	default:
	    view.error("ERROR: INVALID COMMAND.");
	    break;
    }

}
