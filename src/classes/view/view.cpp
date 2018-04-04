#include "view.h"
#include <string>
#include <iostream>

int View::select() {
    std::string menu = R"(
=======================
MICE Managerial Options
=======================

Create an Item
--------------
(1) Create an ice cream flavor
(2) Create a container
(3) Create a topping

)";
    int choice;
    std::cin >> choice;
    try {
	return choice;
    }
    catch (const std::invalid_argument& e) {
	return 0;
    }
}

void View::error(std::string message) {
    std::cout << message;
}
