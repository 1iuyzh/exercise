#ifndef cpp_7_9_h
#define cpp_7_9_h

#include <string>
#include <iostream>

struct Person {
    std::string name;
    std::string address;
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