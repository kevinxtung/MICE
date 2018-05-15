#include "main_window.h"
#include <vector>
#include <string>
#include <sstream>

unsigned int top;

void Main_Window::finalizeScreen() {
    clean();

    Gtk::Box* confirmationBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    std::vector<Order>& orders = m_controller->getEmporium().getOrders();
    top = m_controller->getEmporium().getCurrentID();
    std::vector<Serving> servings = orders[top-1].getServings(); // orders[top-1] is accessed since orders start at 1.

    for (auto i : servings) {
        auto container = i.getContainer();
        std::vector<Scoop> scoops = i.getScoops();
        std::vector<Topping> toppings = i.getToppings();
        Gtk::Label* containerText = Gtk::manage(new Gtk::Label());
        std::stringstream text;

        

        text << container.getName() << ": $" << priceFix(std::to_string(container.getRetailPrice())) << std::endl;
        containerText->set_text(text.str());
        confirmationBox->pack_start(*containerText, Gtk::PACK_SHRINK, 0);
        for (auto i : scoops) {
            text << i.getName() << " Scoop: $" << priceFix(std::to_string(i.getRetailPrice())) << std::endl;
            containerText->set_text(text.str());
            confirmationBox->pack_start(*containerText, Gtk::PACK_SHRINK, 0);
        }
        for (auto i : toppings) {
            text << i.getName() << " Topping: $" << priceFix(std::to_string(i.getRetailPrice())) << std::endl;
            containerText->set_text(text.str());
            confirmationBox->pack_start(*containerText, Gtk::PACK_SHRINK, 0);
        }
    }
    //************//
    //*NAME ENTRY*//
    //************//
    
    entry = Gtk::manage(new Gtk::Entry());
    keyboardSetup("TEXT");

    //*********************//
    //*FINISH & PAY BUTTON*//
    //*********************//

    Gtk::Label* l_finishPay = Gtk::manage(new Gtk::Label());
    l_finishPay->set_markup("<span font='20'>Please Enter First &amp; Last Name</span>");

    Gtk::Image* i_finishPay = Gtk::manage(new Gtk::Image("submitorder.png"));
    Gtk::Button* b_finishPay = Gtk::manage(new Gtk::Button());
    b_finishPay->set_image(*i_finishPay);
    b_finishPay->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onFinishPayClick));

    //*********************//
    //*NEW CUSTOMER BUTTON*//
    //*********************//

    Gtk::Label* l_newCustomer = Gtk::manage(new Gtk::Label());
    l_newCustomer->set_markup("<span font='20'>Not Registered with MICE?</span>");

    Gtk::Image* i_newCustomer = Gtk::manage(new Gtk::Image("createaccount.png"));
    Gtk::Button* b_newCustomer = Gtk::manage(new Gtk::Button());
    b_newCustomer->set_image(*i_newCustomer);
    b_newCustomer->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onNewCustomerClick));
    
    //*****************//
    //*WIDGET ASSEMBLY*//
    //*****************//

    Gtk::Box *vboxInterior = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    
    vboxInterior->pack_start(*l_finishPay, Gtk::PACK_SHRINK, 0);
    vboxInterior->pack_start(*entry, Gtk::PACK_SHRINK, 0);
    vboxInterior->pack_start(*b_finishPay, Gtk::PACK_SHRINK, 0);
    vboxInterior->pack_end(*b_newCustomer, Gtk::PACK_SHRINK, 0);
    vboxInterior->pack_end(*l_newCustomer, Gtk::PACK_SHRINK, 0);

    Gtk::Grid *grid = Gtk::manage(new Gtk::Grid());
    Gtk::Box *blank = Gtk::manage(new Gtk::Box());
    Gtk::Box *blank2 = Gtk::manage(new Gtk::Box());
    grid->attach(*blank, 0, 0, 1, 1);
    grid->attach(*blank2, 15, 8, 1, 1);
    
    grid->attach(*vboxInterior, 1, 1, 6, 5);
    grid->attach(*confirmationBox, 9, 1, 6, 5);
    grid->attach(*keyboard, 3, 12, 10, 3);

    grid->set_row_homogeneous(true);
    grid->set_column_homogeneous(true);

    box->add(*grid);
    mainbox->add(*box);
    mainbox->show_all();

}

void Main_Window::onFinishPayClick() {
    permission = 5;
    getEntryName(); // Get the name in the box and put it into g_name.
    
    // Don't bother checking if the name wasn't valid.
    if (entry->get_text() == "***INVALID NAME FORMAT***") {
        return;
    }
    // Now check to see if there is a corresponding customer.
    std::vector<Customer>& customers = m_controller->getEmporium().getCustomers();
    for (int x = 0; x < customers.size(); x++) {
        if (customers[x].getName() == g_name) {
            std::vector<Order>& orders = m_controller->getEmporium().getOrders();
            orders[top-1].recieve();
            orders[top-1].setName(g_name);
            finishedOrder();
            return;
        }
    }
    // If we get here, then no customer had a matching name.
    entry->set_text("***THAT NAME DOES NOT MATCH OUR RECORDS***");
}