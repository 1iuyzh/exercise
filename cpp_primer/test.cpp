#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

unsigned hash(const string &k) {
    unsigned int hashValue = 0;
    /*
    const char *keyp = reinterpret_cast<const char *>(&k);
    for (size_t i = 0; i < sizeof(k); i++) {
        hashValue = 37 * hashValue + keyp[i];
    }
    */
    for (auto i : k) {
        hashValue = 37 * hashValue + i;
    }
    return hashValue;
}

int main() {
    string s("Alpha");
    cout << sizeof(string) << endl;
    cout << hash(s) << endl;
    cout << hash(s) << endl;
    return 0;
}