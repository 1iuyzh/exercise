#include<iostream>
#include<vector>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

int main() {
    vector<char> cvec = { 'H', 'e', 'l', 'l', 'o' };
    //string s1(cvec.begin(), 5); //error
    string s1(cvec.begin(), cvec.end());

    cout << s1 << endl;

    return 0;
}