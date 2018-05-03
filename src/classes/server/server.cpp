#include "server.h"

Server::Server(std::string name, std::string phone, double salary)
    : Person(name, phone), m_salary{salary} { }
Server::Server(std::string name, std::string phone, double salary, int ordersTaken)
    : Person(name, phone), m_salary{salary}, m_ordersTaken{ordersTaken} { }

void Server::gainOrder() {++m_ordersTaken;}
void Server::setSalary(double salary) {m_salary = salary;}

int Server::getOrders() {return m_ordersTaken;}
double Server::getSalary() {return m_salary;}