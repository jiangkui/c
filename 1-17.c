//
// Created by jiangkui on 2017/5/19.
//

#define MAX_LINE 1000
#define PRINT_LENGTH 80

int getLines(char line[], int maxLength);
void copyLines(char originLine[], char newLine[]);

void readAndPrintEightyLine(){

    int currentLength = 0, index = 0;
    char currentLine[MAX_LINE];
    char printLine[MAX_LINE][MAX_LINE];

    while ((currentLength = getLines(currentLine, MAX_LINE)) > 0) {
        if (currentLength > PRINT_LENGTH) {
            copyLines(currentLine, printLine[index++]);
        }
    }

    printf("长度大于%d的行为:\n", PRINT_LENGTH);
    for (int i = 0; i < index; ++i) {
        printf("%s\n", printLine[i]);
    }
}


