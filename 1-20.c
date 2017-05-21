//
// Created by jiangkui on 2017/5/21.
//

#define MAX_LINE 1000
#define COL_NUM 8

int readLine20(char currentLine[], int maxLength);
void convertTab(char currentLine[]);

void convertTabToSpace(){
    char currentLine[MAX_LINE];
    int length;

    while ((length = readLine20(currentLine, MAX_LINE)) > 0) {
        convertTab(currentLine);
        printf("%s", currentLine);
    }
}

int readLine20(char currentLine[], int maxLength){
    char c;
    int i = 0;
    for (; i < maxLength-1; ++i) {
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

void convertTab(char currentLine[]){
    char c;
    int convertIndex = 0;
    char convertLine[MAX_LINE];
    for (int i = 0; ; ++i) {
        c = currentLine[i];
        if (c != '\t') {
            convertLine[convertIndex++] = c;
        }

        //如果是 制表符,则替换为空格
        if (c == '\t') {
            //计算补充空格的数量
            //(i + 1 -1) 的解释: i+1 表示制表符当前位置, 再减1表示制表符本身的位置会被替代成空格
            int spaceNum = COL_NUM - ((convertIndex + 1 - 1) % COL_NUM);
            for (int j = 0; j < spaceNum && convertIndex < MAX_LINE; ++j) {
                convertLine[convertIndex++] = '*';
            }
        }

        if (c == '\0') {
            break;
        }
    }

    for (int k = convertIndex; k > 0; --k) {
        currentLine[k] = convertLine[k];
    }
}