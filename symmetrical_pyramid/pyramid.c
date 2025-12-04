#include <stdio.h>
#include "screen.h"
#include <time.h>
#include <stdlib.h> 
#include <stdio.h>
// function definition
int factorial(int n) {
	if (n == 0) return 1; 
	else return n * factorial(n - 1);
}

int n_choose_k(int n, int k) {
	return factorial(n) / (factorial(k) * factorial(n - k));
}

void pyramid(int rows, int current_row, int* numbers, FILE* fp) {
	int max_length = 2 * rows - 1;
	int value = rows;
	if(current_row > max_length) {
		free(numbers);
		return;
	}

	gotoXY(40 - 2 * current_row, 10 + current_row);

	for(int i = 0; i < current_row; i++)
		printf("%4d", numbers[i]);
	printf("\n");

	int* new_row = (int*)malloc((current_row + 1) * sizeof(int));
	int left = 0, right = current_row;
	while(left <= right) {
		new_row[left] = new_row[right] = value;
		left++;
		right--;
		value--;
	}

	// print to txt file
	int indent = (max_length - current_row) * 2;

    for (int i = 0; i < indent; i++) 
        fputc(' ', fp);

	for (int i = 0; i < current_row; i++)
    {
        fprintf(fp, "%4d", numbers[i]);
    }

    fprintf(fp, "\n");
	pyramid(rows, current_row + 1, new_row, fp);
	free(numbers);
}