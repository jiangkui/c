#include <stdio.h>

/*
 * 使用函数方式重写 1.2 节中的温度转换程序
 */

float convert(float fahr);

main(){
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf("华氏温度\t摄氏温度\n");

	while (fahr <= upper){
		celsius = convert(fahr);
		printf("%8.0f\t%8.2f\n", fahr, celsius);
		fahr += step;
	}
}

/* convert 函数：华氏温度转摄氏温度 */
float convert(float fahr){
	float celsius = 5.0 / 9.0 * (fahr - 32);
	return celsius;
}
