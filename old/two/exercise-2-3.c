#include <stdio.h>

/* 
 * htoi 把十六进制数组组成的字符串转为与之等价的整形值。
 */

#define UPPER_LINE 101 // 数组存储上线

int htoi(char s[]);
int hexToDecimal(char s);
int hexPower(int power);
int readLine(char line[], int maxLine);

int main(void){
	char line[UPPER_LINE];
	while (readLine(line, UPPER_LINE) > 0){
		int sum = htoi(line);
		printf("转换结束,%s 转成十进制结果为：%d\n", line, sum);
	}
	printf("程序结束\n");
}

int htoi(char s[]){
	int i = 0, lastIndex = 0, charInt = 0, sum = 0, exponential = 0;
	char c;

	if (s[0] != '0' || (s[1] != 'x' && s[1] != 'X'))
		return -1;

	for (lastIndex = 2; s[lastIndex] != '\0'; lastIndex++){
	}

	for (i = lastIndex - 1; i > 1; i--){
		c = s[i];
		if ((charInt = hexToDecimal(c)) >= 0)
			sum += charInt * hexPower(exponential++); 
			printf("第%2d位转为十进制:%4d，sum=%10d\n", i, charInt, sum);
	}

	return sum;
}

// 十六进制to十进制
int hexToDecimal(char c){
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'f') // 此处只到f 不到z ⊙﹏⊙b汗
		return c - 'a' + 10;
	if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	return -1;	
}

// 计算十六进制的次方值。
int hexPower(int power){
	int i = 0, sum = 1;
	for (i = 0; i < power; i++){
		sum *= 16;
	}
	return sum;
}

int readLine(char line[], int maxline){
	int i, c;
	for (i = 0; i < maxline - 1; i++){
		if ((c = getchar()) != EOF && c != '\n')
			line[i] = c;	
		else
			break;
	}
	
	line[i] = '\0';
	if (i == 0)
		return -1;	
	else
		return i;	
}
