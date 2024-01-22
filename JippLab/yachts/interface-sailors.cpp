
#include "interface.h"
#include <iostream>
#include <fstream>
#include <json/json.h>


void UserInterface::displaySailorMenu() const {
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
            // Add Sailor
            std::string firstName, lastName;
            std::cout << "Enter the first name of the sailor: ";
            std::cin >> firstName;
            std::cout << "Enter the last name of the sailor: ";
            std::cin >> lastName;

            // Create a sailor object (you may need additional input)
            Sailor newSailor(firstName, lastName);

            // Add the sailor to the yacht port
            yachtPort.addSailor(newSailor);

            std::cout << "Sailor added successfully.\n";
            break;
        }
        case 2: {
            // Remove Sailor
            std::string firstName, lastName;
            std::cout << "Enter the first name of the sailor to remove: ";
            std::cin >> firstName;
            std::cout << "Enter the last name of the sailor to remove: ";
            std::cin >> lastName;

            // Remove the sailor from the yacht port
            yachtPort.removeSailor(firstName, lastName);

            std::cout << "Sailor removed successfully.\n";
            break;
        }
        case 3: {
            // Display Sailors
            const std::vector<Sailor>& sailorList = yachtPort.getSailorList();

            if (sailorList.empty()) {
                std::cout << "No sailors available.\n";
            }
            else {
                std::cout << "Sailor List:\n";
                for (const auto& sailor : sailorList) {
                    std::cout << "Name: " << sailor.getFullName() << "\n";
                    // Display other sailor information as needed
                }
            }
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

    Sailor newSailor(firstName, lastName);
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
    const std::vector<Sailor>& sailorList = yachtPort.getSailorList();

    if (sailorList.empty()) {
        std::cout << "No sailors in the port.\n";
    }
    else {
        std::cout << "Sailor List:\n";
        for (const auto& sailor : sailorList) {
            std::cout << "Name: " << sailor.getFirstName() << " " << sailor.getLastName() << "\n";
        }
    }
}