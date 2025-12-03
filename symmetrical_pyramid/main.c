#define _CRT_SECURE_NO_WARNINGS
#include "pascal.h"
#include <stdlib.h>
#include <stdio.h>
#include "screen.h"
#include <time.h>

int main(void) {
	int row;
	printf("Pascal triangle, enter the number of rows: ");
	scanf("%d", &row);

	srand(time(NULL));
	
	int* numbers = (int*)malloc((2 * row - 1) * sizeof(int));
	numbers[0] = row;
	
	FILE *fp = fopen("symmetrical_pyramid.txt", "w");
	pyramid(row, 1, numbers, fp);	

	printf("\x1b[0m");
}