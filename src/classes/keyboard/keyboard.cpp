#include "keyboard.h"

// Static Variable Initialization
std::string Keyboard::m_buffer = "";
Gtk::Entry* Keyboard::m_entry = NULL;

Keyboard::Keyboard() {
    m_entry = Gtk::manage(new Gtk::Entry());
    m_keyboard = Gtk::manage(new Gtk::Box());
    m_buffer = "";
}

Keyboard::Keyboard(std::string style) : Keyboard() {
    m_keyboard = generate(style);
}

Gtk::Box* Keyboard::getKeyboard() {return m_keyboard;}
Gtk::Entry* Keyboard::getEntry() {return m_entry;}
std::string Keyboard::getBuffer() {return m_buffer;}
void Keyboard::clearBuffer() {m_buffer = ""; m_entry->set_text(m_buffer);}

// Generates a usable keyboard based on the input style.
/*
    Valid styles include:
    "ALPHA": Alphabetical letters, along with spacebar and uppercase functionality.
    "DIGIT": A numerical numpad, along with a decimal symbol.
    "FULL": A keyboard, a numpad, and all special characters.
*/

Gtk::Box* Keyboard::generate(std::string style) {
    
    // Box to be returned. keyboardBox will stack Gtk::ButtonBoxes vertically.
    Gtk::Box* keyboardBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    
    if (style == "ALPHA") {
        Gtk::ButtonBox* topRow = Gtk::manage(new Gtk::ButtonBox());    
        Gtk::ButtonBox* homeRow = Gtk::manage(new Gtk::ButtonBox());    
        Gtk::ButtonBox* bottomRow = Gtk::manage(new Gtk::ButtonBox());
        Gtk::Button* b_space = Gtk::manage(new Gtk::Button("            "));


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
        
        b_Q->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::Q));
        b_W->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::W));
        b_E->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::E));
        b_R->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::R));
        b_T->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::T));
        b_Y->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::Y));
        b_U->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::U));
        b_I->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::I));
        b_O->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::O));
        b_P->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::P));

        b_A->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::A));
        b_S->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::S));
        b_D->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::D));
        b_F->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::F));
        b_G->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::G));
        b_H->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::H));
        b_J->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::J));
        b_K->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::K));
        b_L->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::L));

        b_Z->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::Z));
        b_X->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::X));
        b_C->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::C));
        b_V->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::V));
        b_B->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::B));
        b_N->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::N));
        b_M->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::M));
        b_BKSP->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::BKSP));

        b_space->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::space));

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
        keyboardBox->pack_start(*b_space, Gtk::PACK_SHRINK, 0);

        return keyboardBox;
    }
    if (style == "DIGIT") {
        Gtk::ButtonBox* topRow = Gtk::manage(new Gtk::ButtonBox());
        Gtk::ButtonBox* secondRow = Gtk::manage(new Gtk::ButtonBox());
        Gtk::ButtonBox* thirdRow = Gtk::manage(new Gtk::ButtonBox());
        Gtk::ButtonBox* bottomRow = Gtk::manage(new Gtk::ButtonBox());

        Gtk::Button* b_0 = Gtk::manage(new Gtk::Button("0"));
        Gtk::Button* b_00 = Gtk::manage(new Gtk::Button("00"));
        Gtk::Button* b_decimal = Gtk::manage(new Gtk::Button("."));
        Gtk::Button* b_dash = Gtk::manage(new Gtk::Button("-"));
        Gtk::Button* b_BKSP = Gtk::manage(new Gtk::Button("<"));


        Gtk::Button* b_1 = Gtk::manage(new Gtk::Button("1"));
        Gtk::Button* b_2 = Gtk::manage(new Gtk::Button("2"));
        Gtk::Button* b_3 = Gtk::manage(new Gtk::Button("3"));

        Gtk::Button* b_4 = Gtk::manage(new Gtk::Button("4"));
        Gtk::Button* b_5 = Gtk::manage(new Gtk::Button("5"));
        Gtk::Button* b_6 = Gtk::manage(new Gtk::Button("6"));

        Gtk::Button* b_7 = Gtk::manage(new Gtk::Button("7"));
        Gtk::Button* b_8 = Gtk::manage(new Gtk::Button("8"));
        Gtk::Button* b_9 = Gtk::manage(new Gtk::Button("9"));

        //b_0->signal_clicked().connect(sigc::ptr_fun(&i0));
        b_0->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i0));
        b_00->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i00));
        b_decimal->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::decimal));
        b_dash->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::dash));
        b_BKSP->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::BKSP));


        b_1->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i1));
        b_2->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i2));
        b_3->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i3));

        b_4->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i4));
        b_5->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i5));
        b_6->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i6));

        b_7->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i7));
        b_8->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i8));
        b_9->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i9));
        
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
        bottomRow->pack_start(*b_decimal, Gtk::PACK_SHRINK, 0);

        keyboardBox->pack_start(*topRow, Gtk::PACK_SHRINK, 0);
        keyboardBox->pack_start(*secondRow, Gtk::PACK_SHRINK, 0);
        keyboardBox->pack_start(*thirdRow, Gtk::PACK_SHRINK, 0);
        keyboardBox->pack_start(*bottomRow, Gtk::PACK_SHRINK, 0);

        return keyboardBox;
    }
}

