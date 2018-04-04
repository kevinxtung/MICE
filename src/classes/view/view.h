#pragma once

#include <string>

class View {
    public:
	int select();
	void error(std::string message);
};
