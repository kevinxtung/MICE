#include "main_window.h"

#include <thread>

void Main_Window::finishedOrder() {
    
    // https://stackoverflow.com/questions/41476077/thread-error-invalid-use-of-non-static-member-function
    // An error was resolved in the thread below using the above SO link.
    std::thread screen(&Main_Window::finishedOrderScreen, this);
    screen.join();

    std::thread delay(&Main_Window::sleep, this, 5000);
    delay.join();
    
    defaultScreen();
}

void Main_Window::finishedOrderScreen() {
    clean();
    Gtk::Label* l_finished = Gtk::manage(new Gtk::Label("Your order has been successfully submitted!"));
    box->set_center_widget(*l_finished);
    mainbox->add(*box);
    mainbox->show_all();
    std::cout << "DONE" << std::endl;
}
