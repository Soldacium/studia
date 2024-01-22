
#include "interface.h"
#include <iostream>
#include <fstream>
#include <json/json.h>

void UserInterface::displayYachtMenu() const {
    int choice;

    do {
        std::cout << "\nYacht Menu:\n";
        std::cout << "1. Add Yacht\n";
        std::cout << "2. Remove Yacht\n";
        std::cout << "3. Display Yachts\n";
        std::cout << "0. Back to Main Menu\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            handleAddYacht();
            break;
        }
        case 2: {
            handleRemoveYacht();
            break;
        }
        case 3: {
            handleDisplayYachts();
            break;
        }
        case 0:
            std::cout << "Returning to Main Menu.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);
}

void UserInterface::handleAddYacht() {
    std::string name;
    double length;
    int maxPassengers;

    std::cout << "Enter Yacht Details:\n";
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Length: ";
    std::cin >> length;
    std::cout << "Max Passengers: ";
    std::cin >> maxPassengers;

    Yacht newYacht(name, length, maxPassengers);
    yachtPort += newYacht;
    std::cout << "Yacht added successfully.\n";
}

void UserInterface::handleRemoveYacht() {
    int yachtId;

    std::cout << "Enter Yacht ID to remove: ";
    std::cin >> yachtId;

    const Yacht* yachtToRemove = yachtPort.getYachtById(yachtId);

    if (yachtToRemove) {
        yachtPort -= *yachtToRemove;
        std::cout << "Yacht removed successfully.\n";
    }
    else {
        std::cout << "Yacht not found.\n";
    }
}

void UserInterface::handleDisplayYachts() const {
    const std::vector<Yacht>& yachtList = yachtPort.getYachtList();

    if (yachtList.empty()) {
        std::cout << "No yachts in the port.\n";
    }
    else {
        std::cout << "Yacht List:\n";
        for (const auto& yacht : yachtList) {
            std::cout << "ID: " << yacht.getId() << ", Name: " << yacht.getName()
                << ", Length: " << yacht.getLength() << ", Max Passengers: " << yacht.getMaxPassengers() << "\n";
        }
    }
}