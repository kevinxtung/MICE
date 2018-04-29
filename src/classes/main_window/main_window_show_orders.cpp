#include "main_window.h"

#include <sstream>
#include <string>

#include <iostream>

void Main_Window::showOrdersScreen() {
    clean();

    //***************//
    //*ORDER DISPLAY*//
    //***************//

    Gtk::Box* orderBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    std::vector<Order> orders = m_controller->getEmporium().getOrders();
    std::vector<Serving> servings;

    for (auto i : orders) {
        std::cout << i.getStatus() << std::endl;
        if (i.getStatus() == "UNFILLED") {
            servings = i.getServings();
            for (auto i : servings) {
                auto container = i.getContainer();
                std::vector<Scoop> scoops = i.getScoops();
                std::vector<Topping> toppings = i.getToppings();
                Gtk::Label* containerText = Gtk::manage(new Gtk::Label());
                std::stringstream text;
                text << container.getName() << container.getRetailPrice() << std::endl;
                containerText->set_text(text.str());
                for (auto i : scoops) {
                    text << i.getName() << " Scoop" << std::endl;
                    containerText->set_text(text.str());
                }
                for (auto i : toppings) {
                    text << i.getName() << " Topping" << std::endl;
                    containerText->set_text(text.str());
                    orderBox->pack_start(*containerText, Gtk::PACK_SHRINK, 0);
                }
            }
        }
    }

    //**********************************//
    //*RETURN TO EMPLOYEE SCREEN BUTTON*//
    //**********************************//

    Gtk::Image* i_back = Gtk::manage(new Gtk::Image{"backbutton.png"});
    Gtk::Button* b_back = Gtk::manage(new Gtk::Button());
    b_back->set_image(*i_back);
    b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::employeeScreen));

    //****************//
    //*MAIN BOX SETUP*//
    //****************//

    Gtk::Grid* grid = Gtk::manage(new Gtk::Grid());
    grid->attach(*orderBox, 0, 1, 1, 2);
    grid->attach(*b_back, 0, 0, 1, 1);
    box->add(*grid);
    mainbox->add(*box);
    mainbox->show_all();
}