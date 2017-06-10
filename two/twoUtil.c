/**
 * 作者:jiangkui
 * 开始:2017年06月10日22:54:05
 * 结束:
 * 备注:提供一个通用的工具类
 */

/**
 * 十进制转二进制
 */
void hexToBit(int i, char result[], int length){
    int bit = 0;
//    result[length] = '\0';
    for (int j = length-1; j >= 0; j--) {
        if (i > 0) {
            bit = i % 2;
            i /= 2;
            result[j] = '0' + bit;
        } else {
            result[j] = '0';
        }
    }
}