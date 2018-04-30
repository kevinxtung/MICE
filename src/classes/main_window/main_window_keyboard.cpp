#include "main_window.h"
#include <string>

std::string input = "";

void Main_Window::flushEntry() {
    input = "";
    entry->set_text(input);
}

void Main_Window::keyboardSetup() {
    // Flush the entry box every time we are ready for the keyboard
    flushEntry();

    Gtk::Box* keyboardBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    Gtk::ButtonBox* topRow = Gtk::manage(new Gtk::ButtonBox());    
    Gtk::ButtonBox* homeRow = Gtk::manage(new Gtk::ButtonBox());    
    Gtk::ButtonBox* bottomRow = Gtk::manage(new Gtk::ButtonBox());    

    Gtk::Button* b_Q = Gtk::manage(new Gtk::Button("Q"));
    Gtk::Button* b_W = Gtk::manage(new Gtk::Button("W"));
    Gtk::Button* b_E = Gtk::manage(new Gtk::Button("E"));
    Gtk::Button* b_R = Gtk::manage(new Gtk::Button("R"));
    Gtk::Button* b_T = Gtk::manage(new Gtk::Button("T"));
    Gtk::Button* b_Y = Gtk::manage(new Gtk::Button("Y"));
    Gtk::Button* b_U = Gtk::manage(new Gtk::Button("U"));
    Gtk::Button* b_I = Gtk::manage(new Gtk::Button("I"));
    Gtk::Button* b_O = Gtk::manage(new Gtk::Button("O"));
    Gtk::Button* b_P = Gtk::manage(new Gtk::Button("P"));

    Gtk::Button* b_A = Gtk::manage(new Gtk::Button("A"));
    Gtk::Button* b_S = Gtk::manage(new Gtk::Button("S"));
    Gtk::Button* b_D = Gtk::manage(new Gtk::Button("D"));
    Gtk::Button* b_F = Gtk::manage(new Gtk::Button("F"));
    Gtk::Button* b_G = Gtk::manage(new Gtk::Button("G"));
    Gtk::Button* b_H = Gtk::manage(new Gtk::Button("H"));
    Gtk::Button* b_J = Gtk::manage(new Gtk::Button("J"));
    Gtk::Button* b_K = Gtk::manage(new Gtk::Button("K"));
    Gtk::Button* b_L = Gtk::manage(new Gtk::Button("L"));

    Gtk::Button* b_Z = Gtk::manage(new Gtk::Button("Z"));
    Gtk::Button* b_X = Gtk::manage(new Gtk::Button("X"));
    Gtk::Button* b_C = Gtk::manage(new Gtk::Button("C"));
    Gtk::Button* b_V = Gtk::manage(new Gtk::Button("V"));
    Gtk::Button* b_B = Gtk::manage(new Gtk::Button("B"));
    Gtk::Button* b_N = Gtk::manage(new Gtk::Button("N"));
    Gtk::Button* b_M = Gtk::manage(new Gtk::Button("M"));
    Gtk::Button* b_BKSP = Gtk::manage(new Gtk::Button("<"));
    
    b_Q->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::Q));
    b_W->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::W));
    b_E->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::E));
    b_R->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::R));
    b_T->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::T));
    b_Y->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::Y));
    b_U->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::U));
    b_I->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::I));
    b_O->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::O));
    b_P->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::P));

    b_A->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::A));
    b_S->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::S));
    b_D->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::D));
    b_F->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::F));
    b_G->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::G));
    b_H->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::H));
    b_J->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::J));
    b_K->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::K));
    b_L->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::L));

    b_Z->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::Z));
    b_X->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::X));
    b_C->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::C));
    b_V->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::V));
    b_B->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::B));
    b_N->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::N));
    b_M->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::M));
    b_BKSP->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::BKSP));

    topRow->pack_start(*b_Q, Gtk::PACK_SHRINK, 0);
    topRow->pack_start(*b_W, Gtk::PACK_SHRINK, 0);
    topRow->pack_start(*b_E, Gtk::PACK_SHRINK, 0);
    topRow->pack_start(*b_R, Gtk::PACK_SHRINK, 0);
    topRow->pack_start(*b_T, Gtk::PACK_SHRINK, 0);
    topRow->pack_start(*b_Y, Gtk::PACK_SHRINK, 0);
    topRow->pack_start(*b_U, Gtk::PACK_SHRINK, 0);
    topRow->pack_start(*b_I, Gtk::PACK_SHRINK, 0);
    topRow->pack_start(*b_O, Gtk::PACK_SHRINK, 0);
    topRow->pack_start(*b_P, Gtk::PACK_SHRINK, 0);

    homeRow->pack_start(*b_A, Gtk::PACK_SHRINK, 0);
    homeRow->pack_start(*b_S, Gtk::PACK_SHRINK, 0);
    homeRow->pack_start(*b_D, Gtk::PACK_SHRINK, 0);
    homeRow->pack_start(*b_F, Gtk::PACK_SHRINK, 0);
    homeRow->pack_start(*b_G, Gtk::PACK_SHRINK, 0);
    homeRow->pack_start(*b_H, Gtk::PACK_SHRINK, 0);
    homeRow->pack_start(*b_J, Gtk::PACK_SHRINK, 0);
    homeRow->pack_start(*b_K, Gtk::PACK_SHRINK, 0);
    homeRow->pack_start(*b_L, Gtk::PACK_SHRINK, 0);

    bottomRow->pack_start(*b_Z, Gtk::PACK_SHRINK, 0);
    bottomRow->pack_start(*b_X, Gtk::PACK_SHRINK, 0);
    bottomRow->pack_start(*b_C, Gtk::PACK_SHRINK, 0);
    bottomRow->pack_start(*b_V, Gtk::PACK_SHRINK, 0);
    bottomRow->pack_start(*b_B, Gtk::PACK_SHRINK, 0);
    bottomRow->pack_start(*b_N, Gtk::PACK_SHRINK, 0);
    bottomRow->pack_start(*b_M, Gtk::PACK_SHRINK, 0);
    bottomRow->pack_start(*b_BKSP, Gtk::PACK_SHRINK, 0);

    keyboardBox->pack_start(*topRow, Gtk::PACK_SHRINK, 0);
    keyboardBox->pack_start(*homeRow, Gtk::PACK_SHRINK, 0);
    keyboardBox->pack_start(*bottomRow, Gtk::PACK_SHRINK, 0);
    keyboard = Gtk::manage(new Gtk::Box());
    keyboard->add(*keyboardBox);
}

