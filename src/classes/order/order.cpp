#include "order.h"

// Initialization
unsigned int Order::m_topID = 0;

// Constructor
Order::Order() : m_ID{++m_topID}, m_status{"Open"} { }



// Getters
std::vector<Serving> Order::getServings() {return m_servings;}
std::string Order::getStatus() {return m_status;}
unsigned int Order::getID() {return m_ID;}
unsigned int Order::getTopID() {return m_topID;}
unsigned int Order::getNextID() {return ++m_topID;}

// Setters
void Order::addServing(Serving serving) {m_servings.push_back(serving);}
void Order::removeServing() {m_servings.pop_back();}
void Order::pay() {m_status = "PAID";}
void Order::cancel() {m_status = "CANCELLED";}

