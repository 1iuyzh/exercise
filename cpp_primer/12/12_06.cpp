#include<iostream>
#include<vector>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::ostream;

auto make_dynamically() {
    // return new vector<int>; // 默认初始化
    // return new vector<int>(); // 值初始化
    return new vector<int>{}; // 列表初始化
}

auto save(vector<int> *p) {
    int i;
    while (cin >> i)
        p->push_back(i);
    return p;
}

// 返回值ostream&, 返回标准输出cout
ostream& print(vector<int> *p) {
    for (auto i : *p)
        cout << i << ' ';
    return cout;
}

int main() {
    auto p = save(make_dynamically());
    print(p) << endl;
    delete p;
    return 0;
}