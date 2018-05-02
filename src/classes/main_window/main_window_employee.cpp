#include "main_window.h"

#define X_EMPLOYEE 240
#define Y_EMPLOYEE 80

void Main_Window::employeeScreen() {
    clean();
    
    Gtk::Image* i_back = Gtk::manage(new Gtk::Image{"backbutton.png"});
    Gtk::Button* b_back = Gtk::manage(new Gtk::Button());
    b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::defaultScreen));
    b_back->set_image(*i_back);

    Gtk::Image* i_showOrders = Gtk::manage(new Gtk::Image{"showorders.png"});
    Gtk::Button* b_showOrders = Gtk::manage(new Gtk::Button());
    b_showOrders->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::showOrdersScreen));
    b_showOrders->set_image(*i_showOrders);

    Gtk::Image* i_showInventory = Gtk::manage(new Gtk::Image{"showinventory.png"});
    Gtk::Button* b_showInventory = Gtk::manage(new Gtk::Button());
    b_showInventory->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::showInventoryScreen));
    b_showInventory->set_image(*i_showInventory);

    Gtk::Image* i_showRecords = Gtk::manage(new Gtk::Image{"showrecords.png"});
    Gtk::Button* b_showRecords = Gtk::manage(new Gtk::Button());
    b_showRecords->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::showRecordsScreen));
    b_showRecords->set_image(*i_showRecords);

    std::string activeEmployeeText = "Active Employee ID: ";
    activeEmployeeText += activeEmployee;
    Gtk::Label* l_activeEmployee = Gtk::manage(new Gtk::Label(activeEmployeeText));

    int x, y, offsetX, offsetY;
    Gtk::Window::get_size(x, y);
    offsetX = (x-X_EMPLOYEE)/3;
    offsetY = (y-Y_EMPLOYEE)/24;

    Gtk::Grid *grid = Gtk::manage(new Gtk::Grid());
    grid->set_column_spacing(offsetX);
    grid->set_row_spacing(offsetY);
    grid->attach(*b_back, 0, 0, 1, 1);
    grid->attach(*b_showOrders, 1, 1, 1, 1);
    grid->attach(*b_showInventory, 1, 2, 1, 1);
    grid->attach(*b_showRecords, 1, 3, 1, 1);
    grid->attach(*l_activeEmployee, 2, 4, 1, 1);

    box->add(*grid);
    mainbox->add(*box);
    mainbox->show_all();
}

void Main_Window::onSaveClick() {
    m_controller->execute(3);
}
void Main_Window::onLoadClick() {
    m_controller->execute(4);
}