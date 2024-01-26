#pragma once
// UserInterface.h
#ifndef USERINTERFACE_HEADER
#define USERINTERFACE_HEADER

#include "yacht-port.h"
#include <json/json.h>

class UserInterface {
public:
    UserInterface(YachtPort& yachtPort);

    void run();
    void displayMenu();
    void saveYachtPortToJsonFile(const std::string& fileName) const;
    void loadYachtPortFromJsonFile(const std::string& fileName) const;
private:
    YachtPort& yachtPort;

    void displayYachtMenu();
    void displayEmployeeMenu();
    void displaySailorMenu();
    // void displayReservationMenu();
    void displayDisplayOptionsMenu() const;
    void displayDataManagementMenu() const;

    void handleAddYacht();
    void handleRemoveYacht();
    void handleMakeReservation();
    // void handleDeleteReservation();
    void handleDisplayYachts() const;
    void handleAddEmployee();
    void handleRemoveEmployee();
    void handleDisplayEmployees() const;
    void handleAddSailor();
    void handleRemoveSailor();
    void handleDisplaySailors() const;

};

#endif USERINTERFACE_HEADER