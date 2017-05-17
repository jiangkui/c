#include <stdio.h>

/*
 * 编写一个程序打印长度大于80个字符的所有输入行
 */

#define CONDITION 80 /* 80个字符 */

int readPartLine(char cache[], int len); 
void printLine(char cache[]);

main(){
	int i, partLen = 0;
	char cache[CONDITION + 1];

	for (i=0; i<CONDITION + 1; i++)
		cache[i] = 0;
	
	while ((partLen = readPartLine(cache, CONDITION)) > 0){
		/* printf("%d\n", partLen); */ 
		if (partLen > CONDITION)
			printLine(cache);	
	}
}

/* 读取一行数据并存储到 cache中，如果该行字符大于 len，则停止读取，return len + 1（加一个 '\0' 字符串结束符号，ASCII中 '\0' 表示null，算是c 语言的一个约定吧） */
int readPartLine(char cache[], int len){
	int i = 0, c = 0, cache_len = 0;

	for (i = 0; i < len; i++){
		c = getchar();
		if (c == EOF || c == '\n')
			break;
		else 
			cache[cache_len++] = c;
	}

	cache[cache_len++] = '\0';
	return cache_len;
}

/* 打印行，先打印缓存中的行，之后再打印到该行结束 */
void printLine(char cache[]){
	int i = 0, c;
	printf("该行超过%d个字符：", CONDITION);
	while ((c = cache[i++]) != '\0'){
		printf("%c", c);
	}
	
	while ((c = getchar()) != '\n' && c != EOF)
		printf("%c", c);
	printf("\n");
}
