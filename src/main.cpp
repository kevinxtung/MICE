#include <iostream>
#include "classes/container/container.h"
#include "classes/controller/controller.h"
#include "classes/emporium/emporium.h"

int main(int argc, char* argv[]) {
    Emporium emporium;
    Controller controller(emporium);
    controller.cli();
}
