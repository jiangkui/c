/**
 * 作者:jiangkui
 * 开始:2017年05月24日09:38:00
 * 结束:2017年05月24日10:20:27
 * 备注:
 */

#define MAX_LINE 1000
int onTheHeadAnnotate = 0;
int onTheString = 0;
int onTheLineAnnotate = 0;

int readLine23(char currentLine[]){
    char c;
    int index = 0;
    while ((c = getchar()) != EOF) {

        //字符串中
        if (onTheString == 1) {
            if (c != '"') {
                currentLine[index++] = c;
            } else {
                onTheString = 0;
            }
            continue;
        } else {
            if (c == '"' && currentLine[index - 1] != '\'') {
                onTheString = 1;
                currentLine[index++] = c;
                continue;
            }
        }

        //在头注释里面
        if (onTheHeadAnnotate == 1) {
            if (c == '*' && (c = getchar()) == '/') {
                onTheHeadAnnotate = 0;
            }
            continue;
        }

        //在行注释里面
        if (onTheLineAnnotate == 1) {
            if (c != '\n') {
                continue;
            }
        }

        if (c == '/') {
            if ((c = getchar()) == '*') {
                onTheHeadAnnotate = 1;
                continue;
            }
            if (c == '/') {
                onTheLineAnnotate = 1;
                continue;
            }
            currentLine[index++] = '/';
        }

        currentLine[index++] = c;
        if (c == '\n') {
            currentLine[index++] = '\0';
            onTheLineAnnotate = 0;
            return 0;
        }
    }

    return -1;
}

void main23(){
    int length = 0;
    char currentLine[MAX_LINE];
    while ((length = readLine23(currentLine)) >= 0) {
        printf("%s", currentLine);
    }
}