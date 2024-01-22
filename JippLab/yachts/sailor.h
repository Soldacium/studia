#include <vector>
#include "Person.h"


class Sailor : public Person {
public:
    // Constructors
    Sailor();
    Sailor(const std::string& birthday, const std::string& name, const std::string& surname, int registeredSailboats);

    // Getter and Setter methods specific to Sailor
    int getRegisteredSailboats() const;
    void setRegisteredSailboats(const std::vector<int>& registeredSailboats);

    void addRegisteredSailboat(int sailboatID);
    void removeRegisteredSailboat(int sailboatID);

private:
    std::vector<int> registeredSailboats;
};
