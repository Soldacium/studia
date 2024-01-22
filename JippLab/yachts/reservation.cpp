// Reservation.cpp
#include "Reservation.h"

Reservation::Reservation() : beginDate(""), endDate(""), sailorId(0) {}

Reservation::Reservation(const std::string& beginDate, const std::string& endDate, int sailorId)
    : beginDate(beginDate), endDate(endDate), sailorId(sailorId) {}

const std::string& Reservation::getBeginDate() const {
    return beginDate;
}

const std::string& Reservation::getEndDate() const {
    return endDate;
}

int Reservation::getSailorId() const {
    return sailorId;
}

void Reservation::setSailorId(int newSailorId) {
    sailorId = newSailorId;
}

bool Reservation::operator==(const Reservation& other) const {
    return (beginDate == other.beginDate && endDate == other.endDate && sailorId == other.sailorId);
}

bool Reservation::operator!=(const Reservation& other) const {
    return !(*this == other);
}

bool Reservation::operator<(const Reservation& other) const {
    // Compare based on beginDate for simplicity
    return beginDate < other.beginDate;
}