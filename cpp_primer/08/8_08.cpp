#include"../07/7_12.h"
#include<fstream>
#include<iostream>
using namespace std;

int main(int argc, char **argv) {
    ifstream in(argv[1]);
    ofstream out(argv[2], ofstream::app);
    Sales_data total;
    if (read(in, total)) {
        Sales_data trans;
        while (read(in, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(out, total) << endl;
                total = trans;
            }
        }
        print(out, total) << endl;
    }
    else {
        cerr << "No data?!" << endl;
    }
    return 0;
}