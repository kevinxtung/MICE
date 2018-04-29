#pragma once

#include "classes/item/item.h"
#include "classes/container/container.h"
#include "classes/scoop/scoop.h"
#include "classes/topping/topping.h"
#include "classes/order/order.h"
#include "classes/person/person.h"
#include "classes/customer/customer.h"
#include "classes/server/server.h"
#include "classes/manager/manager.h"
#include "classes/owner/owner.h"
#include <vector>
#include <string>

class Emporium {
    public:
		Emporium() : m_balance{0.0}, m_topID{0} { }

		void addContainer(Container container);
		void addScoop(Scoop scoop);
		void addTopping(Topping topping);
		void addOrder(Order order);

		void addCustomer(Customer customer);
		void addServer(Server server);
		void addManager(Manager manager);
		void addOwner(Owner owner);

		void setBalance(double balance);
		void addBalance(double balance);
		void subBalance(double balance);

		void setID(unsigned int ID);

		std::vector<Container>& getContainers();
		std::vector<Scoop>& getScoops();
		std::vector<Topping>& getToppings();
		std::vector<Order>& getOrders();
		
		std::vector<Customer>& getCustomers();
		std::vector<Server>& getServers();
		std::vector<Manager>& getManagers();
		std::vector<Owner>& getOwners();

		double getBalance();
		unsigned int getNextID();
		unsigned int getCurrentID();
    private:
		std::vector<Container> m_containers;
		std::vector<Scoop> m_scoops;
		std::vector<Topping> m_toppings;
		std::vector<Order> m_orders;

		std::vector<Customer> m_customers;
		std::vector<Server> m_servers;
		std::vector<Manager> m_managers;
		std::vector<Owner> m_owners;

		double m_balance;
		unsigned int m_topID;
};
