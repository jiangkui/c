#include <stdio.h>

/*
 * 编写一个程序，以每一行一个单词的形式打印输入
 */

main(){
	int c, last_c;

	while ((c = getchar()) != EOF){
		if ((c == ' ' || c == '\t' || c == '\n')){ 
			if (!(last_c == ' ' || last_c == '\t' || last_c == '\n')){ /* 如果上一个字符不是空格，则说明单词结束，可以打印一个换行符 */
				putchar('\n');
			}
			last_c = c;
			continue;
		}
		
		putchar(c);
		last_c = c;
	}
}
