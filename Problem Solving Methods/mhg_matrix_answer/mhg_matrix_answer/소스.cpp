#include <stdio.h>
#include <string.h>

void mat_mult(float A[3][3], float B[3][3], float C[3][3]) {

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {
			C[i][j] = 0;
			for (int h = 0; h < 3; h++) {
				C[i][j] += A[i][h] * B[h][j];
			}
		}
}
}

void print_mat3(const float a[3][3]) {

	for (int i = 0; i < 3; i++) {
		printf("[");
		for (int j = 0; j < 3; j++) {
			printf("%f", a[i][j]);
		}
		printf("]\n");
	}
}

int main() {

	float A[3][3] = { {1,2,3},{4,5,6}, {7,8,9} };
	float B[3][3] = { {1,2,1},{2,4,6}, {7,2,5} };
	float C[3][3];

	mat_mult(A, B, C);

	printf("//---A\n");
	print_mat3(A);
	printf("//---B\n");
	print_mat3(B);
	printf("//---C\n");
	print_mat3(C);


	return 0;
}
