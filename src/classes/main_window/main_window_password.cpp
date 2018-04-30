#include "main_window.h"

void Main_Window::passwordScreen() {
    clean();
    entry = Gtk::manage(new Gtk::Entry());
    numpadSetup();

    Gtk::Button* b_clear = Gtk::manage(new Gtk::Button("CLEAR"));
    Gtk::Button* b_enter = Gtk::manage(new Gtk::Button("ENTER"));
    b_clear->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::flushEntry));
    b_enter->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::employeeScreen));

    Gtk::Grid* grid = Gtk::manage(new Gtk::Grid());
    grid->attach(*entry, 1, 0, 3, 1);
    grid->attach(*numpad, 1, 1, 3, 1);
    grid->attach(*b_clear, 1, 2, 1, 1);
    grid->attach(*b_enter, 3, 2, 1, 1);

    box->add(*grid);
    mainbox->add(*box);
    mainbox->show_all();
}