//
// Created by jiangkui on 2017/5/18.
//

void one_twelve(){
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            putchar('\n');
        } else {
            putchar(c);
        }
    }
}
