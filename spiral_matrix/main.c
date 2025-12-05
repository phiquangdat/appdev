#define _CRT_SECURE_NO_WARNINGS
#include "spiral_matrix.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int row;
	fprintf(stderr, "Enter size of matrix (max %d): ", MAX_SIZE);
	scanf("%d", &row);

	int numbers[MAX_SIZE][MAX_SIZE];

	FILE *fp = fopen("spiral_matrix.txt", "w");
	if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

	spiral_matrix(row, numbers);	
	fclose(fp);
}