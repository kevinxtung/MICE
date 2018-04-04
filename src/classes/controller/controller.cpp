#include "controller.h"
#include <string>

void Controller::cli() {
    int cmd = -1;
    while (cmd != 0) {
	cmd = view.select();
	execute(cmd);
    }
}

void Controller::execute(int cmd) {
    switch (cmd) {
	case 0:	    // Exit
	    break;
	case 1:	    // Create flavor
	    break;
	case 2:	    // Create container	    
	    break;
	case 3:	    // Create topping
	    break;
	default:
	    view.error("Invalid command.");
    }

}
