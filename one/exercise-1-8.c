#include <stdio.h>

/*
 * 编写一个统计空格、制表符与换行符个数的程序
 */

main(){
	int space_cnt = 0, tab_cnt = 0, enter_cnt = 0, input;
	while ((input = getchar()) != EOF){
		space_cnt += input == ' ';
		tab_cnt += input == '\t';
		enter_cnt += input == '\n';
	}
	printf("空格：%d个\n", space_cnt);
	printf("制表符：%d个\n", tab_cnt);
	printf("换行符：%d个\n", enter_cnt);
}