void Main_Window::numpadSetup(std::string type) {
    // Flush the entry box every time we are ready for the keyboard
    flushEntry();

    Gtk::Box* numpadBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    Gtk::ButtonBox* topRow = Gtk::manage(new Gtk::ButtonBox());
    Gtk::ButtonBox* secondRow = Gtk::manage(new Gtk::ButtonBox());
    Gtk::ButtonBox* thirdRow = Gtk::manage(new Gtk::ButtonBox());
    Gtk::ButtonBox* bottomRow = Gtk::manage(new Gtk::ButtonBox());

    Gtk::Button* b_0 = Gtk::manage(new Gtk::Button("0"));
    Gtk::Button* b_00 = Gtk::manage(new Gtk::Button("00"));
    Gtk::Button* b_decimal = Gtk::manage(new Gtk::Button("."));

    Gtk::Button* b_1 = Gtk::manage(new Gtk::Button("1"));
    Gtk::Button* b_2 = Gtk::manage(new Gtk::Button("2"));
    Gtk::Button* b_3 = Gtk::manage(new Gtk::Button("3"));

    Gtk::Button* b_4 = Gtk::manage(new Gtk::Button("4"));
    Gtk::Button* b_5 = Gtk::manage(new Gtk::Button("5"));
    Gtk::Button* b_6 = Gtk::manage(new Gtk::Button("6"));

    Gtk::Button* b_7 = Gtk::manage(new Gtk::Button("7"));
    Gtk::Button* b_8 = Gtk::manage(new Gtk::Button("8"));
    Gtk::Button* b_9 = Gtk::manage(new Gtk::Button("9"));

    b_0->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::i0));
    b_00->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::i00));
    b_decimal->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::decimal));

    b_1->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::i1));
    b_2->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::i2));
    b_3->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::i3));

    b_4->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::i4));
    b_5->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::i5));
    b_6->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::i6));

    b_7->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::i7));
    b_8->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::i8));
    b_9->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::i9));
    
    topRow->pack_start(*b_7, Gtk::PACK_SHRINK, 0);
    topRow->pack_start(*b_8, Gtk::PACK_SHRINK, 0);
    topRow->pack_start(*b_9, Gtk::PACK_SHRINK, 0);

    secondRow->pack_start(*b_4, Gtk::PACK_SHRINK, 0);
    secondRow->pack_start(*b_5, Gtk::PACK_SHRINK, 0);
    secondRow->pack_start(*b_6, Gtk::PACK_SHRINK, 0);

    thirdRow->pack_start(*b_1, Gtk::PACK_SHRINK, 0);
    thirdRow->pack_start(*b_2, Gtk::PACK_SHRINK, 0);
    thirdRow->pack_start(*b_3, Gtk::PACK_SHRINK, 0);

    bottomRow->pack_start(*b_0, Gtk::PACK_SHRINK, 0);
    bottomRow->pack_start(*b_00, Gtk::PACK_SHRINK, 0);
    if (type == "INT") {
        b_decimal->set_sensitive(false);
        b_decimal->set_opacity(0.0);
    }
    bottomRow->pack_start(*b_decimal, Gtk::PACK_SHRINK, 0);

    numpadBox->pack_start(*topRow, Gtk::PACK_SHRINK, 0);
    numpadBox->pack_start(*secondRow, Gtk::PACK_SHRINK, 0);
    numpadBox->pack_start(*thirdRow, Gtk::PACK_SHRINK, 0);
    numpadBox->pack_start(*bottomRow, Gtk::PACK_SHRINK, 0);
    
    numpad = Gtk::manage(new Gtk::Box());
    numpad->add(*numpadBox);
}

