#include <stdio.h>

/*
 * 编写一个程序，打印输入中各个字符出现频度的直方图。(不区分大小写，大写按小写累计）
 */

main(){
	int character[26], i, c;

	for (i = 0; i < 26; i++){
		character[i] = 0;
	}	

	while ((c = getchar()) != EOF){
		int value = (c - 'a');
		if (value >= 0 && value < 26){
			character[value]++;
		}

		/* 大写字母按照小写字母计算 */
		value = (c - 'A');
		if (value >= 0 && value < 26){
			character[value] ++;
		}	
	} 	
	
	printf("打印单词出现频率的直方图\n");
	
	for (i = 0; i < 26; i++){
		printf("%c:", i + 'a');
		int j;
		for (j = 0; j < character[i]; j ++){
			printf("#");
		}
		printf("\n");
	}
}
