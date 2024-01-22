
#include "Interface.h"
#include <iostream>
#include <fstream>
#include <json/json.h>

void UserInterface::displayEmployeeMenu() const {
    int choice;

    do {
        std::cout << "\nEmployee Menu:\n";
        std::cout << "1. Add Employee\n";
        std::cout << "2. Remove Employee\n";
        std::cout << "3. Display Employees\n";
        std::cout << "0. Back to Main Menu\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            handleAddEmployee();
            break;
        }
        case 2: {
            handleRemoveEmployee();
            break;
        }
        case 3: {
            handleDisplayEmployees();
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


void UserInterface::handleAddEmployee() {
    std::string firstName, lastName, position;

    std::cout << "Enter Employee Details:\n";
    std::cout << "First Name: ";
    std::cin >> firstName;
    std::cout << "Last Name: ";
    std::cin >> lastName;
    std::cout << "Position: ";
    std::cin >> position;

    Employee newEmployee(firstName, lastName, position);
    yachtPort+=newEmployee;
    std::cout << "Employee added successfully.\n";
}

void UserInterface::handleRemoveEmployee() {
    std::string firstName, lastName;

    std::cout << "Enter Employee Name to remove: ";
    std::cout << "First Name: ";
    std::cin >> firstName;
    std::cout << "Last Name: ";
    std::cin >> lastName;

    const Employee* employeeToRemove = yachtPort.getEmployeeByName(firstName, lastName);

    if (employeeToRemove) {
        yachtPort -= *employeeToRemove;
        std::cout << "Employee removed successfully.\n";
    }
    else {
        std::cout << "Employee not found.\n";
    }
}

void UserInterface::handleDisplayEmployees() const {
    const std::vector<Employee>& employeeList = yachtPort.getEmployeeList();

    if (employeeList.empty()) {
        std::cout << "No employees in the port.\n";
    }
    else {
        std::cout << "Employee List:\n";
        for (const auto& employee : employeeList) {
            std::cout << "Name: " << employee.getFirstName() << " " << employee.getLastName()
                << ", Position: " << employee.getPosition() << "\n";
        }
    }
}