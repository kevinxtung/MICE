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

    Gtk::Image* i_66 = Gtk::manage(new Gtk::Image{"66.png"});
    Gtk::ToolButton* b_66 = Gtk::manage(new Gtk::ToolButton(*i_66));
    b_66->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::generate));
    toolbar->append(*b_66);

    Gtk::Image* i_save = Gtk::manage(new Gtk::Image{"save.png"});
    Gtk::ToolButton* b_save = Gtk::manage(new Gtk::ToolButton(*i_save));
    b_save->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onSaveClick));
    toolbar->append(*b_save);
    
    Gtk::Image* i_load = Gtk::manage(new Gtk::Image{"load.png"});
    Gtk::ToolButton* b_load = Gtk::manage(new Gtk::ToolButton(*i_load));
    b_load->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onLoadClick));
    toolbar->append(*b_load);

    mainbox->show_all();
}

void Main_Window::onSaveClick() {
    m_controller->execute(3);
}
void Main_Window::onLoadClick() {
    m_controller->execute(4);
}