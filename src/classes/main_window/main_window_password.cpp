#include "main_window.h"
#include <stdexcept>
#include <string>

void Main_Window::passwordScreen() {
    clean();
    entry = Gtk::manage(new Gtk::Entry());
    numpadSetup("INT");

    Gtk::Image* i_back = Gtk::manage(new Gtk::Image{"backbutton.png"});
    Gtk::Button* b_back = Gtk::manage(new Gtk::Button());
    b_back->set_image(*i_back);
    b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::defaultScreen));

    Gtk::Button* b_clear = Gtk::manage(new Gtk::Button("CLEAR"));
    Gtk::Button* b_enter = Gtk::manage(new Gtk::Button("ENTER"));
    b_clear->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::flushEntry));
    b_enter->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::verifyPassword));

    Gtk::Grid* grid = Gtk::manage(new Gtk::Grid());
    grid->attach(*b_back, 0, 0, 1, 1);
    grid->attach(*entry, 1, 0, 3, 1);
    grid->attach(*numpad, 1, 1, 3, 1);
    grid->attach(*b_clear, 1, 2, 1, 1);
    grid->attach(*b_enter, 3, 2, 1, 1);

    box->add(*grid);
    mainbox->add(*box);
    mainbox->show_all();
}

void Main_Window::verifyPassword() {
    int code = -1;
    try {
        code = std::stoi(entry->get_text());
    } catch (std::exception e) {
        entry->set_text("***INVALID SYMBOL DETECTED***");
        return;
    }
    if (code != 1957) {
        defaultScreen();
    }
    else {
        employeeScreen();
    }
}