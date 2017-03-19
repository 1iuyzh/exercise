#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void f1(int *&, int *&);

int main() {
    int i, j;
    cin >> i >> j;
    int *pi = &i;
    int *pj = &j;
    f1(pi, pj);
    cout << *pi << ' ' << *pj << endl;
    return 0;
}

void f1 (int *&p1, int *&p2) {
    int *temp = p1;
    p1 = p2;
    p2 = temp;
}