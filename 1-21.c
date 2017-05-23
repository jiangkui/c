//
// Created by jiangkui on 2017/5/22.
//

#define MAX_LINE 1000
#define TAB_LENGTH 8
#define SPACE_PLACEHOLDER "*"

int readLine21(char currentLine[], int maxLength) {
    char c;
    int i = 0;
    for (; i < maxLength - 1; ++i) {
        c = getchar();
        if (c == EOF) {
            break;
        }

        currentLine[i] = c;
        if (c == '\n') {
            break;
        }
    }

    currentLine[i + 1] = '\0';
    return i;
}

int convertTab21(char currentLine[], int startIndex, int newStartIndex) {
    char c;
    int endIndex = startIndex + TAB_LENGTH - 1;
    int newEndIndex = newStartIndex;
    int alreadySet = 0;
    int tabIndex;

    // 找tab的位置
    for (tabIndex = TAB_LENGTH; tabIndex > 0; --tabIndex) {
        c = currentLine[startIndex + tabIndex - 1];
        if (c != ' ') {
            newEndIndex = newStartIndex + tabIndex;
            break;
        }
    }

    // 赋值
    for (int j = newStartIndex; j < newEndIndex; ++j) {
        c = currentLine[startIndex++];
        currentLine[j] = c;
        if (c == '\0' || c == EOF) {
            return -1;
        }
    }

    // 末尾至少有一个空格
    if (tabIndex < TAB_LENGTH) {
        currentLine[newEndIndex] = '\t';
        return newEndIndex + 1;
    }
    return newEndIndex;
}

void entab(char currentLine[]) {
    char c;
    int newIndex = 0;

    //分割为 tab 区间进行处理
    for (int i = 0; i < MAX_LINE; i += TAB_LENGTH) {
        int end = convertTab21(currentLine, i, newIndex);
        if (end < 0) {
            return;
        }
        newIndex = end;
    }
}

void readLineEntab() {
    int length;
    char currentLine[MAX_LINE];
    while ((length = readLine21(currentLine, MAX_LINE)) > 0) {
        entab(currentLine);
        printf("%s", currentLine);
    }
}