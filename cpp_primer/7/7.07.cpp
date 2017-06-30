#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;

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

int main() {
    Sales_data total;
    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total);
                total = trans;
            }
        }
        print(cout, total);
    }
    else {
        std::cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}