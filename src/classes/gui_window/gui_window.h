#pragma once

#include <gtkmm.h>
#include "classes/emporium/emporium.h"
#include "classes/controller/controller.h"

class GUI_Window : public Gtk::Window {
    public:
	GUI_Window(Controller* controller);
	virtual ~GUI_Window();

    protected:
	void on_button0_click();

    private:
	Controller* m_controller;

	Gtk::ToolButton *button0;
	Gtk::Image *button0_image;
};
