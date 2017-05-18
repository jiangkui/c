//
// Created by jiangkui on 2017/5/18.
//

void one_fourteen(){
    int charset[26], c, other;

    for (int i = 0; i < 26; ++i) {
        charset[i] = 0;
    }

    while ((c = getchar()) != '\n') {
        if (c >= 'a' && c <= 'z') {
            charset[c - 'a']++;
        } else {
            other++;
        }
    }

    for (int j = 0; j < 26; ++j) {
        putchar('a' + j);
        putchar(':');
        for (int i = 0; i < charset[j]; ++i) {
            putchar('*');
        }
        putchar('\n');
    }
}