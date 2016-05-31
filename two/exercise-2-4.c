#include <stdio.h>

/**
 * 删除 s1 中所有的 s2
 */

#define MAX_LINE 1001 //char数组最大长度

void readLine(char s[], int maxLine){
	int c, i;

	for (i=0; i<maxLine -1; i++){
		if ((c = getchar()) != EOF && c != '\n')
			s[i] = c;
		else
			break;
	}

	s[i] = '\0';
}


/**
 * target 在 source 中的位置
 */
int indexOf(char source[], int sourceCount, char target[], int targetCount, int fromIndex){
	int i, j=0, c, index=0;
	if (fromIndex > sourceCount){
		return -1;
	}

	if (targetCount < 1){
		return -1;
	}

	for (i=fromIndex;  i < sourceCount; i++){
		if ((c = source[i]) != EOF && c != '\0'){
			j = 0;
			index = i;
			while (c == target[j]){
				if (j == targetCount-1){
					return i;
				}

				if (index == sourceCount-1){
					return -1;
				}
					
				index++;
				j++;

				c = source[index]; 
			}	
		} else {
			return -1;
		}
		
	}

	return -1;
}

/**
 * 复制数组
 */
int copy(char target[], int targetCount, int targetOffset, char source[], int sourceCount, int sourceOffset, int end){
	int i, copyNum;
	copyNum = end - sourceOffset;
	if (copyNum < 1)
		return 0;

//	printf("targetOffset:%d\t copyNmu:%d\t sourceOffset:%d\t end:%d\n", targetOffset, copyNum, sourceOffset, end);
	if (targetCount < targetOffset + copyNum){
		return 0;
	}
	if (sourceCount < end){
		return 0;
	}

	for (i=targetOffset; i<copyNum + targetOffset; i++){
		target[i] = source[sourceOffset++];
	}
	return i;	
}

void squeeze(char s1[], char s2[], char result[], int resultCount){
	int i, index, sourceCount, targetCount, c, targetOffset = 0;

	for (sourceCount=0; ((c = s1[sourceCount]) && c != EOF && c != '\0'); sourceCount++){
	}

	for (targetCount=0; ((c = s2[targetCount]) && c != EOF && c != '\0'); targetCount++){
	}

	for (i=0; i<sourceCount; i++){
//		printf("i:%d", i);
		index = indexOf(s1, sourceCount, s2, targetCount, i);
//		printf("index:%d\n", index);
		if (index == -1){
			targetOffset = copy(result, resultCount, targetOffset, s1, sourceCount, i, sourceCount);
			return ;
		} else {
			targetOffset = copy(result, resultCount, targetOffset, s1, sourceCount, i, index);
			i += targetCount;
		}		
		i += index-1;
//		printf("i:%d", i);
	}
	return ;	
}


int main(void){
	char s1[MAX_LINE];
	char s2[MAX_LINE];
	char result[MAX_LINE];

	printf("请输入原数组：\n");
	readLine(s1, MAX_LINE);

	printf("请输入删除的数组：\n");
	readLine(s2, MAX_LINE);

	squeeze(s1, s2, result, MAX_LINE);
	printf("删除结果为：%s\n", result);
}

