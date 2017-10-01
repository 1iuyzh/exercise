#include"DebugDelete.h"
#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main() {
    double *p = new double;
    DebugDelete d;
    d(p);
    int *ip = new int;
    DebugDelete()(ip);
    return 0;
}