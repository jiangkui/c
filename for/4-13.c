/**
 * 作者:jiangkui
 * 开始:2017年06月12日09:44:00
 * 结束:
 * 备注:
 */

#include <stdio.h>
#include <string.h>
/**
 * 练习 4-13
 *      编写一个递归版本的 reverse(s) 函数, 以将字符串 s 倒置。
 */

/**
 * 思路: 将第一个值与最后一个值交换, 第二个值与倒数第二个值交换, 递归即可。
 */
void reverse(char s[]){
    void reverser(char s[], int start, int end);

    int len = strlen(s);

    reverser(s, 0, len-1);
}

void reverser(char s[], int start, int end) {
    char temp;
    if (start < end) {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        reverser(s, ++start, --end);
    }
}

int main(){
    char test[] = "1234567890";
    printf("转换前:%s\n", test);
    reverse(test);
    printf("转换后:%s\n", test);
    return 0;
}