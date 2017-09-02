#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sales_price) : 
        bookNo(book), price(sales_price) { }
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual ~Quote() = default;

private:
    string bookNo;

protected:
    double price = 0.0;
};

double print_total(std::ostream &os, const Quote& item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << "# sold: " << n << " total due: " << ret << endl;
    return ret;
}
int main() {
    Quote q("1234", 10);
    print_total(cout, q, 5);
    return 0;
}