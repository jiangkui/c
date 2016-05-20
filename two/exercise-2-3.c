#include <stdio.h>

int htoi(char s[]);
int hexToInt(char s);
int hexPower(int power);

int main(void){
	char s[] = "0x1a\0";
	int sum = htoi(s);
	printf("%d\n", sum);
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
		if ((charInt = hexToInt(c)) >= 0)
			sum += charInt * hexPower(exponential++); 
			printf("charInt:%d, sum=%d\n", charInt, sum);
	}

	return sum;
}

int hexToInt(char c){
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'z')
		return c - 'a' + 10;
	if (c >= 'A' && c <= 'Z')
		return c - 'A' + 10;
	return -1;	
}

int hexPower(int power){
	int i = 0, sum = 1;
	for (i = 0; i < power; i++){
		sum *= 16;
	}
	return sum;
}
