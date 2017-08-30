#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

class Sales_data {
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);

public:
    Sales_data(const string &s, unsigned u, double d) : bookNo(s), units_sold(u), revenue(d) { }
    Sales_data() : Sales_data("", 0, 0) { }
    Sales_data(const string &s) : Sales_data(s, 0, 0) { }
    Sales_data(std::istream &is);
    string isbn() const { return bookNo; }
    Sales_data& operator+=(const Sales_data&);

private:
    inline double avg_price() const;

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
inline double Sales_data::avg_price() const {
    return units_sold ? revenue/units_sold : 0;
}
Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
std::istream& operator>>(std::istream &is, Sales_data &item) {
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();
    return is;
}
std::ostream& operator<<(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << ' ' << item.units_sold << ' ' << item.revenue << ' ' << item.avg_price();
    return os;
}
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}
Sales_data::Sales_data(std::istream &is) : Sales_data() {
    is >> *this;
}

int main() {
    Sales_data item1(std::cin);
    Sales_data item2(std::cin);
    cout << item1 << endl;
    cout << item2 << endl;
    item1 += item2;
    cout << item1 << endl;
    return 0;
}