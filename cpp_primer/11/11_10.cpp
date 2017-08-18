#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<iterator>
#include<algorithm>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::list;
using std::map;

int main() {
    map<vector<int>::iterator, int> mv;
    map<list<int>::iterator, int> ml;
    vector<int> vec = { 0, 1, 2, 3 };
    list<int> lst = { 3, 2, 1, 0 };
    for (auto cur = vec.begin(); cur != vec.end(); cur++)
        mv[cur] = *cur;
    for (auto cur = vec.begin(); cur != vec.end(); cur++)
        cout << mv[cur] << ' ';
    cout << endl;
    /*
    for (auto cur = lst.begin(); cur != lst.end(); cur++)
    ml[cur] = *cur;
    for (auto cur = lst.begin(); cur != lst.end(); cur++)
        cout << ml[cur] << ' ';
    cout << endl;
    */
    return 0;
}