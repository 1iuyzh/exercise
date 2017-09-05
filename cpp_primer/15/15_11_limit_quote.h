#ifndef EX_15_11_LIMIT_QUOTE_H
#define EX_15_11_LIMIT_QUOTE_H

#include"15_11_quote.h"
#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

class Limit_quote : public Quote {
public:
    Limit_quote() = default;
    Limit_quote(const string&, double, size_t, double);
    double net_price(size_t) const override;
    void debug() const override;

private:
    size_t min_qty = 0;
    double discount = 0.0;
};

Limit_quote::Limit_quote(const string &book, double p, size_t qty, double disc) : 
    Quote(book, p), min_qty(qty), discount(disc) { }

double Limit_quote::net_price(size_t cnt) const {
    if (cnt > min_qty)
        return (cnt - min_qty) * price + min_qty * (1 - discount) * price;
    else
        return cnt * (1 - discount) * price;
}

void Limit_quote::debug() const {
    Quote::debug();
    cout << "min_qty: " << min_qty << ' ';
    cout << "discount: " << discount << ' ';
}

#endif