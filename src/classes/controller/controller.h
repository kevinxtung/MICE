#pragma once

#include "classes/emporium/emporium.h"
#include "classes/view/view.h"
#include "classes/dialogs/dialogs.h"
#include <string>

class Controller {
    public:
		Controller(Emporium& emporium) : m_emporium{emporium}, m_view{View(emporium)} { }
		void cli();
		void execute(int cmd);
		void save();
		void load();
		enum tokenCode {eBalance, eContainer, eScoop, eTopping};
		tokenCode hashToken(std::string token);
		Emporium& getEmporium();

    private:
		Emporium& m_emporium;
		View m_view;
};