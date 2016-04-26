#include <stdio.h>

/*
 * 修改打印最长文本行的主程序main，使之可以打印任意长度的输入行的长度，并尽可能多地打印文本。
 */

#define UPPER_LIMIT 1000 /* 数组存储长度上限 */

int getlines(char line[], int maxline); /* getline 函数名已经被 stdio.h 中定义过了，所以此处改了个名字，不然报冲突 */
void copy(char to[], char from[]);

main(){
	int length; /* 当前行长度 */
	int max_length; /* 最大行长度 */
	char line[UPPER_LIMIT];
	char max_line[UPPER_LIMIT];

	while ((length = getlines(line, UPPER_LIMIT)) > 0)
		if (length > max_length){
			max_length = length;
			copy(max_line, line);
		}

	if (max_length > 0)
		printf("最长的行长度为：%d，内容是：%s\n", max_length, max_line);
}

int getlines(char line[], int maxline){
	int i, c;

	for (i=0; (c = getchar()) != EOF && c != '\n'; i++){
		if (i < maxline-1){
			line[i] = c;	
		}
	} 

	if (c == '\n'){
		line[++i] = '\0';
	}
	return i;
}

void copy(char to[], char from[]){
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
