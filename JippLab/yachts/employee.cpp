// Employee.cpp
#include "employee.h"

Employee::Employee() : Person(), position("") {}

Employee::Employee(const std::string& birthday, const std::string& name, const std::string& surname, const std::string& position)
    : Person(birthday, name, surname), position(position) {}

const std::string& Employee::getPosition() const {
    return position;
}

void Employee::setPosition(const std::string& newPosition) {
    position = newPosition;
}