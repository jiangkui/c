#include <stdio.h>

/*
 * 验证表达式 getchar() != EOF 的值是0还是1
 * 提示：windows 下 ctrl + d 表示输入 EOF
 */

main(){
	int c = 0;
	int value = 0;
	
	printf("提示：\n");
	printf("1、在 windows组合键 ctrl + d 可以输入 EOF!\n");
	printf("2、输入 ctrl + c 可以结束本程序!\n");

	while (1){
		c = getchar();

		if (c == '\n'){
			continue; /* 回车符号不处理 */
		}	

		value = (c == EOF);
		printf("您输入的是:%c, (getchar() != EOF) 的值为：%d\n", c, value); 
	}
}