void Keyboard::Q() {m_buffer += "Q"; m_entry->set_text(m_buffer);}
void Keyboard::W() {m_buffer += "W"; m_entry->set_text(m_buffer);}
void Keyboard::E() {m_buffer += "E"; m_entry->set_text(m_buffer);}
void Keyboard::R() {m_buffer += "R"; m_entry->set_text(m_buffer);}
void Keyboard::T() {m_buffer += "T"; m_entry->set_text(m_buffer);}
void Keyboard::Y() {m_buffer += "Y"; m_entry->set_text(m_buffer);}
void Keyboard::U() {m_buffer += "U"; m_entry->set_text(m_buffer);}
void Keyboard::I() {m_buffer += "I"; m_entry->set_text(m_buffer);}
void Keyboard::O() {m_buffer += "O"; m_entry->set_text(m_buffer);}
void Keyboard::P() {m_buffer += "P"; m_entry->set_text(m_buffer);}

void Keyboard::A() {m_buffer += "A"; m_entry->set_text(m_buffer);}
void Keyboard::S() {m_buffer += "S"; m_entry->set_text(m_buffer);}
void Keyboard::D() {m_buffer += "D"; m_entry->set_text(m_buffer);}
void Keyboard::F() {m_buffer += "F"; m_entry->set_text(m_buffer);}
void Keyboard::G() {m_buffer += "G"; m_entry->set_text(m_buffer);}
void Keyboard::H() {m_buffer += "H"; m_entry->set_text(m_buffer);}
void Keyboard::J() {m_buffer += "J"; m_entry->set_text(m_buffer);}
void Keyboard::K() {m_buffer += "K"; m_entry->set_text(m_buffer);}
void Keyboard::L() {m_buffer += "L"; m_entry->set_text(m_buffer);}

void Keyboard::Z() {m_buffer += "Z"; m_entry->set_text(m_buffer);}
void Keyboard::X() {m_buffer += "X"; m_entry->set_text(m_buffer);}
void Keyboard::C() {m_buffer += "C"; m_entry->set_text(m_buffer);}
void Keyboard::V() {m_buffer += "V"; m_entry->set_text(m_buffer);}
void Keyboard::B() {m_buffer += "B"; m_entry->set_text(m_buffer);}
void Keyboard::N() {m_buffer += "N"; m_entry->set_text(m_buffer);}
void Keyboard::M() {m_buffer += "M"; m_entry->set_text(m_buffer);}

void Keyboard::space() {m_buffer += " "; m_entry->set_text(m_buffer);}


void Keyboard::i0() {m_buffer += "0"; m_entry->set_text(m_buffer);}
void Keyboard::i00() {m_buffer += "00"; m_entry->set_text(m_buffer);}
void Keyboard::decimal() {m_buffer += "."; m_entry->set_text(m_buffer);}
void Keyboard::dash() {m_buffer += "-"; m_entry->set_text(m_buffer);}
void Keyboard::i1() {m_buffer += "1"; m_entry->set_text(m_buffer);}
void Keyboard::i2() {m_buffer += "2"; m_entry->set_text(m_buffer);}
void Keyboard::i3() {m_buffer += "3"; m_entry->set_text(m_buffer);}
void Keyboard::i4() {m_buffer += "4"; m_entry->set_text(m_buffer);}
void Keyboard::i5() {m_buffer += "5"; m_entry->set_text(m_buffer);}
void Keyboard::i6() {m_buffer += "6"; m_entry->set_text(m_buffer);}
void Keyboard::i7() {m_buffer += "7"; m_entry->set_text(m_buffer);}
void Keyboard::i8() {m_buffer += "8"; m_entry->set_text(m_buffer);}
void Keyboard::i9() {m_buffer += "9"; m_entry->set_text(m_buffer);}

void Keyboard::BKSP() {m_buffer.pop_back();}

