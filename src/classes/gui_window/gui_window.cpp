#include "gui_window.h"

GUI_Window::GUI_Window(Controller* controller) : m_controller(controller) {
    // GUI SETUP
    set_default_size(640, 320);

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    button0_image = Gtk::manage(new Gtk::Image{"randombutton.png"});
    button0 = Gtk::manage(new Gtk::ToolButton(*button0_image));
    button0->set_tooltip_markup("TEST FEATURE");
    button0->signal_clicked().connect(sigc::mem_fun(*this, &GUI_Window::on_button0_click));
    toolbar->append(*button0);

    vbox->show_all();
}

GUI_Window::~GUI_Window() { }

// Callbacks

void GUI_Window::on_button0_click() {
    controller->execute_cmd(1);
}
