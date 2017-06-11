/**
 * 作者:jiangkui
 * 开始:2017年06月05日09:11:17
 * 结束:2017年06月10日16:56:40
 * 备注:最近一直在瞎忙活, 收收心, 继续搞, 后面会用心做, 做好。
 */

#include <stdio.h>
#include "twoUtil.c"

# define BIT_LENGTH 33

/**
 * 练习 2-6 :
 *      编写一个函数 setbits(x, p, n, y), 该函数返回对 x 执行下列操作后
 * 的结果值: 将 x 中从第 p 位开始的 n 个 (二进制) 位设置为 y 中最右边 n 位的值,
 * x 的其余各位保持不变。
 *
 * 注意: 第p位是从右向左数, 并且假定最右边第一位是0位。
 */

int setbits(int x, int p, int n, int y) {
    return (x & ((~0 << (p + 1)) | (~(~0 << (p - n + 1))))) | ((y & ~(~0 << n)) << (p + 1 - n));
}

/**
 * 按照格式输出
 */
void formatPrint(int x, int p, int n, int y, int result){
    char xBits[BIT_LENGTH], yBits[BIT_LENGTH], resultBits[BIT_LENGTH];

    hexToBit(x, xBits, BIT_LENGTH);
    hexToBit(y, yBits, BIT_LENGTH);
    hexToBit(result, resultBits, BIT_LENGTH);

    printf("x:%s, 从第 %d 位开始 %d 个, 替换成 y 最右边的 %d 个\n", xBits, p, n, n);
    printf("y:%s\n", yBits);
    printf("r:%s\n\n", resultBits);
}

int main(){
    int result;
    for (int x = 0; x < 1500; x += 511) {
        for (int y = 0; y < 77; y += 37) {
            for (int p = 0; p < 7; p += 3) {
                for (int n = 1; n < p+1; n += 2) {
                    result = setbits(x, p, n, y);
                    formatPrint(x, p, n, y, result);
                }
            }
        }
    }
    return 0;
}

