#include <stdio.h>

/*
 * 编写一个程序删除c语言程序中的所有注释语句。
 */
#define MAX_LEN 1000 /* 缓存最大长度 */

char cache[MAX_LEN];

int readLine(){
	int c, i;
	for (i=0; i<MAX_LEN-1; i++){
		c = getchar();
		if (c == EOF || c == '\n')
			break;
		cache[i] = c;
	}
	
	if (c == '\n'){
		cache[i++] = c;
	}
	cache[i] = '\0';
	return i;
}

main(){
	int in_comment = 0; /* 在注释外 */
	int in_quote = 0; /* 在引号外 */
	int len = 0, index = 0, c = 0;

	while ((len = readLine()) > 0){
		index = 0;
		while (index < len){
			c = cache[index];
			if (c == '"'){
				in_quote = !in_quote; /* 第一个引号 in_quote = 1，第二个引号（引号结束）in_quote = 0 */
			}
			if (in_quote){
				putchar(c);
			} else {
				if (c == '/' && cache[index + 1] == '*'){
					in_comment = 1; /* 注释内 */
				} else if (cache[index-1] == '*' && c == '/'){ /* 注意这里，要跳过 '*' 和 '/' 这两个字符！不要把这俩字符输出 */
					in_comment = 0; /* 注释外 */
				}
				if (!in_comment)
					putchar(c);
			}
			index++;
		}	
	}	
}
