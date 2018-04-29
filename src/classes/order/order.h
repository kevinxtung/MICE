#pragma once

#include "classes/serving/serving.h"
//#include "classes/server/server.h"
//#include "classes/customer/customer.h"
#include <vector>
#include <string>

class Order {
    public:
		Order();

		// Getters
		std::string getName();
		std::vector<Serving> getServings();
		std::string getStatus();
		unsigned int getID();

		// Setters
		void setName(std::string name);
		void setID(unsigned int ID);
		void addServing(Serving serving);
		void removeServing();
		void recieve();
		void pay();
		void fill();
		void close();
		void cancel();

    private:
		std::string m_name;
		std::vector<Serving> m_servings;
		std::string m_status;
		unsigned int m_ID;
	

};
