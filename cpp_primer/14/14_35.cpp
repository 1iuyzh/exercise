#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

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
    cout << readstring() << endl;
    return 0;
}