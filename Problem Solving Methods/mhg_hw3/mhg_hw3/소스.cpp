#include <stdio.h>


int bs(int list[], int lo, int hi, int key) {
	int mid;
	if (lo > hi)
		return -1;
	mid = (lo + hi) / 2;
	if (list[mid] == key)
		return mid;
	else if (list[mid] > key)
		return bs(list, lo, mid- 1, key);
	else if (list[mid] < key)
		return bs(list, mid + 1, hi, key);
	return
		-1;
}

int main() {
	int list[] = { 5,10,15,25,45};
	int lo = 2;
	int hi = 5;
	int key = 5;
	int bs(int list[], int lo, int hi, int key);
	printf("lo = %d \n", lo);
	printf("hi = %d \n", hi);
	printf("key = %d \n", key);
	printf("%d", bs(list, lo, hi, key));








	return 0;
}