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

    switch (position) {
        case 0:
            defaultScreen();
            break;
        case 1:
            showContainers();
            container->set_markup("<span weight='bold'>Container</span>");
            break;
        case 2:
            showScoops();
            scoops->set_markup("<span weight='bold'>Scoops</span>");
            break;
        case 3:
            showToppings();
            toppings->set_markup("<span weight='bold'>Toppings</span>");
            break;
    }
    
    // Status Packing, done after the switch to allow bolding.
    status->pack_start(*container, Gtk::PACK_SHRINK, 0);
    status->pack_start(*scoops, Gtk::PACK_SHRINK, 0);
    status->pack_start(*toppings, Gtk::PACK_SHRINK, 0);

    // Back and Next Buttons
    Gtk::Image *i_back = Gtk::manage(new Gtk::Image{"back.png"});
    Gtk::Button *b_back = Gtk::manage(new Gtk::Button());
    b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onOrderBackClick));
    b_back->set_image(*i_back);

    Gtk::Image *i_next = Gtk::manage(new Gtk::Image{"next.png"});
    Gtk::Button *b_next = Gtk::manage(new Gtk::Button());
    b_next->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onOrderNextClick));
    b_next->set_image(*i_next);

    Gtk::Grid *gridButtons = Gtk::manage(new Gtk::Grid());
    gridButtons->attach(*b_back, 0, 0, 1, 1);
    gridButtons->attach(*b_next, 2, 0, 1, 1);

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
    int x = 0;
    for (auto i : m_controller->getEmporium().getContainers()) {
        Gtk::Button *b_styleButton = Gtk::manage(new Gtk::Button(i.getName()));
        //b_styleButton->signal_clicked().connect(sigc::mem_fun(*this, /*SOME KIND OF OBSERVER*/));
        styleButtons->pack_start(*b_styleButton, Gtk::PACK_SHRINK, 0);
    } 

    Gtk::Label *size = Gtk::manage(new Gtk::Label("Size"));
    Gtk::ButtonBox *sizeButtons = Gtk::manage(new Gtk::ButtonBox());
    
    selections->pack_start(*style, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*styleButtons, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*size, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*sizeButtons, Gtk::PACK_SHRINK, 0);
}
void Main_Window::showScoops() {
    // Container Style and Size Selection
    selections = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));

    Gtk::Label *style = Gtk::manage(new Gtk::Label("Style"));
    Gtk::ButtonBox *styleButtons = Gtk::manage(new Gtk::ButtonBox());
    int x = 0;
    for (auto i : m_controller->getEmporium().getScoops()) {
        Gtk::Button *b_styleButton = Gtk::manage(new Gtk::Button(i.getName()));
        //b_styleButton->signal_clicked().connect(sigc::mem_fun(*this, /*SOME KIND OF OBSERVER*/));
        styleButtons->pack_start(*b_styleButton, Gtk::PACK_SHRINK, 0);
    } 

    Gtk::Label *size = Gtk::manage(new Gtk::Label("Size"));
    Gtk::ButtonBox *sizeButtons = Gtk::manage(new Gtk::ButtonBox());
    
    selections->pack_start(*style, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*styleButtons, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*size, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*sizeButtons, Gtk::PACK_SHRINK, 0);
}
void Main_Window::showToppings() {
    // Container Style and Size Selection
    selections = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));

    Gtk::Label *style = Gtk::manage(new Gtk::Label("Style"));
    Gtk::ButtonBox *styleButtons = Gtk::manage(new Gtk::ButtonBox());
    int x = 0;
    for (auto i : m_controller->getEmporium().getToppings()) {
        Gtk::Button *b_styleButton = Gtk::manage(new Gtk::Button(i.getName()));
        //b_styleButton->signal_clicked().connect(sigc::mem_fun(*this, /*SOME KIND OF OBSERVER*/));
        styleButtons->pack_start(*b_styleButton, Gtk::PACK_SHRINK, 0);
    } 

    Gtk::Label *size = Gtk::manage(new Gtk::Label("Size"));
    Gtk::ButtonBox *sizeButtons = Gtk::manage(new Gtk::ButtonBox());
    
    selections->pack_start(*style, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*styleButtons, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*size, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*sizeButtons, Gtk::PACK_SHRINK, 0);
}
void Main_Window::registerObserver() {
    //std::cout << "callback id " << callbackID << std::endl;
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