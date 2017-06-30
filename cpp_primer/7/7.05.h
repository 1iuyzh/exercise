#ifndef Cpp_7_5_h
#define Cpp_7_5_h

#include <iostream>
#include <string>

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

#endif