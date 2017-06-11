/**
 * 作者:jiangkui
 * 开始:2017年06月10日22:10:00
 * 结束:2017年06月10日23:09:11
 * 备注:补充了下相关知识点
 */

#include <stdio.h>
#include "twoUtil.c"

#define BIT_LENGTH 33

/**
 * 练习 2-7:
 *
 *      编写一个函数 invert(x, p, n), 该函数返回对 x 执行下列操作后的结果值:
 *  将 x 中从第 p 位开始的 n 个 (二进制) 位求反 (即, 1 变成 0, 0 变成 1),
 *  x 的其余各位保持不变。
 *
 *  知识点:
 *      ^ 异或(XOR), 当两个数对应的位不同时该位设为1, 否则设为0.
 *  使用:
 *      取反:1001 0101 ^ 1111 1111 = 0110 1010
 *      不变:1001 0101 ^ 0000 0000 = 1001 0101
 */

/**
 * 思路 result = x ^ 0000 1111 0000 这种形式即可得到结果。
 */
int invert(int x, int p, int n) {
    return x ^ (~(~0 << n) << (p - n + 1));
}

/**
 * 按照格式输出
 */
void formatPrint(int x, int p, int n, int result){
    char xBits[BIT_LENGTH], yBits[BIT_LENGTH], resultBits[BIT_LENGTH];

    hexToBit(x, xBits, BIT_LENGTH);
    hexToBit(result, resultBits, BIT_LENGTH);

    printf("x:%s, 从第 %d 位开始 %d 个位反转\n", xBits, p, n);
    printf("r:%s\n\n", resultBits);
}

int main() {
    int result;
    for (int x = 0; x < 2000; x += 511) {
        for (int p = 1; p < 7; p+= 3) {
            for (int n = 1; n <= p; n++) {
                result = invert(x, p, n);
                formatPrint(x, p, n, result);
            }
        }
    }
    return 0;
}