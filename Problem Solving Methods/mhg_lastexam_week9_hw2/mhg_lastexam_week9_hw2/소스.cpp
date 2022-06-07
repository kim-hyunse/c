#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

bool read_num(const char* file) {
	FILE* pfile;
	pfile= fopen(file, "r");
	int num=0;
	int a;
	int sum;
	
	

	if (pfile == NULL) {
		return false;
	}
	while (fscanf(pfile, "%d ", &num) == 1) {
		int total=0;
		int i = 0;
		
		while (fscanf(pfile, "%d ", &sum) == 1) {

			total += sum;
			i++;

			if (i == num) {
				printf("%lf\n", (double)total / num);
				break;
			}
		}
	}
		
	fclose(pfile);
	return true;
}



int main() {
	


	if (!read_num("test.txt")) {
		return -1;
	}
	


	return 0;
}