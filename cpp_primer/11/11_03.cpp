#include<iostream>
#include<string>
#include<unordered_map>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::unordered_map;

int main() {
    unordered_map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];
    for (const auto &w : word_count)
        cout << w.first << ' ' << w.second << endl;
    return 0;
}