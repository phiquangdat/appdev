#pragma once
#include <stdio.h>
// there are usually 3 parts in a header file:
// constant declarations, struct/class definitions, function declarations

// function declarations
int factorial(int n);
int n_choose_k(int n, int k);
void pyramid(int rows, int current_row, int* numbers, FILE* fp);