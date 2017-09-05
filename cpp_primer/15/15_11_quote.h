#ifndef EX_15_11_QUOTE_H
#define EX_15_11_QUOTE_H

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
    virtual void debug() const;
    virtual ~Quote() = default;

private:
    string bookNo;

protected:
    double price = 0.0;
};

void Quote::debug() const {
    cout << "bookNo: " << bookNo << ' ';
    cout << "price: " << price << ' ';
}

#endif