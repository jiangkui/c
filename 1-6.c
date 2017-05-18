//
// Created by jiangkui on 2017/5/18.
//

void one_six(){
    int c = 0;
    int value = 0;

    printf("提示：\n");
    printf("1、在 windows组合键 ctrl + d 可以输入 EOF!\n");
    printf("2、输入 ctrl + c 可以结束本程序!\n");

    while (1){
        c = getchar();

        if (c == '\n'){
            continue; /* 回车符号不处理 */
        }

        value = (c == EOF);
        printf("您输入的是:%c, (getchar() != EOF) 的值为：%d\n", c, value);

        if (value == 1) {
            break;
        }
    }
}