//
// Created by jiangkui on 2017/5/17.
//

#include <printf.h>

/**
 * 逆序打印温度转换表
 */
void one_five(){
    float huashi, sheshi;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    huashi = upper;

    while (huashi >= lower) {
        sheshi = (float) ((5.0 / 9.0) * (huashi - 32.0));
        printf("华氏度:%3.0f 摄氏度:%6.1f\n", huashi, sheshi);
        huashi -= step;
    }
}
