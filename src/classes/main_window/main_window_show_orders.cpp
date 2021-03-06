#include "main_window.h"
#include <sstream>

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
                text << "SCOOPS" << std::endl;
                for (auto i : scoops) {
                    text << "\t" << i.getName() << std::endl;
                }
                text << "TOPPINGS" << std::endl;
                for (auto i : toppings) {
                    text << "\t" << i.getName() << ": " << i.getAmount() << std::endl;
                }
                text << std::endl << std::endl;
                containerText->set_text(text.str());
                orderBox->pack_start(*containerText, Gtk::PACK_SHRINK, 0);
            }

            //*****************************//
            //*BUTTONS FOR FILL/PAY/CANCEL*//
            //*****************************//

            Gtk::Button* b_fillButton;
            Gtk::Button* b_payButton;
            Gtk::Button* b_cancelButton;
            if (m_isManager) {  // A manager will pay orders
                b_payButton = Gtk::manage(new Gtk::Button("Mark as Paid"));
                b_payButton->signal_clicked().connect(sigc::bind<unsigned int>(sigc::mem_fun(*this, &Main_Window::onOrderPayClick), it_order.getID()));
                b_cancelButton = Gtk::manage(new Gtk::Button("Cancel Order"));
                b_cancelButton->signal_clicked().connect(sigc::bind<unsigned int>(sigc::mem_fun(*this, &Main_Window::onOrderCancelClick), it_order.getID()));
                orderBox->pack_start(*b_payButton, Gtk::PACK_SHRINK, 0);
                orderBox->pack_start(*b_cancelButton, Gtk::PACK_SHRINK, 0);
            }
            else {              // A server will fill orders
                b_fillButton = Gtk::manage(new Gtk::Button("Fill Order"));
                b_fillButton->signal_clicked().connect(sigc::bind<unsigned int>(sigc::mem_fun(*this, &Main_Window::onOrderFillClick), it_order.getID()));
                orderBox->pack_start(*b_fillButton, Gtk::PACK_SHRINK, 0);
            }
            std::string orderIDText = "ORDER ID: ";
            orderIDText += std::to_string(it_order.getID());
            Gtk::Label* l_orderID = Gtk::manage(new Gtk::Label(orderIDText));
            orderBox->pack_start(*l_orderID, Gtk::PACK_SHRINK, 0);
            Gtk::Label* l_orderPrice;
            Gtk::Label* l_orderName;
            if (statusFlag == "FILLED") {
                std::string orderPriceText = "PRICE: $";
                orderPriceText += priceFix(std::to_string(it_order.getPrice()));
                l_orderPrice = Gtk::manage(new Gtk::Label(orderPriceText));
                orderBox->pack_start(*l_orderPrice, Gtk::PACK_SHRINK, 0);
                std::string orderNameText = "NAME: ";
                orderNameText += it_order.getName();
                l_orderName = Gtk::manage(new Gtk::Label(orderNameText));
                orderBox->pack_start(*l_orderName, Gtk::PACK_SHRINK, 0);
            };
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


    //****************************//
    //*PAY/ORDER/CANCEL CALLBACKS*//
    //****************************//

// Looks to fill the order with corresponding ID
void Main_Window::onOrderFillClick(unsigned int ID) {
    std::vector<Order>& orders = m_controller->getEmporium().getOrders();
    for (int x = 0; x < orders.size(); x++) {
        if (orders[x].getID() == ID) {
            orders[x].fill();

            // Once filled, credit the employee who filled it.
            std::vector<Server>& servers = m_controller->getEmporium().getServers();
            for (int x = 0; x < servers.size(); x++) {
                if (servers[x].getID() == activeEmployee) {
                    servers[x].gainOrder();
                    if (servers[x].getOrders() % 4 == 0) {
                        m_controller->getEmporium().subBalance(servers[x].getSalary());
                    }
                    showOrdersScreen();
                    return;
                }
            }
        }
    }
}

// Looks to pay the order with corresponding ID
void Main_Window::onOrderPayClick(unsigned int ID) {
    std::vector<Order>& orders = m_controller->getEmporium().getOrders();
    for (int x = 0; x < orders.size(); x++) {
        if (orders[x].getID() == ID) {
            orders[x].pay();
            // Once paid, add the amount to the balance of the emporium.
            m_controller->getEmporium().addBalance(orders[x].getPrice());
            showOrdersScreen();
            return;
        }
    }
}

// Looks to cancel the order with corresponding ID
void Main_Window::onOrderCancelClick(unsigned int ID) {
    std::vector<Order>& orders = m_controller->getEmporium().getOrders();
    for (int x = 0; x < orders.size(); x++) {
        if (orders[x].getID() == ID) {
            orders[x].cancel();
            showOrdersScreen();
            return;
        }
    }
}