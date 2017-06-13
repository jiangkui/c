/**
 * 作者:jiangkui
 * 开始:2017年06月13日21:20:00
 * 结束:2017年06月13日22:09:46
 * 备注:
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

/**
 * 练习 5-2
 *      模仿函数 getint 的实现方法, 编写一个读取浮点数的函数 getfloat。getfloat 函数的返回值应该是什么类型?
 *  getint 需求:
 *      每次调用 getint 时, 输入流中下一个整数将被赋值给数组元素 array[n], 同时, n的值+1. 当输入中包含有意义
 *  的数字时, 返回一个正值, 否则返回0;
 */

int getfloat(float *pn){
    char c;
    int sign = 1; //正负符号位

    if (!isdigit(c = getchar())) {
        if (c == '-') {
            sign = -1;
            c = getchar();
        }
    }

    while (c != EOF) {
        if (isdigit(c)) {
            *pn = *pn * 10 + (c - '0');
        } else if (c != '.' && c != '\0' && c != '\n'){
            return -1;
        } else {
            break;
        }

        c = getchar();
    }

    float num = 0;
    if (c == '.') {
        for (float i = 1; (c = getchar()) != '\0' && c!= '\n' && c != EOF; ++i) {
            num = num + (c - '0') * pow(0.1f, i);
        }
    }

    *pn = (*pn + num) * sign;
    return 1;
}

int main(){
    int arrLen = 3;
    float arrs[arrLen];
    for (int i = 0; i < 3; ++i) {
        if (getfloat(&arrs[i]) < 0){
            break;
        }
    }

    for (int j = 0; j < arrLen; ++j) {
        printf("%f\n", arrs[j]);
    }
    return 0;
}