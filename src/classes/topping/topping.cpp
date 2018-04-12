#include "topping.h"
#include <string>

std::string Topping::getType() {
    return "Topping";
}

std::string Topping::getAmount() {
    return m_amount;
}
