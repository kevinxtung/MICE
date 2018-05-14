#pragma once
#include <string>
#include <gtkmm.h>


class Keyboard {
    public:
		Keyboard();
		Keyboard(std::string style);
		Gtk::Box* generate(std::string style);

		Gtk::Box* getKeyboard();
        std::string getBuffer();
        void clearBuffer();

    private:
		Gtk::Box* m_keyboard;
        std::string m_buffer;

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

		void space();

		void i0();
		void i00();
		void decimal();
		void dash();
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
};