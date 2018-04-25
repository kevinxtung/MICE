#include "serving.h"

Serving::Serving() { }

// Getters
Container Serving::getContainer() {return m_container;}
std::vector<Scoop> Serving::getScoops() {return m_scoops;}
std::vector<Topping> Serving::getToppings() {return m_toppings;}

// Setters
void Serving::setContainer(Container container) {m_container = container;}
void Serving::addScoop(Scoop scoop) {m_scoops.push_back(scoop);}
void Serving::addTopping(Topping topping) {m_toppings.push_back(topping);}

void Serving::removeScoop() {m_scoops.pop_back();}
void Serving::removeTopping() {m_toppings.pop_back();}