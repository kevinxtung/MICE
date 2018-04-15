#include "main_window.h"

//****************//
//*GUI MANAGEMENT*//
//****************//

// Global GUI Elements
Gtk::Box* mainbox = NULL;
Gtk::Box* box = NULL;
Gtk::Toolbar* toolbar = NULL;

Main_Window::Main_Window(Controller* controller) : m_controller(controller) {

    // GUI SETUP
    set_default_size(1366, 768);
    fullscreen();

    mainbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*mainbox);
    toolbar = Gtk::manage(new Gtk::Toolbar);
    box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    defaultScreen();
}

void Main_Window::clean() {
    mainbox->remove(*box);
    box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    toolbar = Gtk::manage(new Gtk::Toolbar);
}

Main_Window::~Main_Window() { }

//*********//
//*SCREENS*//
//*********//

void Main_Window::defaultScreen() {
    clean();
    mainbox->add(*box);
    box->add(*toolbar);

    i_order = Gtk::manage(new Gtk::Image{"randomicon.png"});
    b_order = Gtk::manage(new Gtk::ToolButton(*i_order));
    b_order->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onOrderClick));
    toolbar->append(*b_order);

    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);
    toolbar->append(*sep);

    i_employee = Gtk::manage(new Gtk::Image{"employeescreenbutton.png"});
    b_employee = Gtk::manage(new Gtk::ToolButton(*i_employee));
    b_employee->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onEmployeeClick));
    toolbar->append(*b_employee);

    mainbox->show_all();
}

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

//***********//
//*CALLBACKS*//
//***********//


void Main_Window::onOrderClick() {
    m_controller->execute(1);
}

void Main_Window::onCreateItemClick() {
    m_controller->execute(1);
}

void Main_Window::onEmployeeClick() {
    employeeScreen();
}
