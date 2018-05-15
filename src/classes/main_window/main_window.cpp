#include "main_window.h"

#include <regex>
#include <chrono>
#include <thread>
#include <time.h>

// Global GUI Elements
Gtk::Box* mainbox = NULL;
Gtk::Box* box = NULL;
Gtk::Box* keyboard = NULL;
Gtk::Entry* entry = NULL;
Gtk::Toolbar* toolbar = NULL;
Gtk::Box* selections = NULL;
std::string activeEmployee;

Main_Window::Main_Window(Controller* controller) : m_controller{controller}, m_isOwner{false}, m_isManager{false} {

    // Initial GUI Setup
    set_default_size(1366, 768); // 1366x768 Native
    fullscreen();

    mainbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*mainbox);
    toolbar = Gtk::manage(new Gtk::Toolbar);
    box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    defaultScreen();
}
Main_Window::~Main_Window() { }

// Refreshes the screen by setting the mainbox to a new empty box.
void Main_Window::clean() {
    mainbox->remove(*box);
    box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    toolbar = Gtk::manage(new Gtk::Toolbar);
}


Controller* Main_Window::getController() {return m_controller;}

// Thread that delays program for specified milliseconds.
void Main_Window::sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    defaultScreen();
}


//***********//
//*CALLBACKS*//
//***********//


void Main_Window::onOrderClick() {
    position = 1;
    orderScreen();
}


void Main_Window::onEmployeeClick() {
    passwordScreen();
}

void Main_Window::generate() {
    m_controller->execute(66);
}

std::string Main_Window::priceFix(std::string price) {
    std::regex regexPrice{"[0-9]+[.][0-9][0-9]"};
    std::regex regexDecimal{"[.]"};
    if (!std::regex_match(price, regexPrice)) {
        if (std::regex_search(price, regexDecimal)) {
            price += '0';
        }
        else {
            price += ".00";
        }
    }
    return price;
}