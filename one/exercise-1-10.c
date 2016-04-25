#include <stdio.h>

/*
 * 编写一个程序，把输入中的'\t', '\b', '\' 替换为\t, \t, \\
 */

main(){
	int c;

	while ((c = getchar()) != EOF){
		if (c == '\t') printf("\\t");
		else if (c == '\b') printf("\\b");
		else if (c == '\\') printf("\\\\");
		else putchar(c);
	}
}
