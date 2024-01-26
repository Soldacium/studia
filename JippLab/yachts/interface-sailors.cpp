
#include "interface.h"
#include <iostream>
#include <fstream>
#include <json/json.h>


void UserInterface::displaySailorMenu() {
    int choice;

    do {
        std::cout << "\nSailor Menu:\n";
        std::cout << "1. Add Sailor\n";
        std::cout << "2. Remove Sailor\n";
        std::cout << "3. Display Sailors\n";
        std::cout << "0. Back to Main Menu\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            handleAddSailor();
            break;
        }
        case 2: {
            handleRemoveSailor();
            break;
        }
        case 3: {
            handleDisplaySailors();
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

void UserInterface::handleAddSailor() {
    std::string firstName, lastName;

    std::cout << "Enter Sailor Details:\n";
    std::cout << "First Name: ";
    std::cin >> firstName;
    std::cout << "Last Name: ";
    std::cin >> lastName;

    Sailor newSailor("2000-12-12",firstName, lastName, std::vector<int>());
    yachtPort += newSailor;
    std::cout << "Sailor added successfully.\n";
}

void UserInterface::handleRemoveSailor() {
    std::string firstName, lastName;

    std::cout << "Enter Sailor Name to remove: ";
    std::cout << "First Name: ";
    std::cin >> firstName;
    std::cout << "Last Name: ";
    std::cin >> lastName;
    const Sailor* sailorToRemove = yachtPort.getSailorByName(firstName, lastName);

    if (sailorToRemove) {
        yachtPort -= *sailorToRemove;
        std::cout << "Sailor removed successfully.\n";
    }
    else {
        std::cout << "Sailor not found.\n";
    }
}

void UserInterface::handleDisplaySailors() const {
    const std::vector<Sailor>& sailorList = yachtPort.getSailors();

    if (sailorList.empty()) {
        std::cout << "No sailors in the port.\n";
    }
    else {
        std::cout << "Sailor List:\n";
        for (const Sailor& sailor : sailorList) {
            std::cout << "Name: " << sailor.getName() << " " << sailor.getSurname() << "\n";
        }
    }
}