#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    string s = "hello";
    cout << reverseString(s) << endl;
    return 0;
}