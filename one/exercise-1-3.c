#include <stdio.h>

/* 当 fahr=0, 20, ..., 300 时，打印华氏温度与摄氏温度对照表。在头部打印标题 */
main(){
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0; 
	upper = 300;
	step = 20;

	fahr = lower;
	printf("华氏温度\t摄氏温度\n");
	while(fahr <= upper){
		celsius = (5.0/9.0) * (fahr -32.0);
		printf("%8.0f\t%8.1f\n", fahr, celsius);
		fahr += step;
	}	
}
