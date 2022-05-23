#include <stdio.h>
#pragma warning(disable:4996)


void cypher(FILE* myFile, FILE* myFile2) {

	char ch = '\0';

	myFile = fopen("original.txt", "r");
	myFile2 = fopen("cypher.txt", "w");


	if (myFile == NULL) {
		printf("ERROR:File Could Not Be Opened");
	}
	else {
		while ((ch = fgetc(myFile)) != EOF) {

			char de = ch + 1;
			fputc(de, myFile2);
		}

	}
	fclose(myFile);
	fclose(myFile2);
}
void decrypted(FILE* myFile, FILE* myFile2) {

	char ch = '\0';

	myFile = fopen("cypher.txt", "r");
	myFile2 = fopen("decrypted.txt", "w");


	if (myFile == NULL) {
		printf("ERROR:File Could Not Be Opened");
	}
	else {
		while ((ch = fgetc(myFile)) != EOF) {

			char de = ch - 1;
			fputc(de, myFile2);
		}

	}
	fclose(myFile);
	fclose(myFile2);
}
int main() {

	FILE* myFile;
	FILE* myFile2;
	FILE* myFile3;

	myFile = fopen("original.txt", "r");
	myFile2 = fopen("cypher.txt", "w");
	myFile3 = fopen("decrypted.txt", "w");

	cypher(myFile, myFile2);
	decrypted(myFile2, myFile3);







	return 0;
}