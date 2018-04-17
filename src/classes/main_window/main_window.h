#pragma once

#include <gtkmm.h>
#include "classes/emporium/emporium.h"
#include "classes/controller/controller.h"

class Main_Window : public Gtk::Window {
    public:
	Main_Window(Controller* controller);
	void clean();
	virtual ~Main_Window();

    protected:
	// Screens
	void defaultScreen();
	void employeeScreen();

	// Callbacks
	void onOrderClick();
	void onEmployeeClick();
	void onCreateItemClick();

    private:
	Controller* m_controller;
	
	//************************//
	//*Customer Functionality*//
	//************************//

	// Create/Start Order
	Gtk::Button *b_order;
	Gtk::Image *i_order;

	//************************//
	//*Employee Functionality*//
	//************************//

	// Switch to Employee Mode
	Gtk::ToolButton *b_employee;
	Gtk::Image *i_employee;

	// Back to Customer Mode
	Gtk::ToolButton *b_back;
	Gtk::Image *i_back;

	// Create Item
	Gtk::ToolButton *b_createItem;
	Gtk::Image *i_createItem;

};
