#include<iostream>
#include<vector>
#include<memory>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::ostream;
using std::shared_ptr;
using std::make_shared;

auto make_dynamically() {
    return make_shared<vector<int>>();
}

auto save(shared_ptr<vector<int>> p) {
    int i;
    while (cin >> i)
        p->push_back(i);
    return p;
}

ostream& print(shared_ptr<vector<int>> p) {
    for (auto i : *p)
        cout << i << ' ';
    return cout;
}

int main() {
    auto p = save(make_dynamically());
    print(p) << endl;
    return 0;
}