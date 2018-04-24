#include "person.h"

Person::Person(std::string name, std::string ID, std::string phone) : m_name{name}, m_ID{ID}, m_phone{phone}, m_active{true} { }

std::string Person::getName() {return m_name;}
std::string Person::getPhone() {return m_phone;}
std::string Person::getID() {return m_ID;}
bool Person::isActive() {return m_active;}