/*
Keyboard::Keyboard(std::string style) {
    // Flush the entry box every time we are ready for the keyboard
    flushBuffer();
    if (style == "TEXT") {
        Gtk::Box* keyboardBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
        Gtk::ButtonBox* topRow = Gtk::manage(new Gtk::ButtonBox());    
        Gtk::ButtonBox* homeRow = Gtk::manage(new Gtk::ButtonBox());    
        Gtk::ButtonBox* bottomRow = Gtk::manage(new Gtk::ButtonBox());
        Gtk::Button* b_space = Gtk::manage(new Gtk::Button("            "));


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
        
        b_Q->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::Q));
        b_W->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::W));
        b_E->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::E));
        b_R->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::R));
        b_T->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::T));
        b_Y->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::Y));
        b_U->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::U));
        b_I->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::I));
        b_O->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::O));
        b_P->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::P));

        b_A->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::A));
        b_S->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::S));
        b_D->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::D));
        b_F->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::F));
        b_G->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::G));
        b_H->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::H));
        b_J->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::J));
        b_K->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::K));
        b_L->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::L));

        b_Z->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::Z));
        b_X->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::X));
        b_C->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::C));
        b_V->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::V));
        b_B->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::B));
        b_N->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::N));
        b_M->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::M));
        b_BKSP->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::BKSP));

        b_space->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::space));

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
        keyboardBox->pack_start(*b_space, Gtk::PACK_SHRINK, 0);

        add(*keyboardBox);
    }
    else {
        flushBuffer();

        Gtk::Box* keyboardBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
        Gtk::ButtonBox* topRow = Gtk::manage(new Gtk::ButtonBox());
        Gtk::ButtonBox* secondRow = Gtk::manage(new Gtk::ButtonBox());
        Gtk::ButtonBox* thirdRow = Gtk::manage(new Gtk::ButtonBox());
        Gtk::ButtonBox* bottomRow = Gtk::manage(new Gtk::ButtonBox());

        Gtk::Button* b_0 = Gtk::manage(new Gtk::Button("0"));
        Gtk::Button* b_00 = Gtk::manage(new Gtk::Button("00"));
        Gtk::Button* b_decimal = Gtk::manage(new Gtk::Button("."));
        Gtk::Button* b_dash = Gtk::manage(new Gtk::Button("-"));
        Gtk::Button* b_BKSP = Gtk::manage(new Gtk::Button("<"));


        Gtk::Button* b_1 = Gtk::manage(new Gtk::Button("1"));
        Gtk::Button* b_2 = Gtk::manage(new Gtk::Button("2"));
        Gtk::Button* b_3 = Gtk::manage(new Gtk::Button("3"));

        Gtk::Button* b_4 = Gtk::manage(new Gtk::Button("4"));
        Gtk::Button* b_5 = Gtk::manage(new Gtk::Button("5"));
        Gtk::Button* b_6 = Gtk::manage(new Gtk::Button("6"));

        Gtk::Button* b_7 = Gtk::manage(new Gtk::Button("7"));
        Gtk::Button* b_8 = Gtk::manage(new Gtk::Button("8"));
        Gtk::Button* b_9 = Gtk::manage(new Gtk::Button("9"));

        b_0->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i0));
        b_00->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i00));
        b_decimal->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::decimal));
        b_dash->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::dash));
        b_BKSP->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::BKSP));


        b_1->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i1));
        b_2->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i2));
        b_3->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i3));

        b_4->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i4));
        b_5->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i5));
        b_6->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i6));

        b_7->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i7));
        b_8->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i8));
        b_9->signal_clicked().connect(sigc::mem_fun(*this, &Keyboard::i9));
        
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
        if (style == "INT") {
            bottomRow->pack_start(*b_BKSP, Gtk::PACK_SHRINK, 0);
        }
        if (style == "NUMBER") {
            bottomRow->pack_start(*b_dash, Gtk::PACK_SHRINK, 0);
        }
        if (style == "DOUBLE") {
            bottomRow->pack_start(*b_decimal, Gtk::PACK_SHRINK, 0);
        }

        keyboardBox->pack_start(*topRow, Gtk::PACK_SHRINK, 0);
        keyboardBox->pack_start(*secondRow, Gtk::PACK_SHRINK, 0);
        keyboardBox->pack_start(*thirdRow, Gtk::PACK_SHRINK, 0);
        keyboardBox->pack_start(*bottomRow, Gtk::PACK_SHRINK, 0);
        
        keyboard = Gtk::manage(new Gtk::Box());
        keyboard->add(*keyboardBox);
    }
}


*/