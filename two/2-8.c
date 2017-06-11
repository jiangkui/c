/**
 * 作者:jiangkui
 * 开始:2017年06月10日23:09:00
 * 结束:2017年06月11日17:26:30
 * 备注:
 */

#include <stdio.h>
#include "twoUtil.c"

#define BIT_LENGTH 33

/**
 * 练习 2-8:
 *
 *      编写一个函数 rightrot(x, n), 该函数返回将 x 循环右移 (即从最右端移出
 *  的位将从最左端移入) n (二进制) 位后所得到的值。
 */

/**
 * 思路: 向右侧移动一位, 左侧增加一位即可。
 *      如果右边第一位是0, 直接向右移位即可。
 *      如果右边第一位是1, 则需要设置左侧第一位是1。
 */
int rightrot(unsigned x, int n) {
    int rightBit = 0;
    while (n > 0) {
        rightBit = x & 0x0001;
        if (rightBit == 0) {
            x = x >> 1;
        } else {
            x = (x >> 1) | (~(~0U >> 1));
        }
        n--;
    }
    return x;
}

void formatPrint(int x, int n, int result){
    char xBits[BIT_LENGTH], nBits[BIT_LENGTH], resultBits[BIT_LENGTH];

    hexToBit(x, xBits, BIT_LENGTH);
    hexToBit(n, nBits, BIT_LENGTH);
    hexToBit(result, resultBits, BIT_LENGTH);

    printf("x:%s, 向右移动%d位\n", xBits, n);
    printf("r:%s\n\n", resultBits);
}

int main(){
    int result = 0;
    for (int x = 1; x < 2000; x+=997) {
        for (int n = 1; n < 11; n+=3) {
            result = rightrot(x, n);
            formatPrint(x, n, result);
        }
    }
    return 0;
}