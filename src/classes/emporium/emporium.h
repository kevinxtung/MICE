#pragma once

#include "classes/item/item.h"
#include "classes/container/container.h"
#include "classes/scoop/scoop.h"
#include "classes/topping/topping.h"
#include "classes/order/order.h"
//#include "classes/person/person.h"
#include <vector>
#include <string>

class Emporium {
    public:
		Emporium() : m_balance{0.0} { }
		void addItem(Item item);
		void addContainer(Container container);
		void addScoop(Scoop scoop);
		void addTopping(Topping topping);

		void addOrder(Order order);

		void setBalance(double balance);
		void addBalance(double balance);
		void subBalance(double balance);

		std::vector<Item> getItems();
		std::vector<Container> getContainers();
		std::vector<Scoop> getScoops();
		std::vector<Topping> getToppings();

		std::vector<Order> getOrders();
		
		double getBalance();


		// ADD loading and saving
    private:
		//std::vector<Item> m_items;
		std::vector<Container> m_containers;
		std::vector<Scoop> m_scoops;
		std::vector<Topping> m_toppings;
		std::vector<Order> m_orders;

		double m_balance;
		//std::vector<Person> m_people;
};
