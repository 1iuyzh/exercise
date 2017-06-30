#ifndef Cpp_7_6_h
#define Cpp_7_6_h

#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    std::string const& isbn() const {
        return bookNo;
    }
    Sales_data& combine(Sales_data const&);
    double avg_price() const;
};

double Sales_data::avg_price() const {
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(Sales_data const& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream &read(istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, Sales_data const& item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(Sales_data const& lhs, Sales_data const& rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

#endif