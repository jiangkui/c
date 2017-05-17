#include <stdio.h>

/*
 * 编写一个程序，删除每个输入行末尾的空格及制表符，并删除完全是空格的行
 */

#define MAX_CACHE_LEN 100 /* 最多支持缓存100个空白字符 */

void printCache(char cache[], int cache_len);

main(){
	int c, cache_len = 0;
	char cache[MAX_CACHE_LEN]; 

	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t'){
			if (cache_len > MAX_CACHE_LEN)
				printf("缓存超出最大值，程序错误!\n");
			cache[cache_len++] = c;	
		} else if (c == '\n'){
			cache_len = 0; /* 换行时则清空缓存 */
		} else {
			printCache(cache, cache_len);
			cache_len = 0; /* 缓存输出一次之后就清空 */
			putchar(c);
		}
	}	
}

void printCache(char cache[], int cache_len){
	if (cache_len < 1){
		return ;
	}
	int i;	
	for (i = 0; i<cache_len; i++)
		putchar(cache[i]);
}
