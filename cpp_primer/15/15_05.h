#ifndef EX_15_05_H
#define EX_15_05_H

#include"15_03.h"
#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string&, double, size_t, double);
    double net_price(size_t) const override;

private:
    size_t min_qty = 0;     // 适用折扣政策的最低购买量
    double discount = 0.0;  // 折扣额
};

Bulk_quote::Bulk_quote(const string &book, double p, size_t qty, double disc) : 
    Quote(book, p), min_qty(qty), discount(disc) { }

double Bulk_quote::net_price(size_t cnt) const {
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

#endif