#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

class Employee {
public:
    Employee() : id(unique++) { };
    Employee(const string &s) : name(s), id(unique++) { }
    Employee(const Employee &em) : name(em.name), id(unique++) { }
    Employee& operator=(const Employee &rhs) {
        name = rhs.name;
        id = unique++;
        return *this;
    }
    void show_name() {
        cout << name << ' ';
    }
    void show_id() {
        cout << id << ' ';
    }
    static int unique;
private:
    string name;
    int id;
};

int Employee::unique = 0;

int main() {
    // test
    Employee a("Alpha");
    Employee b = a;
    Employee c;
    a.show_name();
    a.show_id();
    cout << endl;
    b.show_name();
    b.show_id();
    cout << endl;
    c.show_name();
    c.show_id();
    cout << endl;
    c = Employee("Beta");
    c.show_name();
    c.show_id();
    return 0;
}