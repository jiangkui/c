#include <stdio.h>

/*
 * 编写函数 any(s1, s2) 返回s2在s1 第一次出现的位置，如果没有则返回 -1 
*/

#define MAX_LINE 1000

void readLine(char str[], int maxLine){
	int c, i=0;
	while ((c = getchar()) != EOF && c != '\n'){
		if (i < maxLine - 1)
			str[i++] = c;
		else 
			break;
    }

    str[i] = '\0';
}

int strLen(char s[]){
	int c, i = 0;
	while ((c = s[i]) != '\0'){
		i++;
	}

	return i;
}

int any(char s1[], char s2[]){
	int s1Length, s2Length;
	s1Length = strLen(s1);
	s2Length = strLen(s2);
	
	if (s2Length == 0)
		return 0;
	
	if (s1Length == 0)
		return -1;

	int i, j, s1Index;
	for (i = 0; i < s1Length; i++){
		for (j = 0; j < s2Length; j++){
			s1Index = i + j;
			if (s1Index >= s1Length){
				return -1;
			}
			if (s1[s1Index] != s2[j]){
				break;
			}
			if (j == s2Length - 1){
				return i;
			}
		}
	}

	return -1;
}

int main(void){
	char s1[MAX_LINE];
	char s2[MAX_LINE];

	printf("请输入原字符串：");
	readLine(s1, MAX_LINE);

	printf("请输入查找的字符串：");
	readLine(s2, MAX_LINE);
	
	int index = any(s1, s2);
	printf("位置为：%d\n", index);
}
