#pragma once

#include "classes/person/person.h"
#include <string>

class Owner : public Person {
    public:
        Owner(std::string name, std::string ID, std::string phone);
};