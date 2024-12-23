
#ifndef PERSON_HEADER
#define PERSON_HEADER
#include <string>

class Person {
    friend class Employee;
    friend class Sailor;
public:
    Person();
    Person(const std::string& birthday, const std::string& name, const std::string& surname);

    const std::string& getBirthday() const;
    const std::string& getName() const;
    const std::string& getSurname() const;

    void setBirthday(const std::string& birthday);
    void setName(const std::string& name);
    void setSurname(const std::string& surname);

    bool operator==(const Person& other) const;

private:
    std::string birthday;
    std::string name;
    std::string surname;
};

#endif