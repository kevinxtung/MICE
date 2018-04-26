#include "main_window.h"
#include <vector>

#include <iostream>
void Main_Window::finalizeScreen() {
    clean();
    std::cout << "made bit to finalize" << std::endl;
    std::cout << "b" << std::endl;
    std::vector<Order> orders;
    std::cout << "b" << std::endl;
    orders = m_controller->getEmporium().getOrders();
    std::cout << "b" << std::endl;
    unsigned int top = orders[0].getTopID();
    std::cout << "top is " << top << std::endl;
    std::vector<Serving> servings;
    std::cout << "b" << std::endl;    // FIX
    servings = orders[top-1].getServings(); // orders[top-1] is accessed since orders start at 1.
    std::cout << "b" << std::endl;    
    
    
    for (auto i : servings) {
        auto container = i.getContainer();
        std::vector<Scoop> scoops = i.getScoops();
        std::vector<Topping> toppings = i.getToppings();
        
        std::cout << container.getName() << container.getRetailPrice() << std::endl;
        for (auto i : scoops) {
            std::cout << i.getName() << i.getRetailPrice() << std::endl;
        }
        for (auto i : toppings) {
            std::cout << i.getName() << i.getRetailPrice() << std::endl;
        }
    }
    defaultScreen();
}