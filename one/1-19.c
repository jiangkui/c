//
// Created by jiangkui on 2017/5/20.
//

#define MAX_LINE 1000

int readLine19(char currentLine[], int maxLength);

void reverse(char str[], int length);

/**
 * 编写函数 reverse, 颠倒输入行的顺序
 */
void reverseLine() {
    int lineLength;

    char readLine[MAX_LINE];

    while ((lineLength = readLine19(readLine, MAX_LINE)) > 0) {
        reverse(readLine, lineLength);
        printf("转换后:%s\n", readLine);
    }
}

int readLine19(char readLine[], int maxLength) {
    char c;
    int i = 0;
    for (i = 0; i < maxLength - 1; ++i) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        }
        readLine[i] = c;
    }

    readLine[i] = '\0';
    return i;
}

void reverse(char str[], int length) {
    char c;
    int lastIndex;
    for (int i = 0; i < length / 2; i++) {
        lastIndex = length - 1 - i;
        c = str[i];
        str[i] = str[lastIndex];
        str[lastIndex] = c;
    }
}
