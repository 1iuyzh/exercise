#include"15_11_quote.h"
#include"15_11_bulk_quote.h"
#include"15_11_limit_quote.h"
#include<iostream>

using std::cin; using std::cout; using std::endl;

int main() {
    Bulk_quote bq("1112", 9.0, 50, 0.1);
    Limit_quote lq("1113", 10.0, 100, 0.2);
    bq.debug(); cout << endl;
    lq.debug(); cout << endl;
    Quote *q = &bq;
    q->debug(); cout << endl;
    q->Quote::debug(); cout << endl;
    return 0;
}