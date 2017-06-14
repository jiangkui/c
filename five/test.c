/**
 * 作者:jiangkui
 * 开始:2017年06月14日07:58:00
 * 结束:
 * 备注:
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <alloca.h>
int main(){
    char amessage[] = "now is the time";
    char *pmessage;

//    for (int i = 0; i < 5; ++i) {
//        *pmessage++ = amessage[i];
//    }
//
//    *pmessage = '\0';

    pmessage = alloc(20);
    strcpy(pmessage, amessage);

//    char *pmessage = "now is the time";
//
    while (*pmessage != '\0') {
//        *pmessage = *pmessage + 1;
        printf("%c", *pmessage++);
    }

    printf("\n");
    return 0;
}