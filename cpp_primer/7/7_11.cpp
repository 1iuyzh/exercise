#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;

struct Sales_data {
    //构造函数
    Sales_data() = default;
    Sales_data(const std::string &s):bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(std::istream &);
    // 之前的成员
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

std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> item.revenue;
    return is;
}

std::ostream &print(std::ostream &os, Sales_data const& item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(Sales_data const& lhs, Sales_data const& rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}

int main() {
    Sales_data item1;
    print(std::cout, item1) <<std::endl;

    Sales_data item2("0-201-78345-X");
    print(std::cout, item2) << std::endl;

    Sales_data item3("0-201-78345-X", 3, 20.00);
    print(std::cout, item3) << std::endl;

    Sales_data item4(std::cin);
    print(std::cout, item4) << std::endl;

    return 0;
}