#include <stdio.h>

int iter_factorial(int n) {
	int result = 1;
	int k;
	for (k = 1; k <=n ; k++) {

		result = result * k;
	}
		
		printf("%d", result);
	return result;
}

int main() {
	int n = 0;
	printf("input a number\n");
	scanf_s("%d", &n);
	iter_factorial(n);
	

	return 0;
}