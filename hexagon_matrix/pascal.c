#include <stdio.h>
#include "screen.h"
#include <time.h>
// function definition
int factorial(int n) {
	if (n == 0) return 1; 
	else return n * factorial(n - 1);
}

int n_choose_k(int n, int k) {
	return factorial(n) / (factorial(k) * factorial(n - k));
}

void pascal_by_shoulder_add(int a[], int row, int current_row){
	srand(time(NULL));
	if(row == current_row) return; //we are at the last row


	gotoXY(40 + (row - current_row) * 2, 10 + current_row * 2);
	for(int i = 0; i <= current_row; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n");

	int b[100] = {1}; // new row
	for(int i = 0; i <= (current_row + 1); i++){ //do shoulder add
		if(i <= 0.25 * (current_row + 1)) printf("%4d", rand() % 90 + 10);
		else printf("%4d", rand() % 900 + 100); 
	}
	pascal_by_shoulder_add(b, row, current_row + 1);
}
