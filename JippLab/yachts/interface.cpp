// UserInterface.cpp
#include "interface.h"
#include <iostream>
#include <fstream>
#include <json/json.h>

UserInterface::UserInterface(YachtPort& yachtPort) : yachtPort(yachtPort) {}

void UserInterface::run() {
    displayMenu();
}

void UserInterface::displayMenu() {
    int choice;

    do {
        std::cout << "\033[1;33mWelcome to Fancy YachtPort Console!\033[0m\n";
        std::cout << "\033[1;32m1. Yachts\033[0m\n";
        std::cout << "\033[1;34m2. Employees\033[0m\n";
        std::cout << "\033[1;36m3. Sailors\033[0m\n";
        std::cout << "\033[1;35m4. Reservations\033[0m\n";
        std::cout << "\033[1;31m5. Overall Data\033[0m\n";
        std::cout << "\033[1;37m6. Display Options\033[0m\n";
        std::cout << "\033[1;31m0. Exit\033[0m\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            displayYachtMenu();
            break;
        case 2:
            displayEmployeeMenu();
            break;
        case 3:
            displaySailorMenu();
            break;
        case 4:
            displayReservationMenu();
            break;
        case 5:
            displayDataManagementMenu();
            break;
        case 6:
            displayDisplayOptionsMenu();
            break;
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);
}


void UserInterface::displayDisplayOptionsMenu() const {
    // Implement the submenu for display options
}
