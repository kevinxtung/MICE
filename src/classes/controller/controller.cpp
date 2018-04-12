#include "controller.h"
#include <string>
#include <iostream>

void Controller::cli() {
    int cmd = -1;
    while (cmd != 0) {
	cmd = view.select();
	execute(cmd);
    }
}

void Controller::execute(int cmd) {
    if (!cmd) {
	return;
    }
    switch (cmd) {
	case 0:	    // Exit
	    break;
	case 1:	{    // Create item
	    std::string name, description;
	    double rawCost, retailPrice;
	    int type;

	    Gtk::Dialog *dialog = new Gtk::Dialog();
	    dialog->set_title("Create New Item");

	    // Title
	    Gtk::HBox b_name;
	    Gtk::Label l_name{"Name: "};
	    l_name.set_width_chars(15);
	    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

	    Gtk::Entry e_name;
	    e_name.set_max_length(50);
	    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
	    dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

	    // Description
	    Gtk::HBox b_description;
	    Gtk::Label l_description{"Description: "};
	    l_description.set_width_chars(15);
	    b_description.pack_start(l_description, Gtk::PACK_SHRINK);

	    Gtk::Entry e_description;
	    e_description.set_max_length(50);
	    b_description.pack_start(e_description, Gtk::PACK_SHRINK);
	    dialog->get_vbox()->pack_start(b_description, Gtk::PACK_SHRINK);

	    // Cost
 	    Gtk::HBox b_rawCost;
	    Gtk::Label l_rawCost{"Cost per item: "};
	    l_rawCost.set_width_chars(15);
	    b_rawCost.pack_start(l_rawCost, Gtk::PACK_SHRINK);

	    Gtk::Entry e_rawCost;
	    e_rawCost.set_max_length(50);
	    b_rawCost.pack_start(e_rawCost, Gtk::PACK_SHRINK);
	    dialog->get_vbox()->pack_start(b_rawCost, Gtk::PACK_SHRINK);
   
	    // Price
	    Gtk::HBox b_retailPrice;
	    Gtk::Label l_retailPrice{"Price per item: "};
	    l_retailPrice.set_width_chars(15);
	    b_retailPrice.pack_start(l_retailPrice, Gtk::PACK_SHRINK);

	    Gtk::Entry e_retailPrice;
	    e_retailPrice.set_max_length(50);
	    b_retailPrice.pack_start(e_retailPrice, Gtk::PACK_SHRINK);
	    dialog->get_vbox()->pack_start(b_retailPrice, Gtk::PACK_SHRINK);
	    
	    // Type
	    Gtk::HBox b_type;
	    Gtk::Label l_type{"Type of item: "};
	    l_type.set_width_chars(15);
	    b_type.pack_start(l_type, Gtk::PACK_SHRINK);

	    Gtk::ComboBoxText c_type;
	    c_type.set_size_request(160);
	    c_type.append("Container");
	    c_type.append("Scoop");
	    c_type.append("Topping");
	    b_type.pack_start(c_type, Gtk::PACK_SHRINK);
	    dialog->get_vbox()->pack_start(b_type, Gtk::PACK_SHRINK);

	    // Finishing up dialog
	    dialog->add_button("Cancel", 0);
	    dialog->add_button("Create", 1);
	    dialog->show_all();
	    int result = dialog->run();

	    dialog->close();
	    while (Gtk::Main::events_pending()) {
		Gtk::Main::iteration();
	    }

	    if (result == 1) {
		name = e_name.get_text();
		description = e_description.get_text();
		rawCost = std::stod(e_rawCost.get_text());
		retailPrice = std::stod(e_retailPrice.get_text());
		type = c_type.get_active_row_number();
		switch (type) {
		    case 0:
			emporium.addItem(Item(name, description, rawCost, retailPrice));
			break;
		    case 1:
			emporium.addItem(Item(name, description, rawCost, retailPrice));
			break;
		    case 2:
			emporium.addItem(Item(name, description, rawCost, retailPrice));
			break;
		    default:
			break;
		}
	    }
	    break;
	}
	case 2:
	    break;
	default:
	    view.error("ERROR: INVALID COMMAND.");
	    break;
    }

}
