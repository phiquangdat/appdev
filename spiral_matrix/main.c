#define _CRT_SECURE_NO_WARNINGS
#include "spiral_matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int main(void) {
	int row;
	printf("Enter size of matrix: ");
	scanf("%d", &row);

	srand(time(NULL));
	int** numbers = (int**)malloc(row * sizeof(int*));
	for(int i = 0; i < row; i++) {
		numbers[i] = (int*)malloc(row * sizeof(int));
	}
	
	FILE *fp = fopen("spiral_matrix.txt", "w");
	spiral_matrix(row, numbers, fp);	

	printf("\x1b[0m");
}