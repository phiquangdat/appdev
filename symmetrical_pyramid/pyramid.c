#include <stdio.h>
#include <stdlib.h>
#include "pyramid.h"
// function definition
void pyramid(int rows, int current_row, int numbers[]) {
	int max_length = 2 * rows - 1;
	int value = rows;

	for(int i = 0; i < 40 - 2 * current_row; i++)
		printf(" "); // print leading spaces since ansi does not support in redirect output

	for(int i = 0; i < current_row; i++)
		printf("%4d", numbers[i]);

	if(current_row == max_length) return;
	printf("\n"); // no new line at final row

	int new_row[MAX_SIZE] = {0};

	int left = 0, right = current_row;

	while(left <= right) {
		new_row[left] = new_row[right] = value;
		left++;
		right--;
		value--;
	}

	pyramid(rows, current_row + 1, new_row);
}