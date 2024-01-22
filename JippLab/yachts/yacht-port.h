
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
    const std::vector<Employee>& getEmployees() const;
    const std::vector<Sailor>& getSailors() const;
    const std::vector<Reservation>& getReservations() const;

    // Overloaded operators
    YachtPort& operator+=(const Yacht& yacht);
    YachtPort& operator-=(const Yacht& yacht);
    YachtPort& operator+=(const Employee& employee);
    YachtPort& operator-=(const Employee& employee);
    YachtPort& operator+=(const Sailor& sailor);
    YachtPort& operator-=(const Sailor& sailor);
    YachtPort& operator+=(const Reservation& reservation);
    YachtPort& operator+=(const Yacht& yacht);
    YachtPort& operator-=(const Yacht& yacht);

    YachtPort& operator=(const Json::Value& jsonData);

    int generateNextYachtId();
    const Yacht* getYachtById(int yachtId) const;


    // ... (other functionalities)

private:
    int nextYachtId;
    std::string name;
    std::string location;
    std::vector<Yacht> yachts;
    std::vector<Employee> employees;
    std::vector<Sailor> sailors;
    std::vector<Reservation> reservations;
    // ... (other attributes)

    // Helper method to find an employee by ID
    const Employee* findEmployeeById(int id) const;
};