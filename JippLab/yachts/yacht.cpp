// Yacht.cpp
#include "Yacht.h"

Yacht::Yacht() : name(""), length(0.0), maxPassengers(0), pricing(0.0) {}

Yacht::Yacht(const std::string& name, double length, int maxPassengers, int id)
    : name(name), length(length), maxPassengers(maxPassengers), pricing(0.0), id(id) {}

const std::string& Yacht::getName() const {
    return name;
}

void Yacht::setName(const std::string& newName) {
    name = newName;
}

double Yacht::getLength() const {
    return length;
}

void Yacht::setLength(double newLength) {
    length = newLength;
}

int Yacht::getMaxPassengers() const {
    return maxPassengers;
}

void Yacht::setMaxPassengers(int newMaxPassengers) {
    maxPassengers = newMaxPassengers;
}

const std::vector<Reservation>& Yacht::getCharterDates() const {
    return charterDates;
}

void Yacht::addCharterDate(const std::string& beginDate, const std::string& endDate, int sailorId) {
    charterDates.push_back(Reservation(beginDate, endDate, sailorId));
}

void Yacht::removeCharterDate(const std::string& beginDate) {
    // Find and remove Reservation with matching beginDate from the vector
    auto it = std::remove_if(charterDates.begin(), charterDates.end(),
        [beginDate](const Reservation& reservation) {
            return reservation.getBeginDate() == beginDate;
        });

    charterDates.erase(it, charterDates.end());
}

double Yacht::getPricing() const {
    return pricing;
}

void Yacht::setPricing(double newPricing) {
    pricing = newPricing;
}

int Yacht::getId() const {
    return id;
}

void Yacht::setId(int id) {
    this->id = id;
}