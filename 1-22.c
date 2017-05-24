/**
 * 作者:jiangkui
 * 开始:2017年05月24日07:46:00
 * 结束:2017年05月24日09:34:31
 * 备注:期间思路错误,浪费了不少时间
 */

#define MAX_LENGTH 1000
#define SPLIT_POSITION 20
#define TAB_LEN 4

int readLine22(char currentLine[]){
    char c;
    int i;
    int setChar = 0;

    for (i = 0; i < SPLIT_POSITION;) {
        c = getchar();
        if (c == EOF) {
            return -1;
        } else if (c == '\n') {
            return 0;
        }

        //列开头的空格全部省略
        if (setChar == 0) {
            if (c == ' ' || c == '\t') {
                continue;
            }
        }

        //字符之间夹杂制表符,转成空格
        setChar = 1;
        if (c == '\t') {
            for (int j = 0; j < TAB_LEN; ++j) {
                currentLine[i++] = ' ';
            }
        } else {
            currentLine[i++] = c;
        }
    }
    return 1;
}

void main22(){
    int length = 0;
    char currentLine[MAX_LENGTH];

    while ((length = readLine22(currentLine)) >= 0) {
        printf("%s\n", currentLine);
    }
}