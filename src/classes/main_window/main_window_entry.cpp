#include "main_window.h"
#include <string>
#include <regex>

std::string g_name;
std::string g_number;

void Main_Window::entryScreen(std::string prompt, std::string type, int function) {
    clean();
    entry = Gtk::manage(new Gtk::Entry());
    keyboardSetup(type);

    Gtk::Image* i_back = Gtk::manage(new Gtk::Image{"backbutton.png"});
    Gtk::Button* b_back = Gtk::manage(new Gtk::Button());
    b_back->set_image(*i_back);
    b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::defaultScreen));

    Gtk::Button* b_clear = Gtk::manage(new Gtk::Button("CLEAR"));
    Gtk::Button* b_enter = Gtk::manage(new Gtk::Button("ENTER"));
    b_clear->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::flushEntry));
    switch(function) {
        case 1:
            b_enter->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::getEntryName));
            break;
        case 2:
            b_enter->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::getEntryNumber));
            break;
    }
    
    Gtk::Label* l_prompt = Gtk::manage(new Gtk::Label(prompt));

    Gtk::Grid* grid = Gtk::manage(new Gtk::Grid());
    grid->attach(*b_back, 0, 0, 1, 1);
    grid->attach(*l_prompt, 2, 1, 1, 1);
    grid->attach(*entry, 1, 2, 3, 1);
    grid->attach(*keyboard, 1, 3, 3, 1);
    grid->attach(*b_clear, 1, 4, 1, 1);
    grid->attach(*b_enter, 3, 4, 1, 1);

    box->add(*grid);
    mainbox->add(*box);
    mainbox->show_all();
}

void Main_Window::entryScreen(std::string prompt, std::string description, std::string type, int function) {
    clean();
    entry = Gtk::manage(new Gtk::Entry());
    keyboardSetup(type);

    Gtk::Image* i_back = Gtk::manage(new Gtk::Image{"backbutton.png"});
    Gtk::Button* b_back = Gtk::manage(new Gtk::Button());
    b_back->set_image(*i_back);
    b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::defaultScreen));

    Gtk::Button* b_clear = Gtk::manage(new Gtk::Button("CLEAR"));
    Gtk::Button* b_enter = Gtk::manage(new Gtk::Button("ENTER"));
    b_clear->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::flushEntry));
    switch(function) {
        case 1:
            b_enter->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::getEntryName));
            break;
        case 2:
            b_enter->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::getEntryNumber));
            break;
    }
    
    Gtk::Label* l_prompt = Gtk::manage(new Gtk::Label(prompt));
    Gtk::Label* l_description = Gtk::manage(new Gtk::Label(description));

    Gtk::Grid* grid = Gtk::manage(new Gtk::Grid());
    grid->attach(*b_back, 0, 0, 1, 1);
    grid->attach(*l_prompt, 2, 1, 1, 1);
    grid->attach(*l_description, 1, 2, 3, 1);
    grid->attach(*entry, 1, 3, 3, 1);
    grid->attach(*keyboard, 1, 4, 3, 1);
    grid->attach(*b_clear, 1, 5, 1, 1);
    grid->attach(*b_enter, 3, 5, 1, 1);

    box->add(*grid);
    mainbox->add(*box);
    mainbox->show_all();
}

// REGEX
void Main_Window::getEntryName() {
    std::string name = entry->get_text();
    std::regex regexName{"[A-Z]+[ ][A-Z]+"};
    if (std::regex_match(name, regexName)) {
        g_name = name;
        entryScreen("Number", "Format as XXX-XXX-XXXX", "NUMBER", 2);
    } else {
        entry->set_text("***INVALID NAME FORMAT***");
    }
}

// REGEX
void Main_Window::getEntryNumber() {
    std::string number = entry->get_text();
    std::regex regexNumber{"[0-9][0-9][0-9][-][0-9][0-9][0-9][-][0-9][0-9][0-9][0-9]"};
    if (std::regex_match(number, regexNumber)) {
        g_number = number;
        defaultScreen();
    } else {
        entry->set_text("***INVALID NUMBER FORMAT***");
    }
}

