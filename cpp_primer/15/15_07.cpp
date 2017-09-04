#include"15_07.h"
#include<iostream>

using std::cin; using std::cout; using std::endl;

int main() {
    Limit_quote lq("1111", 10.0, 100, 0.2);
    cout << lq.net_price(99) << endl;
    cout << lq.net_price(100) << endl;
    cout << lq.net_price(101) << endl;
    return 0;
}