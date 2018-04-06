#pragma once

#include "classes/item/item.h"
//#include "classes/order/order.h"
//#include "classes/person/person.h"

// temp
#include "classes/scoop/scoop.h"

#include <vector>

class Emporium {
    public:
	void addItem(Item item);
	void addScoop(Scoop scoop);
	// loading and saving
    private:
	std::vector<Item> m_items;
	std::vector<Scoop> m_scoop;
	//std::vector<Order> m_orders;
	//std::vector<Person> m_people;
};
