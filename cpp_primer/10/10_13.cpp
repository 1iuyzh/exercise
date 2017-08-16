#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

bool f1(const string &s1) {
    return s1.size() >= 5;
}

int main() {
    vector<string> words = { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
    auto it = partition(words.begin(), words.end(), f1);
    for (auto cur = words.begin(); cur != it; cur++)
        cout << *cur << ' ';
    cout << endl;
    for (auto i : words) cout << i << ' ';
    cout << endl;
    return 0;
}