#pragma once
// there are usually 3 parts in a header file:
// constant declarations, struct/class definitions, function declarations

// function declarations
#include <stdio.h>
int factorial(int n);
int n_choose_k(int n, int k);
void hexagon_matrix(int n, int current_row, int *index, int *numbers, int total_numbers, FILE *fp);
int random_number(int position, int total_numbers);
