#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<iterator>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;

int main() {
    istream_iterator<int> in_iter(cin), eof;
    ostream_iterator<int> out_iter(cout, " ");
    vector<int> vec(in_iter, eof);
    sort(vec.begin(), vec.end());
    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;
    return 0;
}