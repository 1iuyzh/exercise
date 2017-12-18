#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<string>
using namespace std;

class Employee {
public:
    const string &getName() const {
        return name;
    }

    bool operator==(const Employee &rhs) const {
        return getName() == rhs.getName();
    }
    bool operator!=(const Employee &rhs) const {
        return getName() != rhs.getName();
    }

private:
    string name;
    double salary;
    int seniority;  // 资历
};

#endif