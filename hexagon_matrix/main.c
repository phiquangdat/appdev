#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include "pascal.h"
#include <stdlib.h>
#include <stdio.h>
#include "screen.h"

int main(void) {
	int row;
	int count = 0;

	printf("Pascal triangle, enter the number of rows: ");
	scanf("%d", &row);
	
	srand(time(NULL));

	int total_numbers = 3 * row * (row - 1) + 1;

    int *numbers = malloc(total_numbers * sizeof(int));
    if (!numbers) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i <  3*row*(row-1) + 1; i++)
    	numbers[i] = random_number(i, 3*row*(row-1) + 1);

	for (int i = 3*row*(row-1) + 1; i > 0; i--) {
		int j = rand() % (i + 1); // Start from last, pick random from 0 - current index
		// swap those two
		int temp = numbers[i];
		numbers[i] = numbers[j];
		numbers[j] = temp;
	}

	FILE *fp = fopen("hexagon_output.txt", "w");
	if (fp == NULL) {
		printf("Cannot open file!\n");
		return 1;
	}
	hexagon_matrix(row, 0, &count, numbers,3*row*(row-1) + 1, fp);
	fclose(fp); 
	free(numbers);
	printf("\x1b[0m");
}
