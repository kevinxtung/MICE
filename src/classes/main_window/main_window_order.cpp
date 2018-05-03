#include "main_window.h"

// Uninitialized State is -1
// Shows position end-user is at with screens.
int position = -1; // 1 is containers, 2 is scoops, 3 is toppings. 0 is main.

Serving serving;
Order order;

const double X_PAD = 80.0;
const double Y_PAD = 20.0;

bool full; // For determining container fullness.
int amount; // For determining topping amount.
void Main_Window::orderScreen() {
    clean();

    Gtk::Grid *grid = Gtk::manage(new Gtk::Grid());

    // Custom Dialog Box
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    
    // Custom Picture Box
    Gtk::Box *pbox = Gtk::manage(new Gtk::Box());
    Gtk::Image *i_placeholder = Gtk::manage(new Gtk::Image("placeholder.png"));
    pbox->add(*i_placeholder);

    // Status Bar
    Gtk::Box *status = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
    Gtk::Label *container = Gtk::manage(new Gtk::Label());
    Gtk::Label *scoops = Gtk::manage(new Gtk::Label());
    Gtk::Label *toppings = Gtk::manage(new Gtk::Label());
    container->set_markup("<span font='18'>Container</span>");
    scoops->set_markup("<span font='18'>Scoops</span>");
    toppings->set_markup("<span font='18'>Toppings</span>");

    container->set_padding(X_PAD, Y_PAD);
    scoops->set_padding(X_PAD, Y_PAD);
    toppings->set_padding(X_PAD, Y_PAD);

    // Back, Next, and Finish Buttons
    Gtk::Grid *gridButtons = Gtk::manage(new Gtk::Grid()); // Grid declared for buttons

    Gtk::Image *i_back = Gtk::manage(new Gtk::Image{"back.png"});
    Gtk::Button *b_back = Gtk::manage(new Gtk::Button());
    b_back->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onOrderBackClick));
    b_back->set_image(*i_back);

    Gtk::Image *i_next = Gtk::manage(new Gtk::Image{"next.png"});
    Gtk::Button *b_next = Gtk::manage(new Gtk::Button());
    b_next->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onOrderNextClick));
    b_next->set_image(*i_next);

    Gtk::Image *i_finishOrder = Gtk::manage(new Gtk::Image{"finishorder.png"});
    Gtk::Button *b_finishOrder = Gtk::manage(new Gtk::Button());
    b_finishOrder->signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::onOrderFinishClick));
    b_finishOrder->set_image(*i_finishOrder);

    // Switch that draws GUI based on current position in creating a serving.
    switch (position) {
        case 0: // User wants to exit.
            defaultScreen();
            break;
        case 1: // User is selecting containers.
            showContainers();
            container->set_markup("<span weight='bold' font='18'>Container</span>");
            i_back = Gtk::manage(new Gtk::Image{"returntostart.png"});
            b_back->set_image(*i_back);
            break;
        case 2: // User is selecting scoops.
            showScoops();
            scoops->set_markup("<span weight='bold' font='18'>Scoops</span>");
            break;
        case 3: // User is selecting toppings.
            showToppings();
            toppings->set_markup("<span weight='bold' font='18'>Toppings</span>");
            i_next = Gtk::manage(new Gtk::Image{"addtoorder.png"});
            b_next->set_image(*i_next);
            gridButtons->attach(*b_finishOrder, 2, 0, 1, 1);
            b_finishOrder->set_sensitive(true);
            b_finishOrder->set_opacity(1.0);
            break;
    }
    
    // Status Packing, done after the switch to allow bolding.
    status->pack_start(*container, Gtk::PACK_SHRINK, 0);
    status->pack_start(*scoops, Gtk::PACK_SHRINK, 0);
    status->pack_start(*toppings, Gtk::PACK_SHRINK, 0);

    // Grid Packing, done after switch to allow image text changes.
    gridButtons->attach(*b_back, 0, 0, 1, 1);
    gridButtons->attach(*b_next, 1, 0, 1, 1);
    if (position != 3) {
        gridButtons->attach(*b_finishOrder, 2, 0, 1, 1);
        b_finishOrder->set_sensitive(false);
        b_finishOrder->set_opacity(0.0);
    }

    // Dialog Assembly
    vbox->pack_start(*status, Gtk::PACK_SHRINK, 0);
    vbox->pack_start(*selections, Gtk::PACK_SHRINK, 0);
    vbox->pack_end(*gridButtons, Gtk::PACK_SHRINK, 0);
    
    grid->set_row_homogeneous(true);
    grid->set_column_homogeneous(true);
    Gtk::Box *blank = Gtk::manage(new Gtk::Box());
    Gtk::Box *blank2 = Gtk::manage(new Gtk::Box());
    grid->attach(*blank, 0, 0, 1, 1);
    grid->attach(*pbox, 1, 1, 5, 7);
    grid->attach(*vbox, 7, 1, 8, 7);
    grid->attach(*blank2, 15, 8, 1, 1);
    
    box->add(*grid);
    mainbox->add(*box);
    mainbox->show_all();
}

