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
        text << container.getName() << ": " << container.getRetailPrice() << std::endl;
        containerText->set_text(text.str());
        confirmationBox->pack_start(*containerText, Gtk::PACK_SHRINK, 0);
        for (auto i : scoops) {
            text << i.getName() << " Scoop: " << i.getRetailPrice() << std::endl;
            containerText->set_text(text.str());
            confirmationBox->pack_start(*containerText, Gtk::PACK_SHRINK, 0);
        }
        for (auto i : toppings) {
            text << i.getName() << " Topping: " << i.getRetailPrice() << std::endl;
            containerText->set_text(text.str());
            confirmationBox->pack_start(*containerText, Gtk::PACK_SHRINK, 0);
        }
    }

    //*********************//
    //*FINISH & PAY BUTTON*//
    //*********************//

    Gtk::Button* b_finishPay = Gtk::manage(new Gtk::Button("Finish and Pay"));
    b_finishPay->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onFinishPayClick));

    Gtk::Grid* grid = Gtk::manage(new Gtk::Grid());
    grid->attach(*confirmationBox, 0, 0, 1, 2);
    grid->attach(*b_finishPay, 1, 1, 1, 1);
    box->add(*grid);
    mainbox->add(*box);
    mainbox->show_all();

}

void Main_Window::onFinishPayClick() {
    std::vector<Order>& orders = m_controller->getEmporium().getOrders();
    orders[top-1].recieve();
    defaultScreen();
}


    // DELETE
    /*
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
    }*/