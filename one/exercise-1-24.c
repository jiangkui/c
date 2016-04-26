#include <stdio.h>

/*
 * 写一个程序，查找C语言中的基本语法错误，如括号匹配，要正确处理单引号、双引号转义字符序列与注释
 */
#define MAX_LEN 1000 /* 缓存最大长度 */

char cache[MAX_LEN];

int readLine(){
	int c, i;
	for (i=0; i<MAX_LEN-1 && (c = getchar()) != EOF && c != '\n'; i++){
		cache[i] = c;
	}
	if (c == '\n'){
		cache[i++] = c;
	}
	cache[i] = '\0';
	return i;
}

main(){
	int len = 0, index, c;
	
	/* 大括号、中括号、小括号 对称判定，0 表示匹配 */
	int brace = 0, bracket = 0, parenthesis = 0;
	
	/* 引号与注释开关，处于这些内部的符号将忽略，1表示在外面  -1表示在里面 */
	int in_comment = 1; /* 在注释外部 */
	int in_single_quote = 1; /* 在单引号外部 */
	int in_double_quote = 1; /* 在双引号外部 */

	int i;
	for (i=0; i<MAX_LEN; i++)
		cache[i] = 0;
	
	while ((len = readLine()) > 0){
		index = 0;
		while (index < len){
			c = cache[index];
			
			/* 注释内外判定 */
			if (c == '/' && cache[index+1] == '*'){
				in_comment *= -1;
			}
			if (cache[index -1] == '*' && c == '/'){
				in_comment *= -1;
			}
			
			/* 单引号内外判定 */
			if (c == '\''){
				in_single_quote *= -1;
			}
			
			/* 双引号内外判定 */
			if (c == '"'){
				in_double_quote *= -1;
			}
			
			if ((in_comment == 1) && (in_single_quote == 1) && (in_double_quote == 1)){
				if (c == '{')
					brace++;
				if (c == '}')
					brace--;
				if (c == '[')
					bracket++;
				if (c == ']')
					bracket--;
				if (c == '(')
					parenthesis++;
				if (c == ')')
					parenthesis--;
			}
			
			index ++;
		}
	}

	if (brace != 0)
		printf("大括号不匹配\n");
	if (bracket != 0)
		 printf("中括号不匹配\n");
	if (parenthesis != 0)
		 printf("小括号不匹配\n");
	if (in_comment != 1)
		printf("注释不匹配\n");
	if (in_single_quote != 1)
		printf("单引号不匹配\n");
	if (in_double_quote != 1)
		printf("双引号不匹配\n");
	
	if (brace == 0 && bracket == 0 && parenthesis == 0 && in_comment && in_single_quote && in_double_quote)
		printf("语法正确！\n");
}
