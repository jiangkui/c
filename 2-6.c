/**
 * 作者:jiangkui
 * 开始:2017年06月05日09:11:17
 * 结束:
 * 备注:
 */

#include <stdio.h>
#include <stdlib.h>

//第p位是从右往左数
unsigned setbits(int x, int p, int n, int y) {
    return (x & ((~0 << (p + 1)) | (~(~0 << (p - n + 1))))) | ((y & ~(~0 << n)) << (p + 1 - n));
}

int main(){
    unsigned i;
    unsigned j;
    unsigned k;
    int p;
    int n;
//    char i2[32];
//    char j2[32];
//    char k2[32];

    for(i = 0; i < 30000; i += 511)
    {
        for(j = 0; j < 1000; j += 37)
        {
            for(p = 0; p < 16; p++)
            {
                for(n = 1; n <= p + 1; n++)
                {
                    //TODO 需要增加一个方法, 十进制转2进制。 以二进制的方式输出
                    k = setbits(i, p, n, j);
//                    itoa(i, i2, 2);
//                    itoa(j, j2, 2);
//                    itoa(k, k2, 2);
//                    printf("setbits(%u, %d, %d, %u) = %u\n", i, p, n, j, k);
                    printf("setbits(%o, %d, %d, %o) = %o\n", i, p, n, j, k);
//                    printf("setbits(%s, %d, %d, %s) = %s\n", i2, p, n, j2, k2);
                }
            }
        }
    }
    return 0;
}