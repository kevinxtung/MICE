#include "main_window.h"

#include <chrono>
#include <time.h>

void Main_Window::finishedOrderScreen() {
    clean();
    Gtk::Label* l_finished = Gtk::manage(new Gtk::Label("Your order has been successfully submitted!"));
    box->set_center_widget(*l_finished);
    mainbox->add(*box);
    mainbox->show_all();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    defaultScreen();
}