void Main_Window::showContainers() {
    // Container Style and Size Selection
    selections = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));

    Gtk::Label *style = Gtk::manage(new Gtk::Label());
    style->set_markup("<span weight='bold' font='20'>Choose a Container</span>");
    Gtk::ButtonBox *styleButtons = Gtk::manage(new Gtk::ButtonBox());
    styleButtons->set_layout(Gtk::BUTTONBOX_START);
    int x = 100000; // Containers start at 100000
    for (auto i : m_controller->getEmporium().getContainers()) {
        Gtk::Button *b_styleButton = Gtk::manage(new Gtk::Button());
        b_styleButton->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_Window::onOrderDynamicClick), x));
        b_styleButton->set_image(*(i.getImage()));
        styleButtons->pack_start(*b_styleButton, Gtk::PACK_SHRINK, 0);
        x++;
    } 
    /* STRETCH GOAL
    Gtk::Label *size = Gtk::manage(new Gtk::Label("Size"));
    Gtk::ButtonBox *sizeButtons = Gtk::manage(new Gtk::ButtonBox());
    */
    selections->pack_start(*style, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*styleButtons, Gtk::PACK_SHRINK, 0);
    /* STRETCH GOAL
    selections->pack_start(*size, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*sizeButtons, Gtk::PACK_SHRINK, 0);
    */
}

void Main_Window::showScoops() {
    // Container Style and Size Selection
    selections = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));

    Gtk::Label *style = Gtk::manage(new Gtk::Label());
    style->set_markup("<span weight='bold' font='20'>Tap to add a Scoop</span>");
    Gtk::ButtonBox *styleButtons = Gtk::manage(new Gtk::ButtonBox());
    styleButtons->set_layout(Gtk::BUTTONBOX_START);
    int x = 200000; // Scoops start at 200000
    for (auto i : m_controller->getEmporium().getScoops()) {
        Gtk::Button *b_styleButton = Gtk::manage(new Gtk::Button());
        b_styleButton->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_Window::onOrderDynamicClick), x));
        b_styleButton->set_image(*(i.getImage()));
        if (full) {
            b_styleButton->set_sensitive(false);
        }
        else {
            b_styleButton->set_sensitive(true);
        }
        styleButtons->pack_start(*b_styleButton, Gtk::PACK_SHRINK, 0);
        x++;
    }
    /* STRETCH GOAL
    Gtk::Label *size = Gtk::manage(new Gtk::Label("Size"));
    Gtk::ButtonBox *sizeButtons = Gtk::manage(new Gtk::ButtonBox());
    */
    selections->pack_start(*style, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*styleButtons, Gtk::PACK_SHRINK, 0);
    /* STRETCH GOAL
    selections->pack_start(*size, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*sizeButtons, Gtk::PACK_SHRINK, 0);
    */
}

