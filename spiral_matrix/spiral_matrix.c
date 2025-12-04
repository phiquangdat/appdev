#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <stdio.h>
#include <math.h>
// function definition
void spiral_matrix(int row, int** numbers, FILE* fp) {
	int right = 0;
	int down = 0;
	int count = 0, size = 1;

	while(count < row * row && right < row) {
		down = 0;
		numbers[0][right] = ++count;

		for(int i = down + 1; i < size && i < row; i++, down++) {
			numbers[i][right] = ++count;
		}

		for(int i = right - 1; i >= 0; i--) {
			numbers[down][i] = ++count;
		}

		right++;
		size++;
	}

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < row; j++) {
			printf("%4d ", numbers[i][j]);
			fprintf(fp, "%4d ", numbers[i][j]);
		}
		printf("\n");
		fprintf(fp, "\n");
	}
}