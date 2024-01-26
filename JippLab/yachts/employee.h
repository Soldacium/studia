
#ifndef EMPLOYEE_HEADER
#define EMPLOYEE_HEADER

#include "person.h"
#include "nlohmann/json.hpp"
class Employee : public Person {
public:
    Employee();
    Employee(const std::string& birthday, const std::string& name, const std::string& surname, const std::string& position);

    const std::string& getPosition() const;
    void setPosition(const std::string& position);

    nlohmann::json toJson() const;

private:
    std::string position;
};
#endif