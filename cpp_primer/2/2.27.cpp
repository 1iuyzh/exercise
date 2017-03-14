#include <iostream>

int main() {
    //int i = -1, &r = 0; // 错误: r只能引用整型变量
    //const int i, &r = i;  // 错误: i没有初始化
    //int *const p;   // 错误: p没有初始化
    const int *p;   // 正确
    //int &const r;   // 错误: 没有这种形式
    return 0;
}