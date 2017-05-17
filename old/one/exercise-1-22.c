#include <stdio.h>

/*
 * 编写一个程序，把较长的输入行改成较短的多行
 * 要保证起列不能有空格或制表符。我的实现方式，如果有空格和制表符的话则忽略。
 */

#define MAX_LEN 25 /* 短行字符长 */
char cache[MAX_LEN]; 
int cache_len = 0;

/* 读取数据到缓存，读满缓存为止，如果 EOF 则返回-1，换行返回0 */
int readToCache(){
	int c;
	while ((c = getchar()) != EOF){
		if (c == '\n'){
			return 0;
		} else if (c == ' ' || c == '\t'){
			continue;
		} else {
			cache[cache_len++] = c;
			if (cache_len >= MAX_LEN)
				return cache_len;
		}
	}
	return -1;
}

void printCache(){
	int i;
	for (i=0; i<cache_len; i++)
		putchar(cache[i]);
	putchar('\n');
	cache_len = 0;
}

main(){
	int status = 0;
	while ((status = readToCache()) >= 0){
		printCache();
	}	
}
