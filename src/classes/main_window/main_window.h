#pragma once

#include <gtkmm.h>
#include "classes/emporium/emporium.h"
#include "classes/controller/controller.h"

// DELETE
#include "classes/container/container.h"
#include <string>

extern Gtk::Box* mainbox;
extern Gtk::Box* box;
extern Gtk::Toolbar* toolbar;
extern Gtk::Box* selections; // Used in orderScreen();
extern int position;

class Main_Window : public Gtk::Window {
    public:
	Main_Window(Controller* controller);
	void clean();
	virtual ~Main_Window();

    protected:
	// Screens
	void defaultScreen();
	void employeeScreen();

	void orderScreen();
		void showContainers();
		void showScoops();
		void showToppings();


	// Callbacks
	void registerObserver();

	void onOrderClick();
		void onOrderBackClick();
		void onOrderNextClick();

	void onEmployeeClick();
	void onCreateItemClick();

    private:
	Controller* m_controller;

	Gtk::Image *i_splash;

	//************************//
	//*Customer Functionality*//
	//************************//

	// Create/Start Order
	Gtk::Button *b_order;
	Gtk::Image *i_order;

	//*********************//
	//*Order Functionality*//
	//*********************//
	// Holds images for drawing ice cream.
	std::vector<Gtk::Image> *i_imageBox;

	/*Gtk::Button *b_;
	Gtk::Button *b_;
	Gtk::Button *b_;
	Gtk::Button *b_;	
*/
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
