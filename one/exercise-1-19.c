#include <stdio.h>

/**
 * 编写函数 reverse(s), 将字符串s中的字符顺序颠倒过来。使用该函数编写一个程序，每次颠倒一个输入行中的字符顺序
 */

#define MAX_LEN 1000 /* 字符数组最大长度 */

int reverse(char s[]);
int readLine(char s[], int len);
void printLine(char s[], int len);
 
main(){
	int status = 0, char_len = 0;
	char s[MAX_LEN];
	int i;
	for (i=0; i<MAX_LEN; i++)
		s[i] = 0;

	while ((status = readLine(s, MAX_LEN)) >= 0){
		char_len = reverse(s);
		printLine(s, char_len);
	}	
}


int reverse(char s[]){
	int char_len = 0, cache = 0;

	for (char_len = 0; s[char_len] != '\0'; char_len++)
		;
	
	int low = 0, hi = char_len - 1;
	while (low < hi){
		cache = s[low];
		s[low] = s[hi];	
		s[hi] = cache;
		low++;
		hi--;
	}	
	return char_len;
}

int readLine(char s[], int len){
	int c, index = 0;
	while ((c = getchar()) != EOF){
		if (c == '\n'){
			return 0;
		}
		if (index > len){
			return 0;
		}
		s[index++] = c;
	}
	return -1;
}

void printLine(char s[], int len){
	if (len < 1){
		return;
	}
	int i;
	for (i=0; i<len; i++){
		putchar(s[i]);
	}
	putchar('\n');
}
