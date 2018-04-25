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
		std::vector<Serving> getServings();
		std::string getStatus();
		unsigned int getID();
		unsigned int getTopID();
		unsigned int getNextID();

		// Setters
		void addServing(Serving serving);
		void removeServing();
		void pay();
		void cancel();

    private:
		std::vector<Serving> m_servings;
		std::string m_status;
		unsigned int m_ID;
		static unsigned int m_topID;
	

};
