#include "main_window.h"

#define X_ORDERIMAGE 512
#define Y_ORDERIMAGE 128

void Main_Window::defaultScreen() {
    clean();
    mainbox->add(*box);
    box->add(*toolbar);

    m_isOwner = false;
    m_isManager = false;
//    i_splash = Gtk::manage(new Gtk::Image{"splash.png"});
  //  box->add(*i_splash);

    i_order = Gtk::manage(new Gtk::Image{"startorderbutton.png"});
    b_order = Gtk::manage(new Gtk::Button());
    b_order->set_image(*i_order);
    b_order->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onOrderClick));

//    Gtk::Alignment *align = Gtk::manage(new Gtk::Alignment(0.5, 0.5, 0, 0));
//    align->add(*b_order);
    
    int x, y, offsetX, offsetY;
    Gtk::Window::get_size(x, y);
    offsetX = (x-X_ORDERIMAGE)/2;
    offsetY = (y-Y_ORDERIMAGE)/3;

    Gtk::Grid *grid = Gtk::manage(new Gtk::Grid());
    grid->set_column_spacing(offsetX);
    grid->set_row_spacing(offsetY);
    Gtk::Box *blank = Gtk::manage(new Gtk::Box());
    grid->attach(*blank, 0, 0, 1, 1);
    grid->attach(*b_order, 1, 1, 1, 1);

    box->set_center_widget(*grid);

//    box->set_center_widget(*align);

    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);
    sep->set_opacity(0.0);
    toolbar->append(*sep);

    i_employee = Gtk::manage(new Gtk::Image{"employeescreenbutton.png"});
    b_employee = Gtk::manage(new Gtk::ToolButton(*i_employee));
    b_employee->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onEmployeeClick));
    b_employee->set_opacity(0.0);
    toolbar->append(*b_employee);
    
    mainbox->show_all();
}
