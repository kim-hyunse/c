#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

void compress(FILE* myFile,FILE* myFile2) {

	char ch = '\0';

	myFile = fopen("address.txt", "r");
	myFile2 = fopen("compressed.txt", "w");


	if (myFile == NULL) {
		printf("ERROR:File Could Not Be Opened");
	}
	else {
		while ((ch = fgetc(myFile)) != EOF) {
			
			if (ch == '-'|| ch==' ') {
				continue;
			}
			fputc(ch, myFile2);
		}

	}
fclose(myFile);
fclose(myFile2);
}

void decompress(FILE* myFile2, FILE* myFile3) {
     char c[100];
	 char d[100];
	myFile2 = fopen("compressed.txt", "r");
	myFile3 = fopen("decompressed.txt", "w");
	while ((fgets(c,4, myFile2))&& (fgets(d,5, myFile2)) != NULL) {

		
		fprintf(myFile3, "%s - ", c);
		fprintf(myFile3, "%s   ", d);
		

	}
	fclose(myFile3);
}


int main() {
	
	FILE* myFile;
	FILE* myFile2;
	FILE* myFile3;

	myFile = fopen("address.txt", "r"); 
	myFile2 = fopen("compressed.txt", "w");
	myFile3 = fopen("decompressed.txt", "w");
	
	compress( myFile, myFile2);
	decompress( myFile2, myFile3);
	
	
	return 0;
}