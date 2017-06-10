/**
 * 作者:jiangkui
 * 开始:2017年05月26日09:18:00
 * 结束:
 * 备注:
 */

#define MAX_LINE 1000

int htoi(char line[]){
    char c;
    int num = 0;

    //前两位跳过  0X 和 0x
    for (int i = 2; i < MAX_LINE; ++i) {
        c = line[i];

        if (c == '\0') {
            break;
        }
        num = num * 16 + c;
    }
    return num;
}