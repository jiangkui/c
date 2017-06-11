/**
 * 作者:jiangkui
 * 开始:2017年06月10日22:54:05
 * 结束:
 * 备注:提供一个通用的工具类
 */

/**
 * 十进制转二进制
 */
void hexToBit(unsigned i, char result[], int length) {
    int bit = 0;
    for (int k = 0; k < length; ++k) {
        result[k] = '0';
    }

    //设置数组最后一位是结束符, 注意如果设置 result[BIT_LENGTH] 相当于设置 result[0]。溢出了
    result[length-1] = '\0';

    for (int j = length-2; j >= 0; j--) {
        if (i != 0) {
            bit = i % 2;
            result[j] = (char) ('0' + bit);
            i /= 2;
        } else {
            result[j] = '0';
        }
    }
}