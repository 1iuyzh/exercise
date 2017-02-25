#include <stdio.h>
/*
当 fahr = 0, 20, ..., 300 时，分别打印华氏温度和摄氏温度对照表
*/
int main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      /* 温度表的下限 */
    upper = 300;    /* 温度表的上限 */
    step = 20;      /* 步长 */

    fahr = lower;
    printf("title: fahr2celsius\n");
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        //printf("%d\t%d\n", fahr, celsius);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }
    return 0;
}