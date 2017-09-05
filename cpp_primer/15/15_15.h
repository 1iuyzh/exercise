#ifndef EX_15_15_H
#define EX_15_15_H

#include"15_03.h"
#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double price, size_t qty, double disc) :
        Quote(book, price), quantity(qty), discount(disc) { }
    double net_price(std::size_t) const = 0;    // 纯虚函数

protected:
    std::size_t quantity = 0;   // 折扣适用的购买量
    double discount = 0.0;      // 表示折扣的小数值
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double price, size_t qty, double disc) : 
        Disc_quote(book, price, qty, disc) { }
    double net_price(std::size_t) const override;
};

double Bulk_quote::net_price(std::size_t cnt) const {
    if (cnt > quantity)
        return price * (1 - discount) * cnt;
    else
        return price * cnt;
}

#endif