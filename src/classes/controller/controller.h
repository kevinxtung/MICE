#pragma once

#include "classes/emporium/emporium.h"
#include "classes/view/view.h"

class Controller {
    public:
	Controller(Emporium& emporium) : emporium(emporium), view(View(emporium)) { }
	void cli();
	void execute(int cmd);
    private:
	Emporium& emporium;
	View view;
};
