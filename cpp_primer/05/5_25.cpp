#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main(void) {
    int n1, n2;
    try {
        cin >> n1 >> n2;
        if (n2 == 0)
            throw runtime_error("divisor is 0");
        cout << n1 / n2 << endl;
    }
    catch (runtime_error err) {
        cout << err.what() << endl;
    }
    return 0;
}