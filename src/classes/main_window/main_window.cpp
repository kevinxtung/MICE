#include "main_window.h"

//****************//
//*GUI MANAGEMENT*//
//****************//

// Global GUI Elements
Gtk::Box* mainbox = NULL;
Gtk::Box* box = NULL;
Gtk::Toolbar* toolbar = NULL;
Gtk::Box* selections = NULL;

Main_Window::Main_Window(Controller* controller) : m_controller(controller) {

    // GUI SETUP
    set_default_size(1366, 768); // 1366x768 Native
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


//***********//
//*CALLBACKS*//
//***********//


void Main_Window::onOrderClick() {
    position = 1;
    orderScreen();
}

void Main_Window::onCreateItemClick() {
    m_controller->execute(1);
}

void Main_Window::onEmployeeClick() {
    employeeScreen();
}
