#include<iostream>
#include<string>
#include<vector>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;

class ReadString {
public:
    ReadString(std::istream &i = std::cin) : is(i) { }
    string operator()() const {
        string str;
        std::getline(is, str);
        return is ? str : string();
    }
private:
    std::istream &is;
};

int main() {
    ReadString readstring;
    vector<string> vec;
    for (string str = readstring(); str != ""; str = readstring())
        vec.push_back(str);
    for (auto i : vec)
        cout << i << ' ';
    cout << endl;
    return 0;
}