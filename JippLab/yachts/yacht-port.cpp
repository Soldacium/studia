#include "yacht-port.h"

YachtPort::YachtPort(const std::string& name, const std::string& location) : name(name), nextYachtId(1) {}

YachtPort& YachtPort::operator+=(const Yacht& yacht) {
    // Add the yacht to the yachts vector
    yachts.push_back(yacht);
    return *this;
}

YachtPort& YachtPort::operator-=(const Yacht& yacht) {
    // Remove the yacht from the yachts vector
    // Note: This assumes a simple removal without additional checks
    auto it = std::remove(yachts.begin(), yachts.end(), yacht);
    yachts.erase(it, yachts.end());
    return *this;
}

YachtPort& YachtPort::operator+=(const Employee& employee) {
    // Add the employee to the employees vector
    employees.push_back(employee);
    return *this;
}

YachtPort& YachtPort::operator-=(const Employee& employee) {
    // Remove the employee from the employees vector
    // Note: This assumes a simple removal without additional checks
    auto it = std::remove(employees.begin(), employees.end(), employee);
    employees.erase(it, employees.end());
    return *this;
}

YachtPort& YachtPort::operator+=(const Sailor& sailor) {
    // Add the sailor to the sailors vector
    sailors.push_back(sailor);
    return *this;
}

YachtPort& YachtPort::operator-=(const Sailor& sailor) {
    // Remove the sailor from the sailors vector
    // Note: This assumes a simple removal without additional checks
    auto it = std::remove(sailors.begin(), sailors.end(), sailor);
    sailors.erase(it, sailors.end());
    return *this;
}

YachtPort& YachtPort::operator+=(const Reservation& reservation) {
    // Add the reservation to the reservations vector
    reservations.push_back(reservation);
    return *this;
}

YachtPort& YachtPort::operator+=(const Yacht& yacht) {
    // Assign a unique ID to the yacht before adding it to the list
    Yacht yachtWithId = yacht;
    yachtWithId.setId(generateNextYachtId());

    yachts.push_back(yachtWithId);
    return *this;
}

YachtPort& YachtPort::operator-=(const Yacht& yacht) {
    // Remove the yacht with matching ID from the list
    auto it = std::remove_if(yachts.begin(), yachts.end(),
        [yacht](const Yacht& y) { return y.getId() == yacht.getId(); });

    yachts.erase(it, yachts.end());
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
        return nullptr; // Yacht not found
    }
}

int YachtPort::generateNextYachtId() {
    return nextYachtId++;
}

YachtPort& YachtPort::operator=(const Json::Value& jsonData) {
    /*
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
    */

}