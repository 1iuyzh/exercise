#include"15_03.h"
#include<iostream>

using std::cin; using std::cout; using std::endl;

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