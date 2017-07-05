#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main(void) {
    string word;
    vector<string> v1;
    while (cin >> word)
        v1.push_back(word);
    return 0;
}