#pragma once

#include <string>

class View {
    public:
	View() { }
	int select();
	void error(std::string message);
};
