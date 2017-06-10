//
// Created by jiangkui on 2017/5/19.
//

/*
 * 打印摄氏温度转换为华氏温度的转换表
 *
 * 公式：
 * 		摄氏度 = (5/9) * (华氏度 - 32)
 * 		华氏度 = 摄氏度 * (9/5) + 32
 */

float huashiToSheshi(float huashi) {
    float sheshi = (5.0 / 9.0) * (huashi - 32.0);
    printf("华氏温度:%3.0f, 对应摄氏温度:%6.1f\n", huashi, sheshi);
    return sheshi;
}

float SheshiToHuashi(float sheshi) {
    float huashi = sheshi * (9.0 / 5.0) + 32.0;
    printf("摄氏温度:%3.0f, 对应华氏温度:%6.1f\n", sheshi, huashi);
    return huashi;
}