#include "item.h"

Item::Item(std::string name, std::string description, double rawCost, double retailPrice)
    :	m_name{name}, m_description{description}, m_rawCost{rawCost}, m_retailPrice{retailPrice}, m_quantity{0}, m_image{NULL} { }//Gtk::manage(new Gtk::Image(name + ".png"))
Item::Item(std::string name, std::string description, double rawCost, double retailPrice, int quantity)
    :	m_name{name}, m_description{description}, m_rawCost{rawCost}, m_retailPrice{retailPrice}, m_quantity{quantity}, m_image{Gtk::manage(new Gtk::Image(name + ".png"))} { }//

std::string Item::getType() const {return "Item";}
std::string Item::getName() {return m_name;}
std::string Item::getDescription() {return m_description;}
double Item::getRawCost() {return m_rawCost;}
double Item::getRetailPrice() {return m_retailPrice;}
int Item::getQuantity() {return m_quantity;}
bool Item::isInStock() {return (m_quantity) ? 1 : 0;}
Gtk::Image* Item::getImage() {return m_image;}