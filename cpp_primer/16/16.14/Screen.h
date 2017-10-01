#ifndef SCREEN_H
#define SCREEN_H

#include<string>
#include<iostream>
using namespace std;

template <unsigned H, unsigned W>
class Screen {
public:
    typedef string::size_type pos;
    Screen() = default;
    Screen(const char &c) : contents(H * W, c) { }
    char get() const {
        return contents[cursor];
    }
    Screen& move(pos, pos);
    friend ostream& operator<<(ostream &os, const Screen<H, W> &s) {
        unsigned int i, j;
        for (i = 0; i < H; i++) {
            for (j = 0; j < W; j++)
                os << s.contents[i * W, j] << ' ';
            os << endl;
        }
        return os;
    }
    friend istream& operator>>(istream &is, Screen<H, W> &s) {
        char c;
        is >> c;
        string temp(H * W, c);
        s.contents = temp;
        return is;
    }
private:
    pos cursor = 0;
    pos height = H, width = W;
    string contents;
};

template <unsigned H, unsigned W>
inline Screen<H, W>& Screen<H, W>::move(pos d, pos r) {
    cursor = d * width + r;
    return *this;
}

#endif