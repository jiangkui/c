//
// Created by jiangkui on 2017/5/18.
//

/**
 * 编写一个程序,打印输入单词长度直方图
 */
void one_thirteen(){
    int c, last_c, index;
    int wordsNum[10000];
    for (int i = 0; i < 10000; ++i) {
        wordsNum[i] = 0;
    }

    c = index = 0;
    last_c = -1;
    while ((c = getchar()) != '\n') {
        if (c == ' ' || c == '\t') {
            if (last_c == -1) {
                continue;
            } else {
                index ++;
            }
        } else {
            wordsNum[index]++;
        }
        last_c = c;
    }

    //水平直方图
    for (int j = 0; j <= index; ++j) {
        for (int i = 0; i < wordsNum[j]; ++i) {
            putchar('*');
        }
        putchar('\n');
    }

    //垂直直方图
    int maxHeight = 0;
    for (int k = 0; k < index; ++k) {
        if (maxHeight < wordsNum[index]) {
            maxHeight = wordsNum[index];
        }
    }
    printf("最大高度:%d\n", maxHeight);

    for (int l = maxHeight; l > 0; --l) {
        for (int i = 0; i <= index; ++i) {
            if (wordsNum[i] >= l) {
                putchar('*');
            } else {
                putchar(' ');
            }
            putchar('\t');
        }
        putchar('\n');
    }
}

