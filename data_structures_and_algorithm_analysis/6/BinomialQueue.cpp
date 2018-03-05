#include"BinomialQueue.h"
#include<iostream>
#include<vector>
using namespace std;

int main() {
    BinomialQueue<int> q1;
    q1.insert(16);
    q1.insert(18);
    BinomialQueue<int> q2(12);
    q2.insert(21);
    q2.insert(24);
    q2.insert(65);
    q1.merge(q2);
    BinomialQueue<int> q3(13);
    BinomialQueue<int> q4(14);
    q4.insert(26);
    BinomialQueue<int> q5(23);
    q5.insert(51);
    q5.insert(24);
    q5.insert(65);
    q3.merge(q4);
    q3.merge(q5);

    return 0;
}