#pragma once

#include "classes/view/view.h"

class Controller {
    public:
	Controller() : view(View()) { }
	void cli();
	void execute(int cmd);
    private:
	View view;
};
