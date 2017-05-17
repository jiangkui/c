//
// Created by jiangkui on 2017/5/17.
//

#include <printf.h>

/**
 * 摄氏温度转华氏温度
 */
void one_four(){
    float sheshi, huashi;
    float lower, upper, step;

    lower = 0;
    upper = 100;
    step = 10;

    sheshi = lower;
    while (sheshi <= upper) {
        huashi = (float) (sheshi * 9.0 / 5.0 - 32.0);
        printf("摄氏温度:%3.0f 华氏温度:%5.1f\n", sheshi, huashi);
        sheshi += step;
    }
}