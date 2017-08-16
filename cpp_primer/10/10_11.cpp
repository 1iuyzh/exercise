#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    stable_sort(words.begin(), words.end(), isShorter);
}

int main() {
    vector<string> words = { "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle" };
    elimDups(words);
    for (auto word : words)
        cout << word << ' ';
    cout << endl;
    return 0;
}