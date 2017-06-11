/**
 * 作者:jiangkui
 * 开始:2017年06月11日19:40:00
 * 结束:2017年06月11日20:18:37
 * 备注:
 */

#include <stdio.h>

#define MAX_LENGTH 1000
/**
 * 练习 4-1
 *      编写函数 strrindex(s,t), 它返回字符串 t 在 s 中最右边出现的位置。如果 s 不包含 t, 则返回 -1.
 */

int strrindex(char s[], char t[]){
    int tLength = 0;
    while (t[tLength] != '\0') {
        tLength++;
    }

    int sLength = 0;
    while (s[sLength] != '\0') {
        sLength++;
    }

    int sIndex, sIndex2, tIndex;

    for (sIndex = sLength - 1; sIndex >= 0; sIndex--) {
        for (sIndex2 = sIndex, tIndex = tLength - 1; tIndex >= 0; sIndex2--, tIndex--) {
            if (sIndex2 == -1 || s[sIndex2] != t[tIndex]) {
                break;
            }
        }
        if (tIndex == -1) {
            return sIndex;
        }
    }
    return -1;
}

/**
 * 读取一行
 */
int readLine(char line[], int length){
    char c;
    int index = 0;

    for (; index < length - 1; ) {
        c = (char) getchar();
        if (c != '\n' && c != EOF) {
            line[index++] = c;
        } else {
            break;
        }
    }

    line[index + 1] = '\0';
    return index;
}

/**
 * 返回匹配的行
 */
int main(){
    char pattern[] = "test";
    char line[MAX_LENGTH];
    int found = 0;

    while (readLine(line, MAX_LENGTH) > 0) {
        if ((found = strrindex(line, pattern)) > 0) {
            printf("%s, 位置:%d\n", line, found);
            found ++;
        } else {
            printf("%s, 本行没匹配到\n", line);
        }
    }
    return found;
}