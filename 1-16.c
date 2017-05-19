/*
 * 修改打印最长文本行的主程序main，使之可以打印任意长度的输入行的长度，并尽可能多地打印文本。
 * Created by jiangkui on 2017/5/19.
 */

//可读取的最大长度
#define MAX_LINE 1000

int getLines(char line[], int lineLength);
void copyLines(char line[], char sourceLine[]);

void readAndPrintLine(){

    int maxLength = 0;
    int currentLength;

    char currentLine[MAX_LINE];
    char maxLine[MAX_LINE];

    while ((currentLength = getLines(currentLine, MAX_LINE)) > 0) {
        if (currentLength > maxLength) {
            maxLength = currentLength;
            copyLines(currentLine, maxLine);
        }
    }

    printf("最大长度的行是:%s", maxLine);
}

/**
 * 读取一行
 * 返回0 表示结束
 */
int getLines(char line[], int maxLength){
    char c;
    int i;

    for (i = 0; i < maxLength-1; ++i) {
        c = getchar();
        if (c == EOF || c == '\n') {
            break;
        }

        line[i] = c;
    }

    line[i + 1] = '\0';
    return i;
}

void copyLines(char originLine[], char newLine[]){
    int i = 0;

    while ((newLine[i] = originLine[i]) != '\0') {
        ++i;
    }
}