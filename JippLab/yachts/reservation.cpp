// Reservation.cpp
#include "Reservation.h"

Reservation::Reservation() : beginDate(""), endDate(""), sailorId(0), yachtId(0) {}

Reservation::Reservation(const std::string& beginDate, const std::string& endDate, int sailorId, int yachtId)
    : beginDate(beginDate), endDate(endDate), sailorId(sailorId), yachtId(yachtId) {}

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
    // Assuming user puts xxxx-xx-xx format
    return beginDate < other.beginDate;
}

nlohmann::json Reservation::toJson() const {
    // Create a JSON object with yacht attributes
    nlohmann::json json;
    json["beginDate"] = beginDate;
    json["endDate"] = endDate;
    json["sailorId"] = sailorId;
    json["yachtId"] = yachtId;
    return json;
}