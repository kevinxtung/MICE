#include "emporium.h"

void Emporium::addItem(Item item) {
    m_items.push_back(item);
}

void Emporium::addOrder(Order order) {
    m_orders.push_back(order);
}