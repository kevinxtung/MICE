#include "main_window.h"
#include <stdexcept>
#include <string>

void Main_Window::passwordScreen() {
    clean();
    entry = Gtk::manage(new Gtk::Entry());

    //keyboardSetup("INT");

    Gtk::Image* i_back = Gtk::manage(new Gtk::Image{"backbutton.png"});
    Gtk::Button* b_back = Gtk::manage(new Gtk::Button());
    b_back->set_image(*i_back);
    b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::defaultScreen));

    Gtk::Button* b_clear = Gtk::manage(new Gtk::Button("CLEAR"));
    Gtk::Button* b_enter = Gtk::manage(new Gtk::Button("ENTER"));
    b_clear->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::flushEntry));
    b_enter->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::verifyPassword));

    Gtk::Label* l_label = Gtk::manage(new Gtk::Label("ENTER EMPLOYEE ID:"));

    Gtk::Grid* grid = Gtk::manage(new Gtk::Grid());
    grid->attach(*b_back, 0, 0, 1, 1);
    grid->attach(*l_label, 1, 1, 1, 1);
    grid->attach(*entry, 1, 2, 3, 1);// look into using has_focus?
    Keyboard keyboard("DIGIT");
    Gtk::Box* keyboardBox = keyboard.getKeyboard();
    grid->attach(*keyboardBox, 1, 3, 3, 1);
    grid->attach(*b_clear, 1, 4, 1, 1);
    grid->attach(*b_enter, 3, 4, 1, 1);

    box->add(*grid);
    mainbox->add(*box);
    mainbox->show_all();
}

void Main_Window::verifyPassword() {
    std::string code = "";
    //try {
    code = entry->get_text();
    /*} catch (std::exception e) {
        flushEntry();
        entry->set_text("***INVALID INPUT***");
        return;
    }*/
    if (code == "8675309") {
        m_isOwner = true;
        m_isManager = true;
        activeEmployee = "8675309";
        employeeScreen();
        return;
    }
    /*switch (code) {
        case 8675309:   // Owner Privilege
            m_isOwner = true;
        case 1957:      // Manager Privilege
        case 00:      // Employee Privilege
            break;
        default:
            flushEntry();
            entry->set_text("***INVALID PIN***");
            return;
    }*/
    std::vector<Server>& servers = m_controller->getEmporium().getServers();
    for (auto i : servers) {
        if (i.getID() == code) {
            activeEmployee = code;
            employeeScreen();
            return;
        }
    }
    std::vector<Manager>& managers = m_controller->getEmporium().getManagers();
    for (auto i : managers) {
        if (i.getID() == code) {
            activeEmployee = code;
            m_isManager = true;
            employeeScreen();
            return;
        }
    }
    std::vector<Owner>& owners = m_controller->getEmporium().getOwners();
    for (auto i : owners) {
        if (i.getID() == code) {
            activeEmployee = code;
            m_isOwner = true;
            m_isManager = true;
            employeeScreen();
            return;
        }
    }
    flushEntry();
    entry->set_text("***INVALID ID***");
    return;
}