#include <stdio.h>

/*
 * 以逆序打印温度转换表（300~0度）
 */

main(){
	int lower, upper, step;
	float fahr, celsius;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = upper;
	printf("华氏温度\t摄氏温度\n");
	
	while (fahr >= lower){
		celsius = (5.0 / 9.0) * (fahr -32);
		printf("%8.0f\t%8.2f\n", fahr, celsius);
		fahr -= step;	
	}
}
