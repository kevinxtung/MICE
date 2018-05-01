#pragma once

#include "classes/person/person.h"
#include <string>

class Customer : public Person {
    public:
        Customer(std::string name, std::string phone);
};