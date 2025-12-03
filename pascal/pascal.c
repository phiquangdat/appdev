#include <stdio.h>
#include "screen.h"
// function definition
int factorial(int n) {
	if (n == 0) return 1; 
	else return n * factorial(n - 1);
}

int n_choose_k(int n, int k) {
	return factorial(n) / (factorial(k) * factorial(n - k));
}

void pascal_by_shoulder_add(int a[], int row, int current_row){
	if(row == current_row) return; //we are at the last row

	gotoXY(40 + (row - current_row) * 5, 10 + current_row * 2);
	for(int i = 0; i <= current_row * 2; i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");

	int b[100] = {1}; // new row
	b[1] = a[0] + a[1];
	for(int i = 2; i <= (current_row + 1) * 2; i++){ //do shoulder add
		b[i] = a[i - 2]  + a[i - 1] + a[i];
	}
	b[current_row * 2 + 2] = 1; //the last element in the new row
	pascal_by_shoulder_add(b, row, current_row + 1);
}
