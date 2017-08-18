#include<iostream>
#include<string>
#include<vector>
#include<utility>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;
using std::pair;

int main() {
    vector<string> svec = { "the", "but", "and", "or", "an" };
    vector<int> ivec = { 0, 1, 2, 3, 4 };
    vector<pair<string, int>> vec;
    auto sp = svec.cbegin();
    auto ip = ivec.cbegin();
    while (sp != svec.cend()) {
        vec.push_back(make_pair(*sp, *ip));
        // vec.emplace_back(*sp, *ip);
        // vec.push_back({*sp, *ip});
        // vec.push_back(pair<string, int>(*sp, *ip));
        sp++;
        ip++;
    }
    for (auto i : vec)
        cout << i.first << ' ' << i.second << endl;
    return 0;
}