#include "yacht-port.h"

YachtPort::YachtPort(const std::string& name, const std::string& location) : name(name), location(location) {}

const std::string& YachtPort::getName() const {
    return name;
}

const std::string& YachtPort::getLocation() const {
    return location;
}

const std::vector<Yacht>& YachtPort::getYachts() const {
    return yachts;
}

const std::vector<Employee> YachtPort::getEmployees() const {
    return employees;
}

const std::vector<Sailor>& YachtPort::getSailors() const {
    return sailors;
}

const std::vector<Reservation>& YachtPort::getReservations() const {
    return reservations;
}

YachtPort& YachtPort::operator+=(const Employee& employee) {
    employees.push_back(employee);
    return *this;
}

YachtPort& YachtPort::operator+=(const Yacht& yacht) {
    // Assign a unique ID
    Yacht yachtWithId = yacht;
    yachtWithId.setId(generateNextYachtId());

    yachts.push_back(yachtWithId);
    return *this;
}

YachtPort& YachtPort::operator+=(const Sailor& sailor) {
    sailors.push_back(sailor);
    return *this;
}

YachtPort& YachtPort::operator-=(const Yacht& yacht) {
    auto it = std::remove(yachts.begin(), yachts.end(), yacht);
    yachts.erase(it, yachts.end());
    return *this;
}

YachtPort& YachtPort::operator-=(const Employee& employee) {
    auto it = std::remove(employees.begin(), employees.end(), employee);
    employees.erase(it, employees.end());
    return *this;
}



YachtPort& YachtPort::operator-=(const Sailor& sailor) {
    auto it = std::remove(sailors.begin(), sailors.end(), sailor);
    sailors.erase(it, sailors.end());
    return *this;
}



YachtPort& YachtPort::operator+=(const Reservation& reservation) {
    reservations.push_back(reservation);
    return *this;
}



const Yacht* YachtPort::getYachtById(int yachtId) const {
    // Find the yacht with the specified ID
    auto it = std::find_if(yachts.begin(), yachts.end(),
        [yachtId](const Yacht& y) { return y.getId() == yachtId; });

    if (it != yachts.end()) {
        return &(*it); // Return a pointer to the found yacht
    }
    else {
        return nullptr;
    }
}

int YachtPort::generateNextYachtId() {
    return nextYachtId++;
}

int YachtPort::getLastYachtId() {
    return nextYachtId;
}

const Employee* YachtPort::getEmployeeByName(const std::string& firstName, const std::string& lastName) const {
    for (const auto& employee : employees) {
        if (employee.getName() == firstName && employee.getSurname() == lastName) {
            return &employee;  // Return a pointer to the found employee
        }
    }
    return nullptr;  
}

const Sailor* YachtPort::getSailorByName(const std::string& firstName, const std::string& lastName) const {
    for (const auto& sailor : sailors) {
        if (sailor.getName() == firstName && sailor.getSurname() == lastName) {
            return &sailor;  // Return a pointer to the found sailor
        }
    }

    return nullptr; 
}


/*
YachtPort& YachtPort::operator=(const Json::Value& jsonData) {
    
    // Assuming you have appropriate member functions for deserialization
    if (jsonData.isObject()) {
        // Extract and validate data from jsonData
        // For example:
        if (jsonData.isMember("name") && jsonData["name"].isString()) {
            // Update the name member of YachtPort
            this->name = jsonData["name"].asString();
        }

        if (jsonData.isMember("location") && jsonData["location"].isString()) {
            // Update the location member of YachtPort
            this->location = jsonData["location"].asString();
        }

        if (jsonData.isMember("yachts") && jsonData["yachts"].isArray()) {
            // Clear existing yachts and add new ones
            this->yachts.clear();
            for (const auto& yachtJson : jsonData["yachts"]) {
                // Assuming Yacht has a constructor or assignment operator from Json::Value
                Yacht yacht;
                yacht = yachtJson;
                this->yachts.push_back(yacht);
            }
        }

        // Repeat similar blocks for employees, sailors, and reservations...

        // Return the updated object
        return *this;
    }
    else {
        // Handle invalid JSON data
        // You might throw an exception or handle it according to your requirements
        throw std::invalid_argument("Invalid JSON data for YachtPort deserialization");
    }    
    

}*/