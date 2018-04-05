#pragma once

#include "classes/emporium/emporium.h"
#include <string>

class View {
    public:
	View(Emporium& emporium) : emporium(emporium) { }
	int select();
	void error(std::string message);
    private:
	Emporium& emporium;
};
