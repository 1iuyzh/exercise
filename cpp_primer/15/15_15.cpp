#include"15_15.h"
#include<iostream>

using std::cin; using std::cout; using std::endl;

int main() {
    Bulk_quote bq("1111", 10.0, 10, 0.2);
    cout << bq.net_price(20) << endl;
    return 0;
}