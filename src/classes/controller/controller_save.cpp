#include "controller.h"

#include <fstream>

#include <iostream>

void Controller::save() {
    std::ofstream file;
    file.open("emporium.data");
    std::string sep = ",,";
    Emporium data = getEmporium();

    // Balance Portion
    std::string balance = std::to_string(data.getBalance());
    file << "Balance" << sep << balance << std::endl;

    // ID Portion
    std::string ID = std::to_string(data.getCurrentID());
    file << "ID" << sep << ID << std::endl;

    // Items Portion
    std::vector<Container> containers = data.getContainers();
    std::vector<Scoop> scoops = data.getScoops();
    std::vector<Topping> toppings = data.getToppings();
    for (auto i : containers) {
        file << i.getType() << sep << i.getName() << sep << i.getDescription() <<
        sep << std::to_string(i.getRawCost()) << sep << std::to_string(i.getRetailPrice()) <<
        sep << std::to_string(i.getQuantity()) << sep << std::to_string(i.getMaxScoops()) <<
        std::endl;
    }
    for (auto i : scoops) {
        file << i.getType() << sep << i.getName() << sep << i.getDescription() <<
        sep << std::to_string(i.getRawCost()) << sep << std::to_string(i.getRetailPrice()) <<
        sep << std::to_string(i.getQuantity()) <<
        std::endl;
    }
    for (auto i : toppings) {
        file << i.getType() << sep << i.getName() << sep << i.getDescription() <<
        sep << std::to_string(i.getRawCost()) << sep << std::to_string(i.getRetailPrice()) <<
        sep << std::to_string(i.getQuantity()) << sep << i.getAmount() <<
        std::endl;
    }
    file.close();
}

void Controller::load() {
    std::string line, token, delimiter = ",,";
    std::string name, description, rawCost, retailPrice, quantity, uniqueArg;
    size_t pos = 0;
    std::ifstream file("emporium.data");
    while (std::getline(file, line)) {
        token = line.substr(0, line.find(delimiter));
        switch (hashToken(token)) {
            case 0: {   // Balance Load
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                m_emporium.setBalance(std::stod(token));
                break;
            }
            case 1: {   // Container Load
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                name = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                description = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                rawCost = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                retailPrice = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                quantity = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                uniqueArg = token;

                m_emporium.addContainer(Container(name, description, std::stod(rawCost), std::stod(retailPrice), std::stoi(quantity), std::stoi(uniqueArg)));
                break;
            }
            case 2: {   // Scoop Load
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                name = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                description = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                rawCost = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                retailPrice = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                quantity = token;

                m_emporium.addScoop(Scoop(name, description, std::stod(rawCost), std::stod(retailPrice), std::stoi(quantity)));
                break;
            }
            case 3: {   // Topping Load
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                name = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                description = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                rawCost = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                retailPrice = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                quantity = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                uniqueArg = token;

                m_emporium.addTopping(Topping(name, description, std::stod(rawCost), std::stod(retailPrice), std::stoi(quantity), uniqueArg));
                break;
            }
            case 4: {   // ID Load
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                m_emporium.setID(std::stod(token));
                break;
            }
            default: {
                while ((pos = line.find(delimiter)) != std::string::npos) {
                    token = line.substr(0, pos);
                    std::cout << token << std::endl;
                    line = line.substr(pos + delimiter.length());
                }
            }
        }

    }
    file.close();
}

Controller::tokenCode Controller::hashToken(std::string token) {
    if (token == "Balance") return eBalance;
    if (token == "Container") return eContainer;
    if (token == "Scoop") return eScoop;
    if (token == "Topping") return eTopping;
    if (token == "ID") return eID;
    if (token == "Customer") return eCustomer;
    if (token == "Server") return eServer;
    if (token == "Manager") return eManager;
    if (token == "Owner") return eOwner;
    if (token == "Order") return eOrder;
    if (token == "Serving") return eServing;
}