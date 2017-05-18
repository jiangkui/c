//
// Created by jiangkui on 2017/5/18.
//

void one_ten(){
    char c;

    while ((c = getchar()) != EOF) {
        if (c == '\t'){
            printf("\\t");
        } else if (c == '\b'){
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\");
        } else{
            putchar(c);
        }
    }
}