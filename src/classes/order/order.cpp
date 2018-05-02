#include "order.h"

// Constructor
Order::Order() : m_status{"OPEN"}, m_name{"NONAME"} { }



// Getters
std::string Order::getName() {return m_name;}
std::vector<Serving> Order::getServings() {return m_servings;}
std::string Order::getStatus() {return m_status;}
unsigned int Order::getID() {return m_ID;}

double Order::getPrice() {
    double total = 0.0;
    for (auto i : m_servings) {
        auto container = i.getContainer();
        std::vector<Scoop> scoops = i.getScoops();
        std::vector<Topping> toppings = i.getToppings();
        total += container.getRetailPrice();
        for (auto i : scoops) {
            total += i.getRetailPrice();
        }
        for (auto i : toppings) {
            total += i.getRetailPrice();
        }
    }
    return total;
}

// Setters
void Order::setName(std::string name) {m_name = name;}
void Order::setID(unsigned int ID) {m_ID = ID;}
void Order::addServing(Serving serving) {m_servings.push_back(serving);}
void Order::removeServing() {m_servings.pop_back();}
void Order::recieve() {m_status = "UNFILLED";}
void Order::pay() {m_status = "PAID";}
void Order::fill() {m_status = "FILLED";}
void Order::close() {m_status = "CLOSED";}
void Order::cancel() {m_status = "CANCELLED";}