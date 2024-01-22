
#include "person.h"

class Employee : public Person {
public:
    // Constructors
    Employee();
    Employee(const std::string& birthday, const std::string& name, const std::string& surname, const std::string& position);

    // Getter and Setter methods specific to Employee
    const std::string& getPosition() const;
    void setPosition(const std::string& position);

private:
    std::string position;
};