//
// Created by jiangkui on 2017/5/18.
//

void one_night(){
    int c, last_c = 0;

    while ((c = getchar()) != EOF){
        if (c == ' ' && last_c == ' '){
            continue;
        }
        putchar(c);
        last_c = c;
    }
}