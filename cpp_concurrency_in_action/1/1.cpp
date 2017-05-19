#include <iostream>
#include <thread>
void hello() {
    std::cout << "Hello Concurrency World";
}
int main() {
    std::thread t(hello);
    t.join();
}