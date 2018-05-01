#include "main_window.h"

void Main_Window::showRecordsScreen() {
    clean();

    // Back Button
    Gtk::Image* i_back = Gtk::manage(new Gtk::Image{"backbutton.png"});
    Gtk::Button* b_back = Gtk::manage(new Gtk::Button());
    b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::employeeScreen));
    b_back->set_image(*i_back);

    // Save Emporium
    Gtk::Image* i_save = Gtk::manage(new Gtk::Image{"save.png"});
    Gtk::Button* b_save = Gtk::manage(new Gtk::Button());
    b_save->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onSaveClick));
    b_save->set_image(*i_save);
    
    // Load Emporium
    Gtk::Image* i_load = Gtk::manage(new Gtk::Image{"load.png"});
    Gtk::Button* b_load = Gtk::manage(new Gtk::Button());
    b_load->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onLoadClick));
    b_load->set_image(*i_load);
    
    // Add a new Customer
    Gtk::Image* i_addCustomer = Gtk::manage(new Gtk::Image{"addcustomer.png"});
    Gtk::Button* b_addCustomer = Gtk::manage(new Gtk::Button());
    b_addCustomer->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onAddCustomerClick));
    b_addCustomer->set_image(*i_addCustomer);

    // Add a new Server
    Gtk::Image* i_addServer = Gtk::manage(new Gtk::Image{"addserver.png"});
    Gtk::Button* b_addServer = Gtk::manage(new Gtk::Button());
    b_addServer->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onAddServerClick));
    b_addServer->set_image(*i_addServer);

    // Add a new Manager
    Gtk::Image* i_addManager = Gtk::manage(new Gtk::Image{"addmanager.png"});
    Gtk::Button* b_addManager = Gtk::manage(new Gtk::Button());
    b_addManager->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onAddManagerClick));
    b_addManager->set_image(*i_addManager);
    
    // Add a new Owner
    Gtk::Image* i_addOwner = Gtk::manage(new Gtk::Image{"addowner.png"});
    Gtk::Button* b_addOwner = Gtk::manage(new Gtk::Button());
    b_addOwner->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onAddOwnerClick));
    b_addOwner->set_image(*i_addOwner);

    // Permission Flags
    b_save->set_sensitive(true);
    b_load->set_sensitive(true);
    b_addCustomer->set_sensitive(true);
    b_addServer->set_sensitive(true);
    b_addOwner->set_sensitive(true);
    if (!m_isManager) {
        b_save->set_sensitive(false);
        b_load->set_sensitive(false);
        b_addServer->set_sensitive(false);
    }
    if (!m_isOwner) {
        b_addManager->set_sensitive(false);
        b_addOwner->set_sensitive(false);
    }

    Gtk::Grid* grid = Gtk::manage(new Gtk::Grid());
    grid->attach(*b_back, 0, 0, 1, 1);
    grid->attach(*b_addCustomer, 1, 1, 1, 1);
    grid->attach(*b_addServer, 2, 1, 1, 1);
    grid->attach(*b_addManager, 3, 1, 1, 1);
    grid->attach(*b_addOwner, 4, 1, 1, 1);
    grid->attach(*b_save, 1, 2, 1, 1);
    grid->attach(*b_load, 2, 2, 1, 1);

    box->add(*grid);
    mainbox->add(*box);
    mainbox->show_all();
}
