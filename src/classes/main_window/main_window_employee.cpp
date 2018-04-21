#include "main_window.h"

void Main_Window::employeeScreen() {
    clean();
    mainbox->add(*box);
    box->add(*toolbar);
    
    i_back = Gtk::manage(new Gtk::Image{"backbutton.png"});
    b_back = Gtk::manage(new Gtk::ToolButton(*i_back));
    b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::defaultScreen));
    toolbar->append(*b_back);

    //Gtk::Toolbar *toolbar2 = Gtk::manage(new Gtk::Toolbar);

    i_createItem = Gtk::manage(new Gtk::Image{"createitem.png"});
    b_createItem = Gtk::manage(new Gtk::ToolButton(*i_createItem));
    b_createItem->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onCreateItemClick));
    toolbar->append(*b_createItem);

    mainbox->show_all();
}