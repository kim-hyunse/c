#include <stdio.h>


int sum_of(int a[], int n) {
	if (n == 1) {
		return a[n - 1];
	}
	else {
		
		return a[n - 1] + sum_of(a, n - 1);
	}
		

}


int main() {
	int a[] = { 20, 30, 10, 50, 15, 45, 80, 25 };
	int b = 4;
	int sum_of(int a[],int b);
	printf("%d", sum_of(a,b));


	return 0;
}


