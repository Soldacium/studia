#include "interface.h"
#include <iostream>
#include <fstream>
#include <json/json.h>
#include <nlohmann/json.hpp>

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
    /*
    try {
        Json::StreamWriterBuilder writerBuilder;
        std::string jsonOutput = Json::writeString(writerBuilder, yachtPort);

        // Save JSON to a file
        std::ofstream outputFile(fileName);
        if (outputFile.is_open()) {
            outputFile << jsonOutput;
            outputFile.close();
            std::cout << "YachtPort saved to file successfully.\n";
        }
        else {
            throw OpenFileError("Unable to open file for writing.");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }    
    */

}


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
            yachtPort = yachtPortJson;  // Assuming YachtPort has a suitable assignment operator or constructor

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