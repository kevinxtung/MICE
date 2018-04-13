// Kevin Tung
// 1001229434
// MAVERICK ICE CREAM EMPORIUM

#include <iostream>
#include <gtkmm.h>
#include "classes/container/container.h"
#include "classes/controller/controller.h"
#include "classes/emporium/emporium.h"
#include "classes/main_window/main_window.h"

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "com.kevinxtung.mice");
    Emporium emporium;
    Controller controller(emporium);
    Main_Window window(&controller);
    window.set_title("Test GUI");

    return app->run(window);
}
