// Sailor.cpp
#include "sailor.h"

Sailor::Sailor() : Person(), registeredSailboats({}) {}


Sailor::Sailor(const std::string& birthday, const std::string& name, const std::string& surname, const std::vector<int>& registeredSailboats)
    : Person(birthday, name, surname), registeredSailboats(registeredSailboats) {}

const std::vector<int> Sailor::getRegisteredSailboats() const {
    return registeredSailboats;
}

void Sailor::setRegisteredSailboats(const std::vector<int>& newRegisteredSailboats) {
    registeredSailboats = newRegisteredSailboats;
}

void Sailor::addRegisteredSailboat(int sailboatID) {
    registeredSailboats.push_back(sailboatID);
}

void Sailor::removeRegisteredSailboat(int sailboatID) {
    // Find and remove sailboatID from the vector
    auto it = std::find(registeredSailboats.begin(), registeredSailboats.end(), sailboatID);
    if (it != registeredSailboats.end()) {
        registeredSailboats.erase(it);
    }
}