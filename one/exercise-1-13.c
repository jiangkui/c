#include <stdio.h>

/*
 * 打印输入中单词长度的直方图
 */

main(){
	int c, last_c, word_count, i;
	int word[1000];
	
	for (i = 0; i<1000; i++){
		word[i] = 0;
	}

	word_count = 0; 
	while ((c = getchar()) != EOF){
		if ((c == ' ' || c == '\t' || c == '\n')){ 
			if (!(last_c == ' ' || last_c == '\t' || last_c == '\n')){ /* 如果上一个字符不是空格，则说明单词结束，可以打印一个换行符 */
				word_count ++;
			}
			last_c = c;
			continue;
		}
		
		word[word_count]++;	
		last_c = c;
	}

	printf("打印水平直方图\n");
	for (i = 0; i < word_count; i++) {
		int j;
		for (j = 0; j < word[i]; j++){
			printf("#");
		}
		printf("\n");
	}			
	
	/* 找出最长的单词的高度 */
	int c_max = 0;
	for (i = 0; i < word_count; i++){
		c_max = c_max > word[i] ? c_max : word[i];
	}

	printf("打印垂直直方图\n");
	/* 思路：假设最长的单词高度为10，降序打印每一行，如果单词高度大于当前行，则打印 "#"，如果单词高度小于当前行，则打印 " " */
	
	int line_height;
	for (line_height= c_max; line_height> 0; line_height--){ /* 找到单词最长的高度，之后降序打印行 */
		int index;
		for (index= 0; index <= word_count; index++){ /* 输出该行单词的高度，单词高度大于行的高度，则输出 "#"，否则输出 " " */
			if (word[index] >= line_height){
				printf("#");	
			} else {
				printf(" ");
			}
			printf("\t");
		}
		printf("\n");
	}
}
