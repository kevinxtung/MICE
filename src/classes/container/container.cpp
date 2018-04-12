#include "container.h"

std::string Container::getType() {
    return "Container";
}

int Container::getMaxScoops() {
    return m_maxScoops;
}
