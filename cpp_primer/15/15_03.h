#ifndef EX_15_03_H
#define EX_15_03_H

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
    virtual ~Quote() = default; // 虚析构函数

private:
    string bookNo;

protected:
    double price = 0.0;
};

#endif