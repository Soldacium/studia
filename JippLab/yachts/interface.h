#pragma once
// UserInterface.h
#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "yacht-port.h"
#include <json/json.h>

class UserInterface {
public:
    UserInterface(YachtPort& yachtPort);

    void run();




    void displayMenu() const;


    void saveYachtPortToJsonFile(const std::string& fileName) const;
    
    void loadYachtPortFromJsonFile(const std::string& fileName) const;
private:
    YachtPort& yachtPort;

    void displayYachtMenu() const;
    void displayEmployeeMenu() const;
    void displaySailorMenu() const;
    void displayReservationMenu() const;
    void displayDisplayOptionsMenu() const;
    void displayDataManagementMenu() const;

    void handleAddYacht();
    void handleRemoveYacht();
    void handleDisplayYachts() const;
    void handleAddEmployee();
    void handleRemoveEmployee();
    void handleDisplayEmployees() const;
    void handleAddSailor();
    void handleRemoveSailor();
    void handleDisplaySailors() const;

};

#endif // USERINTERFACE_H