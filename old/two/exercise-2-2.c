#include <stdio.h>

#define MAX_STRING_LENGTH 100

int main(void){
	int i = 0, c, lim = MAX_STRING_LENGTH;
	char s[MAX_STRING_LENGTH];

	while(i < lim -1){
		if ((c=getchar()) == '\n'){
			continue;
		}

		if (c == EOF){
			break;
		}
		s[i++] = c;
	}
}