void Main_Window::showToppings() {
    // Container Style and Size Selection
    selections = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));

    Gtk::Label *topping = Gtk::manage(new Gtk::Label());
    topping->set_markup("<span weight='bold' font='20'>Tap to add a Topping</span>");
    Gtk::ButtonBox *toppingButtons = Gtk::manage(new Gtk::ButtonBox());
    toppingButtons->set_layout(Gtk::BUTTONBOX_START);

    int x = 300000; // Toppings start at 300000
    for (auto i : m_controller->getEmporium().getToppings()) {
        Gtk::Button *b_toppingButton = Gtk::manage(new Gtk::Button());
        b_toppingButton->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &Main_Window::onOrderDynamicClick), x));
        b_toppingButton->set_image(*(i.getImage()));

        toppingButtons->pack_start(*b_toppingButton, Gtk::PACK_SHRINK, 0);
        x++;
    } 

    Gtk::Label *amount = Gtk::manage(new Gtk::Label());
    amount->set_markup("<span weight='bold' font='20'>Customize Amount</span>");
    Gtk::ButtonBox *amountButtons = Gtk::manage(new Gtk::ButtonBox());
    //amountButtons->set_layout(Gtk::BUTTONBOX_START);
    Gtk::Button *b_none = Gtk::manage(new Gtk::Button("None"));
    Gtk::Button *b_light = Gtk::manage(new Gtk::Button("Light"));
    Gtk::Button *b_normal = Gtk::manage(new Gtk::Button("Normal"));
    Gtk::Button *b_extra = Gtk::manage(new Gtk::Button("Extra"));
    Gtk::Button *b_drenched = Gtk::manage(new Gtk::Button("Drenched"));
    amountButtons->pack_start(*b_none, Gtk::PACK_SHRINK, 0);
    amountButtons->pack_start(*b_light, Gtk::PACK_SHRINK, 0);
    amountButtons->pack_start(*b_normal, Gtk::PACK_SHRINK, 0);
    amountButtons->pack_start(*b_extra, Gtk::PACK_SHRINK, 0);
    amountButtons->pack_start(*b_drenched, Gtk::PACK_SHRINK, 0);

    selections->pack_start(*topping, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*toppingButtons, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*amount, Gtk::PACK_SHRINK, 0);
    selections->pack_start(*amountButtons, Gtk::PACK_SHRINK, 0);
}

void Main_Window::onOrderDynamicClick(int button) {
    std::cout << "callback id " << button << std::endl;
    if (button < 200000) {      // Container Callback
        //std::vector<Container::Container> containers = m_controller->getEmporium().getContainers();
        serving.setContainer((m_controller->getEmporium().getContainers())[button-100000]);
        while (serving.getScoops().size() > 0) {
            serving.removeScoop();
        }
        full = false;
    }
    else if (button < 300000){  // Scoop Callback
        std::vector<Scoop> scoops = m_controller->getEmporium().getScoops();
        // Check to see the container is not full
        serving.addScoop(scoops[button-200000]);
        if (serving.getScoops().size() >= serving.getContainer().getMaxScoops()) {
            full = true;
            orderScreen(); // Update the order screen.
        }
        else {
            full = false;
            orderScreen();
        }
    }
    else {                      // Topping Callback
        std::vector<Topping> toppings = m_controller->getEmporium().getToppings();
        //toppings[button-300000].setAmount()
        serving.addTopping(toppings[button-300000]);
    }
}

void Main_Window::onOrderBackClick() {
    position--;
    if (position <= 0) {
        defaultScreen();
    }
    else {
        orderScreen();
    }
}

void Main_Window::onOrderNextClick() {
    position++;
    if (position >= 4) {
        order.addServing(serving);
        flushServing();
        position = 1;
        orderScreen();
    }
    else {
        orderScreen();
    }
}

void Main_Window::onOrderFinishClick() {
    // ADD something to force selecting cone, cream, and top.
    order.addServing(serving);
    flushServing();
    order.setID(m_controller->getEmporium().getNextID());
    m_controller->getEmporium().addOrder(order);
    flushOrder();
    finalizeScreen();
}

void Main_Window::flushServing() {
    while (!serving.getScoops().empty()) {
        serving.removeScoop();
    }
    full = false;
    while (!serving.getToppings().empty()) {
        serving.removeTopping();
    }
}

void Main_Window::flushOrder() {
    while (!order.getServings().empty()) {
        order.removeServing();
    }
}