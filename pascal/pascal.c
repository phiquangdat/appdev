// function definition
int factorial(int n) {
	if (n == 0) return 1; 
	else return n * factorial(n - 1);
}

int n_choose_k(int n, int k) {
	return factorial(n) / (factorial(k) * factorial(n - k));
}