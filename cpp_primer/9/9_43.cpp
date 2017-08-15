#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

void f1(string &s, const string &oldVal, const string &newVal) {
    for (auto cur = s.begin(); cur <= s.end() - oldVal.size(); ) {
        if (oldVal == string(cur, cur + oldVal.size())) {
            cur = s.erase(cur, cur + oldVal.size());
            cur = s.insert(cur, newVal.begin(), newVal.end());
            cur += newVal.size();
        } else ++cur;
    }
}

int main() {
    const char *cp = "thoeeeeeeetho";
    string s(cp);
    f1(s, "tho", "though");
    cout << s << endl;
    return 0;
}