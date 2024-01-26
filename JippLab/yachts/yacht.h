#ifndef YACHT_HEADER
#define YACHT_HEADER

#include <string>
#include <vector>
#include "reservation.h"
#include <nlohmann/json.hpp>


class Yacht {
public:
    Yacht();
    Yacht(const std::string& name, double length, int maxPassengers, int id);

    const std::string& getName() const;
    void setName(const std::string& name);

    double getLength() const;
    void setLength(double length);

    int getMaxPassengers() const;
    void setMaxPassengers(int maxPassengers);

    const std::vector<Reservation>& getCharterDates() const;
    void addCharterDate(const std::string& beginDate, const std::string& endDate, int sailorId);
    void removeCharterDate(const std::string& beginDate);

    double getPricing() const;
    void setPricing(double pricing);

    int getId() const;
    void setId(int id);

    nlohmann::json toJson() const;

    bool operator==(const Yacht& other) const;

private:
    int id;
    std::string name;
    double length;
    int maxPassengers;
    std::vector<Reservation> charterDates;
    double pricing;
};
#endif YACHT_HEADER