#ifndef RESERVATION_HEADER
#define RESERVATION_HEADER

#include <string>

class Reservation {
public:
    Reservation();
    Reservation(const std::string& beginDate, const std::string& endDate, int sailorId);

    const std::string& getBeginDate() const;
    const std::string& getEndDate() const;
    int getSailorId() const;
    void setSailorId(int sailorId);

    // Comparison operators
    bool operator==(const Reservation& other) const;
    bool operator!=(const Reservation& other) const;
    bool operator<(const Reservation& other) const;

private:
    std::string beginDate;
    std::string endDate;
    int sailorId;
};
#endif

