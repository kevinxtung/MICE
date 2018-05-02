#include "person.h"

Person::Person(std::string name, std::string phone) : m_name{name}, m_phone{phone}, m_active{true} {
    for (int x = 0; x < phone.size(); x++) {
        if (phone[x] != '-') {
            m_ID += phone[x];
        }
    }
}

std::string Person::getName() {return m_name;}
std::string Person::getPhone() {return m_phone;}
std::string Person::getID() {return m_ID;}
bool Person::isActive() {return m_active;}