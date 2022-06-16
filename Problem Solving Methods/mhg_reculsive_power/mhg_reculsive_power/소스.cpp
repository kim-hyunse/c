#include <stdio.h>

double power(float val, int pow) {

	if (pow == 0) {
		return (1.0);
	}
	else {
		return val * power(val, pow - 1);
	}


}

int main() {

	float val = 100;
	int pow = 3;
	double power(float val,int pow);
	printf("%f",power(val,pow));



	return 0;
}
