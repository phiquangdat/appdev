#define _CRT_SECURE_NO_WARNINGS
#include "pascal.h"
#include <stdlib.h>
#include <stdio.h>
#include "screen.h"

int main(void) {
	int row;
	printf("Pascal triangle, enter the number of rows: ");
	scanf("%d", &row);
	setBGcolor(BLACK);
	clearScreen();
	srand(time(NULL));
	for(int i = 0; i < row; i++) {
		gotoXY(40 + (row - i) * 2, 10 + i);
		for(int j = 0; j <= i; j++) {
			setFGcolor(RED + rand() % 7);
			printf("%4d", n_choose_k(i, j));
		}
		printf("\n");
	}
	printf("\x1b[0m");
}