//
// Created by jiangkui on 2017/5/20.
//

#define MAX_LINE 1000

int readLineDelete(char currentLine[], int maxLine);

void copyLine18(char originLine[], char newLine[]);

/**
 * 编写程序,删除每个输入行末尾的空格以及制表符,并删除完全是空格的行
 */
void deleteSpace() {
    int lineLength;
    char currentLine[MAX_LINE];
    char printLine[MAX_LINE][MAX_LINE];
    int index = 0;

    for (int i = 0; i < 5; ++i) {
        lineLength = readLineDelete(currentLine, MAX_LINE);
        if (lineLength > 0) {
            copyLine18(currentLine, printLine[index++]);
        }
    }

    printf("处理完的结果:\n");
    for (int i = 0; i < index; ++i) {
        printf("%s\n", printLine[i]);
    }
}

int readLineDelete(char currentLine[], int maxLine){
    char c;

    int i = 0;
    for (; i < maxLine - 1; ++i) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        }
        currentLine[i] = c;
    }

    //反向寻找不为空格和制表符的字符。
    i--;
    for (; i > 0; i--) {
        c = currentLine[i];
        if (c != ' ' && c != '\t'){
            break;
        }
    }

    currentLine[i + 1] = '\0';
    return i;
}

void copyLine18(char originLine[], char newLine[]){
    for (int i = 0; ; i++) {
        newLine[i] = originLine[i];
        if (newLine[i] == '\0') {
            return;
        }
    }
}