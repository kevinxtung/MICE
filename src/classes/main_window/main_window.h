#pragma once

#include <gtkmm.h>
#include "classes/emporium/emporium.h"
#include "classes/controller/controller.h"
#include "classes/serving/serving.h"
#include "classes/order/order.h"
#include <string>

extern Gtk::Box* mainbox;
extern Gtk::Box* box;
extern Gtk::Box* keyboard;
extern Gtk::Box* numpad;
extern Gtk::Entry* entry;
extern Gtk::Toolbar* toolbar;
extern Gtk::Box* selections; // Used in orderScreen();
extern int position; // Used in orderScreen();
extern std::string input;

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
	void passwordScreen();
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

	void verifyPassword();

	void onEmployeeClick();
		void onCreateItemClick();
			void generate();
		void onSaveClick();
		void onLoadClick();

		void keyboardSetup();
		void numpadSetup(std::string type);
		void flushEntry();

		void Q();
		void W();
		void E();
		void R();
		void T();
		void Y();
		void U();
		void I();
		void O();
		void P();

		void A();
		void S();
		void D();
		void F();
		void G();
		void H();
		void J();
		void K();
		void L();

		void Z();
		void X();
		void C();
		void V();
		void B();
		void N();
		void M();

		void i0();
		void i00();
		void decimal();
		void i1();
		void i2();
		void i3();
		void i4();
		void i5();
		void i6();
		void i7();
		void i8();
		void i9();
		void BKSP();

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
