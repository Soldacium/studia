#include "interface.h"
#include <iostream>
#include <fstream>
#include <json/json.h>
#include <nlohmann/json.hpp>
#include "error.h"

void UserInterface::displayDataManagementMenu() const {
    int choice;

    do {
        std::cout << "\nData Management Menu:\n";
        std::cout << "1. Save Data to File\n";
        std::cout << "2. Load Data from File\n";
        std::cout << "0. Back to Main Menu\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string filename;
            std::cout << "Enter the file name to load save: ";
            std::cin >> filename;
            saveYachtPortToJsonFile(filename);
            break;
        }
        case 2: {
            // Load Data from File
            std::string filename;
            std::cout << "Enter the file name to load data: ";
            std::cin >> filename;

            // Load the yacht port data from the specified file
            loadYachtPortFromJsonFile(filename);
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

void UserInterface::saveYachtPortToJsonFile(const std::string& fileName) const {
    
    nlohmann::json yachtPortJson;

    yachtPortJson["nextYachtId"] = yachtPort.getLastYachtId();
    yachtPortJson["name"] = yachtPort.getName();
    yachtPortJson["location"] = yachtPort.getLocation();

    std::vector<Yacht> yachtList = yachtPort.getYachts();
    nlohmann::json yachtArray = nlohmann::json::array();
    for (const Yacht& yacht : yachtList) {
        yachtArray.push_back(yacht.toJson());
    }
    yachtPortJson["yachts"]=yachtArray;

    std::vector<Employee> employeeList = yachtPort.getEmployees();
    nlohmann::json employeeArray = nlohmann::json::array();
    for (const Employee& employee : employeeList) {
        employeeArray.push_back(employee.toJson());
    }
    yachtPortJson["employees"] = employeeArray;

    std::vector<Sailor> SailorList = yachtPort.getSailors();
    nlohmann::json SailorArray = nlohmann::json::array();
    for (const Sailor& Sailor : SailorList) {
        SailorArray.push_back(Sailor.toJson());
    }
    yachtPortJson["Sailors"] = SailorArray;

    std::vector<Reservation> ReservationList = yachtPort.getReservations();
    nlohmann::json ReservationArray = nlohmann::json::array();
    for (const Reservation& Reservation : ReservationList) {
        ReservationArray.push_back(Reservation.toJson());
    }
    yachtPortJson["Reservations"] = ReservationArray;

    // Write the JSON data to a file
    std::ofstream file(fileName);
    if (file.is_open()) {
        file << std::setw(4) << yachtPortJson;
        std::cout << "YachtPort data saved to file successfully.\n";
    }
    else {
        throw errors::OpenFileError("Unable to open the file");
    }
}

// do reverse for saving, simple
void UserInterface::loadYachtPortFromJsonFile(const std::string& fileName) const {
    /*
    
    
    try {
        std::ifstream inputFile(fileName);
        if (inputFile.is_open()) {
            // Read the JSON data from the file
            Json::CharReaderBuilder readerBuilder;
            Json::Value yachtPortJson;
            Json::parseFromStream(readerBuilder, inputFile, &yachtPortJson);

            // Reconstruct the YachtPort object from the JSON data
           // yachtPort = yachtPortJson;  // Assuming YachtPort has a suitable assignment operator or constructor

            inputFile.close();
            std::cout << "YachtPort loaded from file successfully.\n";
        }
        else {
            throw OpenFileError("Unable to open file for reading.");
        }
    }
    catch (const OpenFileError& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }    
    */

}