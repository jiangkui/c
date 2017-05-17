#include <stdio.h>

/**
 * 华氏温度与摄氏温度 对照表
 */
void one_three(){
    float huashi, sheshi;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    huashi = lower;
    while (huashi <= upper) {
        sheshi = (float) ((5.0 / 9.0) * (huashi - 32.0));
        printf("%3.0f %6.1f\n", huashi, sheshi);
        huashi = huashi + step;
    }
}