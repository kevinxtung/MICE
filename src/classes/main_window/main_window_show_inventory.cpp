#include "main_window.h"

void Main_Window::showInventoryScreen() {
    clean();

    // Back Button
    Gtk::Image* i_back = Gtk::manage(new Gtk::Image{"backbutton.png"});
    Gtk::Button* b_back = Gtk::manage(new Gtk::Button());
    b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::employeeScreen));
    b_back->set_image(*i_back);

    // Create a new Item
    Gtk::Image* i_createItem = Gtk::manage(new Gtk::Image{"createitem.png"});
    Gtk::Button* b_createItem = Gtk::manage(new Gtk::Button());
    b_createItem->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onCreateItemClick));
    b_createItem->set_image(*i_createItem);

    // Populate Emporium with Items
    Gtk::Image* i_66 = Gtk::manage(new Gtk::Image{"66.png"});
    Gtk::Button* b_66 = Gtk::manage(new Gtk::Button());
    b_66->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::generate));
    b_66->set_image(*i_66);

    // Permission Flags
    b_createItem->set_sensitive(true);
    b_66->set_sensitive(true);
    if (!m_isManager) {
        b_createItem->set_sensitive(false);
    }
    if (!m_isOwner) {
        b_66->set_sensitive(false);        
    }

    Gtk::Grid* grid = Gtk::manage(new Gtk::Grid());
    grid->attach(*b_back, 0, 0, 1, 1);
    grid->attach(*b_createItem, 1, 1, 1, 1);
    grid->attach(*b_66, 2, 1, 1, 1);

    box->add(*grid);
    mainbox->add(*box);
    mainbox->show_all();
}