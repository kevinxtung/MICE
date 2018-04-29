#pragma once

#include <gtkmm.h>
#include "classes/emporium/emporium.h"
#include "classes/controller/controller.h"
#include "classes/serving/serving.h"
#include "classes/order/order.h"

extern Gtk::Box* mainbox;
extern Gtk::Box* box;
extern Gtk::Toolbar* toolbar;
extern Gtk::Box* selections; // Used in orderScreen();
extern int position; // Used in orderScreen();

class Main_Window : public Gtk::Window {
    public:
	Main_Window(Controller* controller);
	void clean();
	virtual ~Main_Window();
	Controller* getController();

    protected:
	//*********//
	//*SCREENS*//
	//*********//

	void defaultScreen();
	void employeeScreen();
		void showOrdersScreen();

	void orderScreen();
		void showContainers();
		void showScoops();
		void showToppings();

	void finalizeScreen();

	//***********//
	//*CALLBACKS*//
	//***********//

	void registerObserver();

	void onOrderClick();
		void onOrderDynamicClick(int button);
		void onOrderBackClick();
		void onOrderNextClick();
		void onOrderFinishClick();
			void onFinishPayClick();
		void flushServing();
		void flushOrder();

	void onEmployeeClick();
		void onCreateItemClick();
			void generate();
		void onSaveClick();
		void onLoadClick();



    private:
	Controller* m_controller;

	Gtk::Image* i_splash;

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
