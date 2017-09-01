#include<iostream>
#include<vector>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

class Compare {
public:
    bool operator()(const string&, const int&) const;
private:
};
bool Compare::operator()(const string &str, const int &n) const {
    return str.size() == n;
}
int main() {
    int n = 5;
    int count = 0;
    string str;
    vector<string> vec;
    Compare compare;
    while (cin >> str) {
        vec.push_back(str);
    }
    for (auto i : vec) {
        if (compare(i, n))
            count++;
    }
    cout << count << endl;
    return 0;
}