void Main_Window::Q() {input += "Q"; entry->set_text(input);}
void Main_Window::W() {input += "W"; entry->set_text(input);}
void Main_Window::E() {input += "E"; entry->set_text(input);}
void Main_Window::R() {input += "R"; entry->set_text(input);}
void Main_Window::T() {input += "T"; entry->set_text(input);}
void Main_Window::Y() {input += "Y"; entry->set_text(input);}
void Main_Window::U() {input += "U"; entry->set_text(input);}
void Main_Window::I() {input += "I"; entry->set_text(input);}
void Main_Window::O() {input += "O"; entry->set_text(input);}
void Main_Window::P() {input += "P"; entry->set_text(input);}

void Main_Window::A() {input += "A"; entry->set_text(input);}
void Main_Window::S() {input += "S"; entry->set_text(input);}
void Main_Window::D() {input += "D"; entry->set_text(input);}
void Main_Window::F() {input += "F"; entry->set_text(input);}
void Main_Window::G() {input += "G"; entry->set_text(input);}
void Main_Window::H() {input += "H"; entry->set_text(input);}
void Main_Window::J() {input += "J"; entry->set_text(input);}
void Main_Window::K() {input += "K"; entry->set_text(input);}
void Main_Window::L() {input += "L"; entry->set_text(input);}

void Main_Window::Z() {input += "Z"; entry->set_text(input);}
void Main_Window::X() {input += "X"; entry->set_text(input);}
void Main_Window::C() {input += "C"; entry->set_text(input);}
void Main_Window::V() {input += "V"; entry->set_text(input);}
void Main_Window::B() {input += "B"; entry->set_text(input);}
void Main_Window::N() {input += "N"; entry->set_text(input);}
void Main_Window::M() {input += "M"; entry->set_text(input);}

void Main_Window::i0() {input += "0"; entry->set_text(input);}
void Main_Window::i00() {input += "00"; entry->set_text(input);}
void Main_Window::decimal() {input += "."; entry->set_text(input);}
void Main_Window::i1() {input += "1"; entry->set_text(input);}
void Main_Window::i2() {input += "2"; entry->set_text(input);}
void Main_Window::i3() {input += "3"; entry->set_text(input);}
void Main_Window::i4() {input += "4"; entry->set_text(input);}
void Main_Window::i5() {input += "5"; entry->set_text(input);}
void Main_Window::i6() {input += "6"; entry->set_text(input);}
void Main_Window::i7() {input += "7"; entry->set_text(input);}
void Main_Window::i8() {input += "8"; entry->set_text(input);}
void Main_Window::i9() {input += "9"; entry->set_text(input);}

void Main_Window::BKSP() {input.pop_back(); entry->set_text(input);}