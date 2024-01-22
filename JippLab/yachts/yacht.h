#include <string>
#include <vector>
#include "reservation.h"

class Yacht {
public:
    // Constructors
    Yacht();
    Yacht(const std::string& name, double length, int maxPassengers, int id);

    // Getter and Setter methods for Yacht attributes
    const std::string& getName() const;
    void setName(const std::string& name);

    double getLength() const;
    void setLength(double length);

    int getMaxPassengers() const;
    void setMaxPassengers(int maxPassengers);

    // Charter Dates methods
    const std::vector<Reservation>& getCharterDates() const;
    void addCharterDate(const std::string& beginDate, const std::string& endDate, int sailorId);
    void removeCharterDate(const std::string& beginDate);

    // Pricing methods
    double getPricing() const;
    void setPricing(double pricing);

    int getId() const;
    void setId(int id);

private:
    int id;
    std::string name;
    double length;
    int maxPassengers;
    std::vector<Reservation> charterDates;
    double pricing;
};