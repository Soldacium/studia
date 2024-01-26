#ifndef SAILOR_HEADER
#define SAILOR_HEADER

#include <vector>
#include "person.h"
#include "nlohmann/json.hpp"

class Sailor : public Person {
public:
    // Constructors
    Sailor();
    Sailor(const std::string& birthday, const std::string& name, const std::string& surname,const std::vector<int>& registeredSailboats);

    // Getter and Setter methods specific to Sailor
    const std::vector<int> getRegisteredSailboats() const;
    void setRegisteredSailboats(const std::vector<int>& registeredSailboats);

    void addRegisteredSailboat(int sailboatID);
    void removeRegisteredSailboat(int sailboatID);

    nlohmann::json toJson() const;

private:
    std::vector<int> registeredSailboats;
};
#endif