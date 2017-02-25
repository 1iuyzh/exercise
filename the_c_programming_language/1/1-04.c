#include <stdio.h>
/*
当celsius = 0, 20, ..., 300 时，分别打印摄氏温度和华氏温度对照表
*/
int main() {
    float celsius, fahr;
    float lower, upper, step;

    lower = 0;      /* 温度表的下限 */
    upper = 300;    /* 温度表的下限 */
    step = 20;      /* 步长 */

    celsius = lower;
    printf("title: celsius2fahr\n");
    while (celsius <= upper) {
        fahr = celsius * 9.0 / 5.0 + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }
    return 0;
}