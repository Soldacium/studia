#ifndef RESERVATION_HEADER
#define RESERVATION_HEADER

#include <string>
#include "nlohmann/json.hpp"

class Reservation {
public:
    Reservation();
    Reservation(const std::string& beginDate, const std::string& endDate, int sailorId, int yachtId);

    const std::string& getBeginDate() const;
    const std::string& getEndDate() const;
    int getSailorId() const;
    void setSailorId(int sailorId);
    int getYachtId() const;
    void setYachtId(int yachtId);

    // Comparison operators
    bool operator==(const Reservation& other) const;
    bool operator!=(const Reservation& other) const;
    bool operator<(const Reservation& other) const;

    nlohmann::json toJson() const;

private:
    std::string beginDate;
    std::string endDate;
    int sailorId;
    int yachtId;
};
#endif RESERVATION_HEADER

