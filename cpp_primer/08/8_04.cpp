#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

void ReadFiletoVec(const string &, vector<string> &);

int main() {
    vector<string> vec;
    string path("./cpp_primer/data/storyDataFile.txt");
    ReadFiletoVec(path, vec);
    for (const auto &s : vec)
        cout << s << endl;
    return 0;
}

void ReadFiletoVec(const string &path, vector<string> &vec) {
    ifstream in(path);
    if (in) {
        string line;
        while (getline(in, line))
            vec.push_back(line);
    }
}