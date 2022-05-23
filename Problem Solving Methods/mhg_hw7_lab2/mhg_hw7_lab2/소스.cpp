#include <stdio.h>
#pragma warning(disable:4996)





void bin(int decimal) {

	int a = 0;
	for (int j = 9; j >= 0; --j) {
		int result = decimal >> j & 1;
		if (result == 1) {
			a = 1;
			printf("%d", result);
			}
		else if (a == 1) { 
			printf("%d", result); }
	}
}


void oct(int decimal) {

	const char digits[9] = "01234567";
	char oct[12];
	oct[11] = '\0';

	for (int i = 0; i <11;  i++) {
		
		int result = (decimal >> i*3);

		oct[10-i] = digits[result & 7];

		

	}
printf("%s", oct);


}

void hex(int decimal) {

	const char digits[17] = "0123456789ABCDEF";
	char hex[9];
	hex[8] = '\0';

	for (int i = 0; i <8; i++) {
		int four_bits = (decimal >> i * 4);
		hex[7-i] =  digits[four_bits &0x0F];
		
	}
	printf("%s\n", hex);
	
	

}
int main() {



	for (int i = 1; i <= 1000; i++) {


		printf("DEC: %d   ", i);
		printf("   BIN:  ");
		bin(i);	
		printf("   OCT: ");
		oct(i);
        printf("   HEX:  ");
		hex(i);

	


	}


	return 0;
}