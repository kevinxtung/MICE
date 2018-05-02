#include "person.h"
#include <iostream>

Person::Person(std::string name, std::string phone) : m_name{name}, m_phone{phone}, m_active{true} {
    std::cout << "HERE" << std::endl;
    for (int x = 0; x < phone.size(); x++) {
        if (phone[x] != '-') {
            m_ID += phone[x];
            std::cout << "CAT A " << phone[x] << std::endl;
        }
    }
    std::cout << "DONE WITH " << m_ID << std::endl;
}

std::string Person::getName() {return m_name;}
std::string Person::getPhone() {return m_phone;}
std::string Person::getID() {return m_ID;}
bool Person::isActive() {return m_active;}