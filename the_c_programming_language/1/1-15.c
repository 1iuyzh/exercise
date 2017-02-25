#include <stdio.h>

float Fahr2Celsius (float fahr);
/*
重新编写温度转换程序，使用函数实现温度转换计算
*/
int main() {
    int c;
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      // 温度表下限
    upper = 300;    // 温度表上限
    step = 20;      // 步长

    fahr = lower;
    while (fahr <= upper) {
        celsius = Fahr2Celsius (fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }

    c = getchar();
    return 0;
}

float Fahr2Celsius (float fahr) {
    return ((5.0 / 9.0) * (fahr - 32.0));
}
