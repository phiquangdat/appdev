#include <stdio.h>
#include "screen.h"
#include <time.h>
#include <stdlib.h> 
// function definition

int factorial(int n) {
	if (n == 0) return 1; 
	else return n * factorial(n - 1);
}

int n_choose_k(int n, int k) {
	return factorial(n) / (factorial(k) * factorial(n - k));
}

int random_number(int position, int total_numbers) {
    if (position < total_numbers / 4)
        return rand() % 90 + 10;
    else
        return rand() % 900 + 100; 
}

void hexagon_matrix(int n, int current_row, int *index, int *numbers, int total_numbers, FILE *fp) {
    int total_rows = 2 * n - 1;
    if (current_row >= total_rows) return; 

    int row_length; // number of element in current row
    if (current_row < n) row_length = n + current_row; // top half of the matrix     
    else row_length = 3*n - 2 - current_row; // bottom half, max length of first shrinks by 1 each next row

    int *row_nums = malloc(row_length * sizeof(int));
    if (!row_nums) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    } // new row
    for (int i = 0; i < row_length; i++) {
        row_nums[i] = numbers[*index]; // take from shuffled array
        (*index)++;
    }

    gotoXY(40 - row_length * 2, 10 + current_row);
    for (int i = 0; i < row_length; i++)
        printf("%4d", row_nums[i]);
    printf("\n");

    int indent = (total_rows - row_length) * 2; // total_rows acts as middle row length

    for (int i = 0; i < indent; i++) 
        fputc(' ', fp);

	for (int i = 0; i < row_length; i++)
    {
        fprintf(fp, "%4d", row_nums[i]);
    }
    fprintf(fp, "\n");

    hexagon_matrix(n, current_row + 1, index, numbers,total_numbers, fp);

}