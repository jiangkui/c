#include <stdio.h>

/*
 *  编写程序entab，将空格串替换为最少数量的制表符和空格 
 *  思路：制表符长度为8个字符，则可以每8个字符一组进行缓存，如果该缓存末尾位置是空格，则可以使用1个制表符进行替换。
 */

#define TAB 8 /* 制表符长度 */
char cache[TAB]; /* 缓存一个制表符长度的字符数据 */
int cache_len = 0; /* 缓存长度 */

/* 替换缓存末尾的所有空格为制表符 */
void replaceAndPrint(){
	int last_char_index;
	for (last_char_index=cache_len - 1; last_char_index>=0; last_char_index--){
		if (cache[last_char_index] != ' ')
			break;
	}
	
	int i;
	for (i=0; i<=last_char_index; i++){ /* 输出缓存到最后一个字母 */
		putchar(cache[i]);
	}

	putchar('\t');
	cache_len = 0;
}

/* 输出缓存中的字符，清空缓存 */
void printAndResetCache(){
	int i;
	for (i=0; i<cache_len; i++)
		putchar(cache[i]);
	cache_len = 0; /* 清空缓存 */
}

main(){
	int c, space_num = 0, i;
	for (i = 0; i<TAB; i++)
		cache[i] = 0;

	while ((c = getchar()) != EOF){
		if (c != '\n' && c != '\t'){
			cache[cache_len++] = c;
			if (cache_len == TAB){
				if (cache[TAB - 1] == ' ')
					replaceAndPrint();
				else 
					printAndResetCache();
			}
		} else {
			printAndResetCache();
			putchar(c);
		}
	}
}
