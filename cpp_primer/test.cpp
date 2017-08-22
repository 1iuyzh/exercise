#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

struct Sales_data {
    unsigned units_sold = 0;
    double revenue = 0.0;
    //成员函数
    void combine(const Sales_data&);
};

void Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
}

int main () {
    Sales_data total;
    Sales_data trans;
    total.combine(trans);
    cout << total.units_sold << ' ' << total.revenue << endl;
    return 0;
}