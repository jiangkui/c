//
// Created by jiangkui on 2017/5/22.
//

#define MAX_LINE 1000
#define TAB_LENGTH 8
#define SPACE_PLACEHOLDER "*"

int readLine21(char currentLine[], int maxLength);
void entab(char currentLine[]);
void convertTab(char currentLine[], int startIndex, int endIndex);

void readLineEntab(){
    int length;
    char currentLine[MAX_LINE];
    while ((length = readLine21(currentLine, MAX_LINE)) > 0) {
        entab(currentLine);
        printf("%s", currentLine);
    }
}

//TODO 没做完
//int readLine21(char currentLine[], int maxLength){
//    char c;
//    int i = 0;
//    for (; i < maxLength - 1; ++i) {
//        c = getchar();
//        if (c == EOF) {
//            break;
//        }
//
//        currentLine[i] = c;
//        if (c == '\n') {
//            break;
//        }
//    }
//
//    currentLine[i + 1] = '\0';
//    return i;
//}
//
//void entab(char currentLine[]){
//    char c;
//    char readBuffer[TAB_LENGTH];
//    int resultIndex = 0;
//
//    for (int j = 0; j < MAX_LINE; ++j) {
//        c = currentLine[j];
//        currentLine[resultIndex] = c;
//        if (c != ' ') {
//            resultIndex ++;
//        }
//    }
//
//    //分割为 tab 区间进行处理
//    for (int i = 0; i < MAX_LINE; i += TAB_LENGTH) {
//        convertTab(currentLine, i, i + TAB_LENGTH, readBuffer);
//        resultIndex = copy21(currentLine, resultIndex, readBuffer);
//    }
//}
//
//int copy21(char currentLine[], int resultIndex, char readBuffer[]){
//    for (int j = 0; j < TAB_LENGTH; ++j) {
//        c = readBuffer[j];
//        if (c == EOF) {
//            return resultIndex;
//        }
//        currentLine[resultIndex++] = c;
//        if (c == '\t' || c == '\0') {
//            return resultIndex;
//        }
//    }
//}
//
//
//void convertTab(char currentLine[], int startIndex, int endIndex, char readBuffer[]){
//    char c;
//    for (int i = endIndex; i > startIndex; --i) {
//        c = currentLine[i];
//        if (c != ' ') {
//            if (i == endIndex) {
//
//            } else {
//
//            }
//        }
//    }
//}