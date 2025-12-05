#define _CRT_SECURE_NO_WARNINGS
#include "pyramid.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {

	int row;
	fprintf(stderr, "Enter size of pyramid ");
	scanf("%d", &row);

	int numbers[MAX_SIZE];
	numbers[0] = row;

	FILE *fp = fopen("pyramid.txt", "w");
	pyramid(row, 1, numbers);
	fclose(fp);
}