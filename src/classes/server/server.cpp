#include "server.h"

Server::Server(std::string name, std::string ID, std::string phone, double salary)
    : Person(name, ID, phone), m_salary{salary} { }

void Server::gainOrder() {++m_ordersTaken;}
void Server::setSalary(double salary) {m_salary = salary;}

int Server::getOrders() {return m_ordersTaken};
double Server::getSalary() {return m_salary};