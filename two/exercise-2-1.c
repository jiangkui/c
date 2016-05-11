#include <stdio.h>
#include <limits.h>

int main(){
	printf("hello, world\n");
	printf("Size of Char %d\n", CHAR_BIT);
	printf("Size of Char Max %d\n", CHAR_MAX);
	printf("Size of Char Min %d\n", CHAR_MIN);
	printf("Size of shrt Min %d\n", SHRT_MIN);
	printf("Size of shrt Max %d\n", SHRT_MAX);
	printf("Size of int Min %d\n", INT_MIN);
	printf("Size of int Max %d\n", INT_MAX);
	printf("Size of long Min %ld\n", LONG_MIN);
	printf("Size of long Max %ld\n", LONG_MIN);
	printf("Size of unsigned char %u\n", UCHAR_MAX);
	printf("Size of unsinged shrt %u\n", USHRT_MAX);
	printf("Size of unsinged int %u\n", UINT_MAX);
	printf("Size of unsinged long %lu\n", ULONG_MAX);
}
