#include <stdio.h>

/*
 * 编写程序 detab，将输入中的制表符替换成适当数目的空格，使空格充满到
 * 下一个制表符终止位置。
 */

#define SPACE ' ' /* 空格 */
#define TAB_NUM 8 /* 制表符长度 */

int offset = 0;

/* 获取空格数量 */
int obtainSpaceNum(int offset, int tabSize){
	return tabSize - (offset % tabSize);
}

void printSpace(int spaceNum){
	int i;
	for (i=0; i<spaceNum; i++){
		offset ++;
		putchar(SPACE);
	}
}

void readPrintLine(int tabSize){
	int c, spaceNum = 0;

	while ((c = getchar()) != EOF){
		if (c == '\n'){
			offset = 0;
			putchar(c);
		} else if (c == '\t'){
			spaceNum = obtainSpaceNum(offset, tabSize);
			printSpace(spaceNum);	
		} else {
			offset++;
			putchar(c);
		}
	}
}

main(){
	int tabSize = TAB_NUM;
	readPrintLine(tabSize);
}
