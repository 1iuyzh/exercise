#include<iostream>
#include<thread>

using std::cin;
using std::cout;
using std::endl;
using std::thread;

void hello() {
    cout << "Hello Concurrent World" << endl;
}

int main() {
    thread t(hello);
    t.join();
    return 0;
}