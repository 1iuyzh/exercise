#ifndef cpp_7_19_h
#define cpp_7_19_h

#include <string>
#include <iostream>

class Person {
private:
    std::string name = "";
    std::string address = "";
public:
    Person() = default;
    Person(const std::string &s) : name(s) {}
    Person(const std::string &s1, const std::string &s2) : name(s1), address(s2) {}
    Person(std::istream &is) {
        read(is, *this);
    }
    std::string const& get_name() const {
        return name;
    }
    std::string const& get_addr() const {
        return address;
    }
};

std::istream &read(std::istream &is, Person &item) {
    is >> item.name >> item.address;
    return is;
}

std::ostream &print(std::ostream &os, Person const& item) {
    os << item.get_name() << " " << item.get_addr();
    return os;
}

#endif