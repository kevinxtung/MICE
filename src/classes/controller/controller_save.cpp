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

    // People Portion
    std::vector<Customer> customers = data.getCustomers();
    std::vector<Server> servers = data.getServers();
    std::vector<Manager> managers = data.getManagers();
    std::vector<Owner> owners = data.getOwners();

    // Order Portion
    std::vector<Order> orders = data.getOrders();
    std::vector<Serving> servings;

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
    for (auto i : customers) {
        file << "Customer" << sep << i.getName() << sep << i.getPhone() <<
        std::endl;
    }
    for (auto i : servers) {
        file << "Server" << sep << i.getName() << sep << i.getPhone() <<
        sep << std::to_string(i.getOrders()) << sep << std::to_string(i.getSalary()) <<
        std::endl;
    }
    for (auto i : managers) {
        file << "Manager" << sep << i.getName() << sep << i.getPhone() <<
        std::endl;
    }
    for (auto i : owners) {
        file << "Owner" << sep << i.getName() << sep << i.getPhone() <<
        std::endl;
    }
    for (auto i : orders) {
        file << "Order" << sep <<  std::to_string(i.getID()) << sep << i.getStatus() <<
        sep << i.getName() << sep;
        servings = i.getServings();
        for (auto i : servings) {
            auto container = i.getContainer();
            std::vector<Scoop> scoops = i.getScoops();
            std::vector<Topping> toppings = i.getToppings();
            file << "Serving" << sep << container.getName() << sep;
            file << "Scoops" << sep;
            for (auto i : scoops) {
                file << i.getName() << sep;
            }
            file << "Toppings" << sep;
            for (auto i : toppings) {
                file << i.getName() << sep;
            }
        }
        file << "!FINISH" << sep << std::endl;
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
            case 5: {   // Customer Load
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                std::string name = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                std::string number = token;
                m_emporium.addCustomer(Customer(name, number));
                break;
            }
            case 6: {   // Server Load
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                std::string name = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                std::string number = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                std::string orders = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                std::string salary = token;
                m_emporium.addServer(Server(name, number, std::stod(salary), std::stoi(orders)));
                break;
            }
            case 7: {   // Manager Load
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                std::string name = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                std::string number = token;
                m_emporium.addManager(Manager(name, number));
                break;
            }
            case 8: {   // Owner Load
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                std::string name = token;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                std::string number = token;
                m_emporium.addOwner(Owner(name, number));
                break;
            }
            case 9: {   // Order Load
                Order order;
                Serving serving;
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                std::string ID = token;
                order.setID(std::stoi(ID));
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                std::string status = token;
                order.setStatus(status);
                line = line.substr(line.find(delimiter) + delimiter.length());
                token = line.substr(0, line.find(delimiter));
                std::string name = token;
                order.setName(name);
                while (token != "!FINISH") {
                    if (token != "Serving") {
                        line = line.substr(line.find(delimiter) + delimiter.length());
                        token = line.substr(0, line.find(delimiter));
                    }
                    if (token == "Serving") {
                        line = line.substr(line.find(delimiter) + delimiter.length());
                        token = line.substr(0, line.find(delimiter));
                        std::vector<Container> containers = m_emporium.getContainers();
                        for (auto i : containers) {
                            if (i.getName() == token) {
                                serving.setContainer(i);
                                break;
                            }
                        }
                        line = line.substr(line.find(delimiter) + delimiter.length());
                        token = line.substr(0, line.find(delimiter));
                        if (token == "Scoops") {
                            std::vector<Scoop> scoops = m_emporium.getScoops();
                            while (token != "Toppings") {
                                line = line.substr(line.find(delimiter) + delimiter.length());
                                token = line.substr(0, line.find(delimiter));
                                for (auto i : scoops) {
                                    if (i.getName() == token) {
                                        serving.addScoop(i);
                                        break;
                                    }
                                }
                            }
                            std::vector<Topping> toppings = m_emporium.getToppings();
                            while (token != "!FINISH" && token != "Serving") {
                                line = line.substr(line.find(delimiter) + delimiter.length());
                                token = line.substr(0, line.find(delimiter));
                                for (auto i : toppings) {
                                    if (i.getName() == token) {
                                        serving.addTopping(i);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    order.addServing(serving);
                    while (serving.getScoops().size() > 0) {
                        serving.removeScoop();
                    }
                    while (!serving.getToppings().empty()) {
                        serving.removeTopping();
                    }
                }
                m_emporium.addOrder(order);
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
    if (token == "Balance") return eBalance;    // 0
    if (token == "Container") return eContainer;
    if (token == "Scoop") return eScoop;
    if (token == "Topping") return eTopping;
    if (token == "ID") return eID;
    if (token == "Customer") return eCustomer;  // 5
    if (token == "Server") return eServer;
    if (token == "Manager") return eManager;
    if (token == "Owner") return eOwner;
    if (token == "Order") return eOrder;
    if (token == "Serving") return eServing;    // 10
}