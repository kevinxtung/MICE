#include "main_window.h"

#include <iostream>

// Uninitialized State is -1
// Shows position end-user is at with screens.
int position = -1; // 1 is containers, 2 is scoops, 3 is toppings. 0 is main.

void Main_Window::orderScreen() {
    clean();

    // Custom Dialog Box
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    
    // Status Bar
    Gtk::Box *status = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    Gtk::Label *container = Gtk::manage(new Gtk::Label("Container"));
    Gtk::Label *scoops = Gtk::manage(new Gtk::Label("Scoops"));
    Gtk::Label *toppings = Gtk::manage(new Gtk::Label("Toppings"));

    // Back, Next, and Finish Buttons
    Gtk::Grid *gridButtons = Gtk::manage(new Gtk::Grid()); // Grid declared for buttons

    Gtk::Image *i_back = Gtk::manage(new Gtk::Image{"back.png"});
    Gtk::Button *b_back = Gtk::manage(new Gtk::Button());
    b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onOrderBackClick));
    b_back->set_image(*i_back);

    Gtk::Image *i_next = Gtk::manage(new Gtk::Image{"next.png"});
    Gtk::Button *b_next = Gtk::manage(new Gtk::Button());
    b_next->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onOrderNextClick));
    b_next->set_image(*i_next);

    Gtk::Image *i_finishOrder = Gtk::manage(new Gtk::Image{"finishorder.png"});
    Gtk::Button *b_finishOrder = Gtk::manage(new Gtk::Button());
    b_finishOrder->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onOrderNextClick));
    b_finishOrder->set_image(*i_finishOrder);

    // Switch that draws GUI based on current position in creating a serving.
    switch (position) {
        case 0: // User wants to exit.
            defaultScreen();
            break;
        case 1: // User is selecting containers.
            showContainers();
            container->set_markup("<span weight='bold'>Container</span>");
            i_back = Gtk::manage(new Gtk::Image{"returntostart.png"});
            b_back->set_image(*i_back);
            break;
        case 2: // User is selecting scoops.
            showScoops();
            scoops->set_markup("<span weight='bold'>Scoops</span>");
            break;
        case 3: // User is selecting toppings.
            showToppings();
            toppings->set_markup("<span weight='bold'>Toppings</span>");
            i_next = Gtk::manage(new Gtk::Image{"addtoorder.png"});
            b_next->set_image(*i_next);
            gridButtons->attach(*b_finishOrder, 2, 0, 1, 1);
            break;
    }
    
    // Status Packing, done after the switch to allow bolding.
    status->pack_start(*container, Gtk::PACK_SHRINK, 0);
    status->pack_start(*scoops, Gtk::PACK_SHRINK, 0);
    status->pack_start(*toppings, Gtk::PACK_SHRINK, 0);

    // Grid Packing, done after switch to allow image text changes.
    gridButtons->attach(*b_back, 0, 0, 1, 1);
    gridButtons->attach(*b_next, 1, 0, 1, 1);

    // Dialog Assembly
    vbox->pack_start(*status, Gtk::PACK_SHRINK, 0);
    vbox->pack_start(*selections, Gtk::PACK_SHRINK, 0);
    vbox->pack_start(*gridButtons, Gtk::PACK_SHRINK, 0);
    box->add(*vbox);
    mainbox->add(*box);
    mainbox->show_all();
}

void Main_Window::showContainers() {
    // Container Style and Size Selection
    selections = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));

    Gtk::Label *style = Gtk::manage(new Gtk::Label("Style"));
    Gtk::ButtonBox *styleButtons = Gtk::manage(new Gtk::ButtonBox());
    int x = 100000; // Containers start at 100000
    for (auto i : m_controller->getEmporium().getContainers()) {
        Gtk::Button *b_styleButton = Gtk::manage(new Gtk::Button(i.getName()));
        b_styleButton->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_Window::onOrderDynamicClick), x));
        styleButtons->pack_start(*b_styleButton, Gtk::PACK_SHRINK, 0);
        x++;
    } 
    /* STRETCH GOAL
    Gtk::Label *size = Gtk::manage(new Gtk::Label("Size"));
    Gtk::ButtonBox *sizeButtons = Gtk::manage(new Gtk::ButtonBox());
    */
    selections->pack_start(*style, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*styleButtons, Gtk::PACK_SHRINK, 0);
    /* STRETCH GOAL
    selections->pack_start(*size, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*sizeButtons, Gtk::PACK_SHRINK, 0);
    */
}

