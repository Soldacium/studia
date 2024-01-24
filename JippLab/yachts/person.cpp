#include "person.h"

// Default constructor
Person::Person() {}

// Parameterized constructor
Person::Person(const std::string& birthday, const std::string& name, const std::string& surname)
    : birthday(birthday), name(name), surname(surname) {}

// Getter methods
const std::string& Person::getBirthday() const {
    return birthday;
}

const std::string& Person::getName() const {
    return name;
}

const std::string& Person::getSurname() const {
    return surname;
}

// Setter methods
void Person::setBirthday(const std::string& newBirthday) {
    birthday = newBirthday;
}

void Person::setName(const std::string& newName) {
    name = newName;
}

void Person::setSurname(const std::string& newSurname) {
    surname = newSurname;
}

bool Person::operator==(const Person& other) const {
    // Customize the equality comparison based on your class attributes
    return getName() == other.getName() && getSurname() == other.getSurname();
}