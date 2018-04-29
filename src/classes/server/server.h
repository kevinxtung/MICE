#pragma once

#include "classes/person/person.h"
#include <string>

class Server : public Person {
    public:
        Server(std::string name, std::string ID, std::string phone, double salary);
        // Setters
        void gainOrder();
        void setSalary(double salary);

        //Getters
        int getOrders();
        double getSalary();
        
    private:
        int m_ordersTaken;
        double m_salary;
};