#pragma once

#include <string>
#include <gtkmm.h>

class Item {
    private:
	std::string name;
	std::string description;
	double rawCost;
	double retailPrice;
	int quantity;
	//Gtk::Image* image; add this to the constructor as well
    public:
	Item(string name, string description, double rawCost, double retailPrice, int quantity);
	//~Item();

	// Getters
	std::string getName();
	std::string getDescription();
	double getRawCost();
	double getRetailPrice();
	int getQuantity();

	bool isInStock();
	
};
