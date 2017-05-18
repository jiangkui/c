//
// Created by jiangkui on 2017/5/18.
//

void one_eight(){
    int c, kongge, zhibiao, huanhang;

    while (1) {
        c = getchar();

        if (c == '\t') {
            zhibiao ++;
        }
        if (c == '\n') {
            huanhang ++;
        }
        if (c == ' ') {
            kongge ++;
        }

        printf("空格:%d, 制表符:%d, 换行符:%d。\n", kongge, zhibiao, huanhang);
    }
}