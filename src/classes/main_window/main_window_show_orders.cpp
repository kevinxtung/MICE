#include "main_window.h"

#include <sstream>
#include <string>

void Main_Window::showOrdersScreen() {
    clean();

    //************//
    //*ORDER TEXT*//
    //************//

    Gtk::Grid* grid = Gtk::manage(new Gtk::Grid());
    Gtk::Box* allOrders = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));

    std::vector<Order> orders = m_controller->getEmporium().getOrders();
    std::vector<Serving> servings;
    std::string name;
    std::string statusFlag;
    if (m_isManager) {  // We want the manager to pay filled orders
        statusFlag = "FILLED";
    }
    else {              // We want the server to fill unfilled orders
        statusFlag = "UNFILLED";
    }
    int x = 2;
    int y = 2;

    for (auto it_order : orders) {
        Gtk::Box* orderBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
        if (it_order.getStatus() == statusFlag) {
            servings = it_order.getServings();
            name = it_order.getName();
            for (auto i : servings) {
                auto container = i.getContainer();
                std::vector<Scoop> scoops = i.getScoops();
                std::vector<Topping> toppings = i.getToppings();
                Gtk::Label* containerText = Gtk::manage(new Gtk::Label());
                std::stringstream text;
                text << "CONTAINER" << std::endl;
                text << "\t" << container.getName() << std::endl;
                //containerText->set_text(text.str());
                text << "SCOOPS" << std::endl;
                for (auto i : scoops) {
                    text << "\t" << i.getName() << std::endl;
                    //containerText->set_text(text.str());
                }
                text << "TOPPINGS" << std::endl;
                for (auto i : toppings) {
                    text << "\t" << i.getName() << ": " << i.getAmount() << std::endl;
                    //containerText->set_text(text.str());
                    //orderBox->pack_start(*containerText, Gtk::PACK_SHRINK, 0);
                }
                text << std::endl << std::endl;
                containerText->set_text(text.str());
                orderBox->pack_start(*containerText, Gtk::PACK_SHRINK, 0);
            }
            Gtk::Button* b_fillButton;
            if (m_isManager) {  // A manager will pay orders
                b_fillButton = Gtk::manage(new Gtk::Button("Mark as Paid"));
                b_fillButton->signal_clicked().connect(sigc::bind<unsigned int>(sigc::mem_fun(*this, &Main_Window::onOrderPayClick), it_order.getID()));
            }
            else {              // A server will fill orders
                b_fillButton = Gtk::manage(new Gtk::Button("Fill Order"));
                b_fillButton->signal_clicked().connect(sigc::bind<unsigned int>(sigc::mem_fun(*this, &Main_Window::onOrderFillClick), it_order.getID()));
            }
            orderBox->pack_start(*b_fillButton, Gtk::PACK_SHRINK, 0);
            std::string orderIDText = "ORDER ID: ";
            orderIDText += std::to_string(it_order.getID());
            Gtk::Label* l_orderID = Gtk::manage(new Gtk::Label(orderIDText));
            orderBox->pack_start(*l_orderID, Gtk::PACK_SHRINK, 0);
            grid->attach(*orderBox, x, y, 1, 1);
            if (x++-1 % 6 == 0) { // Create a grid arrangement, moving an order to the next row every 5 elemnts
                y++;
            }
            //allOrders->pack_start(*orderBox, Gtk::PACK_SHRINK, 0);
        }
    }

    //**********************************//
    //*RETURN TO EMPLOYEE SCREEN BUTTON*//
    //**********************************//

    Gtk::Image* i_back = Gtk::manage(new Gtk::Image{"backbutton.png"});
    Gtk::Button* b_back = Gtk::manage(new Gtk::Button());
    b_back->set_image(*i_back);
    b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::employeeScreen));

    //*****************************//
    //*REFRESH ORDER SCREEN BUTTON*//
    //*****************************//

    Gtk::Image* i_refresh = Gtk::manage(new Gtk::Image{"refreshbutton.png"});
    Gtk::Button* b_refresh = Gtk::manage(new Gtk::Button());
    b_refresh->set_image(*i_refresh);
    b_refresh->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::showOrdersScreen));

    //****************//
    //*MAIN BOX SETUP*//
    //****************//

    //grid->attach(*allOrders, 1, 1, 5, 1);
    grid->attach(*b_back, 0, 0, 1, 1);
    grid->attach(*b_refresh, 1, 0, 1, 1);
    box->add(*grid);
    mainbox->add(*box);
    mainbox->show_all();
}

void Main_Window::onOrderFillClick(unsigned int ID) {
    std::vector<Order>& orders = m_controller->getEmporium().getOrders();
    for (int x = 0; x < orders.size(); x++) {
        if (orders[x].getID() == ID) {
            orders[x].fill();
            showOrdersScreen();
            return;
        }
    }
}

void Main_Window::onOrderPayClick(unsigned int ID) {
    std::vector<Order>& orders = m_controller->getEmporium().getOrders();
    for (int x = 0; x < orders.size(); x++) {
        if (orders[x].getID() == ID) {
            orders[x].pay();
            showOrdersScreen();
            return;
        }
    }
}