#include <iostream>
#include <list>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::list;
using std::vector;

int main() {
    list<int> l1(5, 2);
    vector<int> v1(5, 3);

    //从list<int>初始化vector<double>
    vector<double> v2(l1.begin(), l1.end());
    for (auto i : v2)
        cout << i << ' ';
    cout << endl;

    //从vector<int>初始化vector<double>
    vector<double> v3(v1.begin(), v1.end());
    for (auto i : v3)
        cout << i << ' ';
    cout << endl;

    return 0;
}