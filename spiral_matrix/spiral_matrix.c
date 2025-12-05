#include <stdio.h>
#include <stdlib.h> 
#include "spiral_matrix.h"
#include <math.h>
// function definition
void spiral_matrix(int row, int numbers[MAX_SIZE][MAX_SIZE]) {
	int right = 0;
	int down = 0;
	int value = 0, size = 1; // size is the length of one side of current layer

	while(value < row * row && right < row) {
		down = 0;
		numbers[0][right] = ++value;

		for(int i = down + 1; i < size && i < row; i++, down++) {
			numbers[i][right] = ++value;
		}
		// now down is at the bottom of the current layer
		for(int i = right - 1; i >= 0; i--) { // move left
			numbers[down][i] = ++value;
		}

		right++;
		size++;
	}

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < row; j++) {
			printf("%4d ", numbers[i][j]);
		}
		printf("\n");
	}
}