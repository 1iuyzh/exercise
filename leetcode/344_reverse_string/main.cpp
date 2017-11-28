#include<iostream>
#include<string>
#include<chrono>
#include"Solution.h"
using namespace std;
using namespace chrono;

int main() {
    string s = "hello";
    Solution solution;
    // Solution 1
    auto start = system_clock::now();
    string res = solution.reverseString1(s);
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << double(duration.count()) * microseconds::period::num / microseconds::period::den << endl;

    // Solution 2
    start = system_clock::now();
    res = solution.reverseString2(s);
    end = system_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << double(duration.count()) * microseconds::period::num / microseconds::period::den << endl;

    return 0;
}