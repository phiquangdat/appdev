#include <stdio.h>
// function definition
int factorial(int n) {
	if (n == 0) return 1; 
	else return n * factorial(n - 1);
}

int n_choose_k(int n, int k) {
	return factorial(n) / (factorial(k) * factorial(n - k));
}

void pascal_by_shoulder_add(int a[], int row, int current_row){
	for(int i = 0; i <= current_row; i++)
		printf("%5d", a[i]);
	printf("\n");
	
	if(row == current_row) return; //we are at the last row
	int b[100] = {1}; // new row
	for(int i = 1; i <= current_row; i++){ //do shoulder add
		b[i] = a[i-1] + a[i];
	}
	b[current_row + 1] = 1; //the last element in the new row
	pascal_by_shoulder_add(b, row, current_row + 1);
}
