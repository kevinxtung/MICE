#include "person.h"
#include <iostream>
#include <cmath>

Person::Person(std::string name, std::string phone) : m_name{name}, m_phone{phone}, m_active{true} {
    std::string filteredNumber = "";
    for (int x = 0; x < phone.size(); x++) {
        if (phone[x] != '-') {
            filteredNumber += phone[x];
        }
    }
    m_ID = filteredNumber;
}

std::string Person::getName() {return m_name;}
std::string Person::getPhone() {return m_phone;}
std::string Person::getID() {return m_ID;}
bool Person::isActive() {return m_active;}