#include<iostream>
#include<forward_list>
//#include<iterator>

using std::cin; using std::cout; using std::endl;
using std::forward_list;
using std::advance;

int main() {
    forward_list<int> flst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto prev = flst.before_begin();
    auto curr = flst.begin();

    for (; curr != flst.end(); ) {
        if (*curr & 0x1) {
            curr = flst.insert_after(prev, *curr);
            advance(curr, 2);
            advance(prev, 2);
        } else curr = flst.erase_after(prev);
    }

    for (auto i : flst) cout << i << ' ';
    cout << endl;
    
    return 0;
}