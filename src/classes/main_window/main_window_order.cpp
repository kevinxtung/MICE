#include "main_window.h"

void Main_Window::orderScreen() {
    clean();
    
    // Custom Dialog Box
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    
    // Status Bar
    Gtk::Box *status = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    Gtk::Label *container = Gtk::manage(new Gtk::Label("Container"));
    Gtk::Label *scoops = Gtk::manage(new Gtk::Label("Scoops"));
    Gtk::Label *toppings = Gtk::manage(new Gtk::Label("Toppings"));
    status->pack_start(*container, Gtk::PACK_SHRINK, 0);
    status->pack_start(*scoops, Gtk::PACK_SHRINK, 0);
    status->pack_start(*toppings, Gtk::PACK_SHRINK, 0);

    // Style and Size Selection
    Gtk::Box *selections = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    Gtk::Label *style = Gtk::manage(new Gtk::Label("Style"));
    Gtk::ButtonBox *styleButtons = Gtk::manage(new Gtk::ButtonBox());
    Gtk::Label *size = Gtk::manage(new Gtk::Label("Size"));
    Gtk::ButtonBox *sizeButtons = Gtk::manage(new Gtk::ButtonBox());
    
    selections->pack_start(*style, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*styleButtons, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*size, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*sizeButtons, Gtk::PACK_SHRINK, 0);
    
    // Back and Next Buttons
    Gtk::Image *i_back = Gtk::manage(new Gtk::Image{"back.png"});
    Gtk::Button *b_back = Gtk::manage(new Gtk::Button());
    b_back->set_image(*i_back);

    Gtk::Image *i_next = Gtk::manage(new Gtk::Image{"next.png"});
    Gtk::Button *b_next = Gtk::manage(new Gtk::Button());
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