void Main_Window::showScoops() {
    // Container Style and Size Selection
    selections = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));

    Gtk::Label *style = Gtk::manage(new Gtk::Label("Style"));
    Gtk::ButtonBox *styleButtons = Gtk::manage(new Gtk::ButtonBox());
    int x = 200000; // Scoops start at 200000
    for (auto i : m_controller->getEmporium().getScoops()) {
        Gtk::Button *b_styleButton = Gtk::manage(new Gtk::Button(i.getName()));
        b_styleButton->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_Window::onOrderDynamicClick), x));
        styleButtons->pack_start(*b_styleButton, Gtk::PACK_SHRINK, 0);
    }
    /* STRETCH GOAL
    Gtk::Label *size = Gtk::manage(new Gtk::Label("Size"));
    Gtk::ButtonBox *sizeButtons = Gtk::manage(new Gtk::ButtonBox());
    */
    selections->pack_start(*style, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*styleButtons, Gtk::PACK_SHRINK, 0);
    /* STRETCH GOAL
    selections->pack_start(*size, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*sizeButtons, Gtk::PACK_SHRINK, 0);
    */
}

void Main_Window::showToppings() {
    // Container Style and Size Selection
    selections = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));

    Gtk::Label *topping = Gtk::manage(new Gtk::Label("Topping"));
    Gtk::ButtonBox *toppingButtons = Gtk::manage(new Gtk::ButtonBox());
    int x = 300000; // Toppings start at 300000
    for (auto i : m_controller->getEmporium().getToppings()) {
        Gtk::Button *b_toppingButton = Gtk::manage(new Gtk::Button(i.getName()));
        b_toppingButton->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_Window::onOrderDynamicClick), x));
        toppingButtons->pack_start(*b_toppingButton, Gtk::PACK_SHRINK, 0);
        x++;
    } 

    Gtk::Label *amount = Gtk::manage(new Gtk::Label("Amount"));
    Gtk::ButtonBox *amountButtons = Gtk::manage(new Gtk::ButtonBox());
    
    Gtk::Button *b_none = Gtk::manage(new Gtk::Button("None"));
    Gtk::Button *b_light = Gtk::manage(new Gtk::Button("Light"));
    Gtk::Button *b_normal = Gtk::manage(new Gtk::Button("Normal"));
    Gtk::Button *b_extra = Gtk::manage(new Gtk::Button("Extra"));
    Gtk::Button *b_drenched = Gtk::manage(new Gtk::Button("Drenched"));
    amountButtons->pack_start(*b_none, Gtk::PACK_SHRINK, 0);
    amountButtons->pack_start(*b_light, Gtk::PACK_SHRINK, 0);
    amountButtons->pack_start(*b_normal, Gtk::PACK_SHRINK, 0);
    amountButtons->pack_start(*b_extra, Gtk::PACK_SHRINK, 0);
    amountButtons->pack_start(*b_drenched, Gtk::PACK_SHRINK, 0);

    selections->pack_start(*topping, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*toppingButtons, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*amount, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*amountButtons, Gtk::PACK_SHRINK, 0);
}

void Main_Window::onOrderDynamicClick(int button) {
    std::cout << "callback id " << button << std::endl;
}

void Main_Window::onOrderBackClick() {
    position--;
    if (position <= 0) {
        defaultScreen();
    }
    else {
        orderScreen();
    }
}

void Main_Window::onOrderNextClick() {
    position++;
    if (position >= 4) {
        defaultScreen();
    }
    else {
        orderScreen();
    }
}