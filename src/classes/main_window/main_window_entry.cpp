#include "main_window.h"
#include <string>
#include <regex>

std::string g_name;
std::string g_number;
double g_salary;
int permission = -1;

void Main_Window::entryScreen(std::string prompt, std::string type, int function) {
    clean();
    entry = Gtk::manage(new Gtk::Entry());
    keyboardSetup(type);

    Gtk::Image* i_back = Gtk::manage(new Gtk::Image{"backbutton.png"});
    Gtk::Button* b_back = Gtk::manage(new Gtk::Button());
    b_back->set_image(*i_back);
    b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::finalizeScreen));

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

    if (permission == 1) {
        b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::finalizeScreen));
    }
    else if (permission >= 1 && permission <= 4) {
        b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::showRecordsScreen));
    } else {
        b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::defaultScreen));
    }

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
        case 3:
            b_enter->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::getEntrySalary));
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
    // REGEX HERE
    std::regex regexName{"[A-Z]+[ ][A-Z]+"};
    if (std::regex_match(name, regexName)) {
        g_name = name;
        if (permission == -1) {
            std::cerr << "Something went wrong in main_window_entry.cpp(getEntryName())." << std::endl;
        }
        if (permission == 0) {
            entryScreen("Please Enter Your Phone Number", "Format Your Number As XXX-XXX-XXXX", "NUMBER", 2);
        }
        if (permission == 5) { // From onFinishPayClick in finalize
            return; // Don't do anything. We just want the name.
        }
        else {
            entryScreen("Phone Number", "Format as XXX-XXX-XXXX", "NUMBER", 2);
        }
    } else {
        flushEntry();
        g_name = "";
        entry->set_text("***INVALID NAME FORMAT***");
    }
}

// REGEX
void Main_Window::getEntryNumber() {
    std::string number = entry->get_text();
    // REGEX HERE
    std::regex regexNumber{"[0-9][0-9][0-9][-][0-9][0-9][0-9][-][0-9][0-9][0-9][0-9]"};
    if (std::regex_match(number, regexNumber)) {
        g_number = number;
        switch(permission) {
            case 0: {   // Customer, calling a new entry from making an order
                m_controller->getEmporium().addCustomer(Customer(g_name, g_number));
                std::vector<Order>& orders = m_controller->getEmporium().getOrders();
                orders[top-1].recieve();
                orders[top-1].setName(g_name);
                finishedOrderScreen();
                break;
            }
            case 1: {   // Customer, calling from employee's creation
                m_controller->getEmporium().addCustomer(Customer(g_name, g_number));
                showRecordsScreen();
                break;
            }
            case 2: {   // Server Specific Case
                entryScreen("Please Enter Server's Salary", "Salary Is In Dollars Per Four Orders", "DOUBLE", 3);
                break;
            }
            case 3: {   // Manager Creation
                m_controller->getEmporium().addManager(Manager(g_name, g_number));
                showRecordsScreen();
                break;
            }
            case 4: {   // Owner Creation
                m_controller->getEmporium().addOwner(Owner(g_name, g_number));
                showRecordsScreen();
                break;
            }
            default:
                defaultScreen();
        }
    } else {
        flushEntry();
        entry->set_text("***INVALID NUMBER FORMAT***");
    }
}

void Main_Window::getEntrySalary() {
    std::string salary = entry->get_text();
    std::regex regexSalary{"[0-9]+[.][0-9][0-9]"};
    if (std::regex_match(salary, regexSalary)) {
        g_salary = std::stod(salary);
        m_controller->getEmporium().addServer(Server(g_name, g_number, g_salary));
        showRecordsScreen();
    }
    else {
        flushEntry();
        entry->set_text("***INVALID NUMBER FORMAT***");
    }
}

void Main_Window::onNewCustomerClick() {
    permission = 0;
    entryScreen("Please Enter Your First and Last Name", "TEXT", 1);
}

void Main_Window::onAddCustomerClick() {
    permission = 1;
    entryScreen("Name", "Enter Customer's First and Last Name", "TEXT", 1);
}

void Main_Window::onAddServerClick() {
    permission = 2;
    entryScreen("Name", "Enter Server's First and Last Name", "TEXT", 1);
}

void Main_Window::onAddManagerClick() {
    permission = 3;
    entryScreen("Name", "Enter Manager's First and Last Name", "TEXT", 1);
}

void Main_Window::onAddOwnerClick() {
    permission = 4;
    entryScreen("Name", "Enter Owner's First and Last Name", "TEXT", 1);
}

