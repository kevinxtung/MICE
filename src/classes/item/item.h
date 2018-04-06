#pragma once

#include <string>
#include <gtkmm.h>

class Item {
    private:
	std::string m_name;
	std::string m_description;
	double m_rawCost;
	double m_retailPrice;
	int m_quantity;
	//Gtk::Image* m_image;
    public:
	Item(std::string name, std::string description, double rawCost, double retailPrice, int quantity);
	//~Item();

	// Getters
	std::string getName();
	std::string getDescription();
	double getRawCost();
	double getRetailPrice();
	int getQuantity();

	bool isInStock();
	
};
