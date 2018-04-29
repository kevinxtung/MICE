#include "emporium.h"

void Emporium::addContainer(Container container) {m_containers.push_back(container);}
void Emporium::addScoop(Scoop scoop) {m_scoops.push_back(scoop);}
void Emporium::addTopping(Topping topping) {m_toppings.push_back(topping);}

void Emporium::addOrder(Order order) {m_orders.push_back(order);}

void Emporium::setBalance(double balance) {m_balance = balance;}
void Emporium::addBalance(double balance) {m_balance += balance;}
void Emporium::subBalance(double balance) {m_balance -= balance;}

void Emporium::setID(unsigned int ID) {m_topID = ID;}

std::vector<Container>& Emporium::getContainers() {return m_containers;}
std::vector<Scoop>& Emporium::getScoops() {return m_scoops;}
std::vector<Topping>& Emporium::getToppings() {return m_toppings;}

std::vector<Order>& Emporium::getOrders() {return m_orders;}

double Emporium::getBalance() {return m_balance;}
unsigned int Emporium::getNextID() {return ++m_topID;}
unsigned int Emporium::getCurrentID() {return m_topID;}