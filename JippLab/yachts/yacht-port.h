
#ifndef YACHTPORT_HEADER
#define YACHTPORT_HEADER

#include <string>
#include <vector>
#include "Yacht.h"
#include "Employee.h"
#include "Sailor.h"
#include "Reservation.h"
#include <json/json.h>

class YachtPort {
public:
    YachtPort(const std::string& name, const std::string& location);

    // Getter methods for attributes
    const std::string& getName() const;
    const std::string& getLocation() const;
    const std::vector<Yacht>& getYachts() const;
    const std::vector<Employee> getEmployees() const;
    const std::vector<Sailor>& getSailors() const;
    const std::vector<Reservation>& getReservations() const;
    const Employee* getEmployeeByName(const std::string& firstName, const std::string& lastName) const;
    const Sailor* getSailorByName(const std::string& firstName, const std::string& lastName) const;

    // Overloaded operators
    YachtPort& operator+=(const Yacht& yacht);
    YachtPort& operator-=(const Yacht& yacht);
    YachtPort& operator+=(const Employee& employee);
    YachtPort& operator-=(const Employee& employee);
    YachtPort& operator+=(const Sailor& sailor);
    YachtPort& operator-=(const Sailor& sailor);
    YachtPort& operator+=(const Reservation& reservation);

    // YachtPort& operator=(const Json::Value& jsonData);

    int generateNextYachtId();
    const Yacht* getYachtById(int yachtId) const;


private:
    int nextYachtId;
    std::string name;
    std::string location;
    std::vector<Yacht> yachts;
    std::vector<Employee> employees;
    std::vector<Sailor> sailors;
    std::vector<Reservation> reservations;
    const Employee* findEmployeeById(int id) const;
};
#endif