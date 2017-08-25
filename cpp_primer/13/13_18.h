#include<iostream>

using std::cin; using std::cout; using std::endl;

class Employee {
public:
    Employee() : id(unique++) { };
    Employee(const string &s) : name(s), id(unique++) { }
    static int unique;
private:
    string name;
    int id;
};

int Employee::unique = 0;