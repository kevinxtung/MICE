#pragma once

#include "classes/person/person.h"
#include <string>

class Manager : public Person {
    public:
        Manager(std::string name, std::string ID, std::string phone);
};