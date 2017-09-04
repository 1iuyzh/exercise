#include"15_05.h"
#include<iostream>

using std::cin; using std::cout; using std::endl;

int main() {
    Bulk_quote bq("1111", 19.9, 50, 0.2);
    cout << bq.net_price(49) << endl;
    cout << bq.net_price(50) << endl;
    cout << bq.net_price(51) << endl;
    return 0;
}