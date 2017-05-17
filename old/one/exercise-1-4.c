#include <stdio.h>

/* 
 * 打印摄氏温度转换为华氏温度的转换表 
 * 
 * 公式：
 * 		摄氏度 = (5/9) * (华氏度 - 32)
 * 		华氏度 = 摄氏度 * (9/5) + 32
 */

main(){
	int lower, upper, step;
	float fahr, celsius;

	lower = 0;
	upper = 100;
	step = 10;

	celsius = lower;
	printf("摄氏温度\t华氏温度\n");	

	while (celsius <= upper){
		fahr = celsius * 9.0 / 5.0 + 32;
		printf("%8.0f\t%8.2f\n", celsius, fahr);
		celsius += step;
	}
}
