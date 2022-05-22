#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {

	FILE* myInFile, * myOutFile;
	char ch;
	myInFile = fopen("employee.txt", "r");
	if (myInFile == NULL) {
		printf("Could not open data.txt!\n");
		exit(1);
	}
	myOutFile = fopen("samedata.txt", "w");
	if (myOutFile == NULL) {
		printf("Could not open samedata.txt!\n");
		exit(1);
	}
	/* Read the input file one character at a time, and write
	the character to the output file. */
	while ((fscanf(myInFile,"%s  %s  %d  %f  %c")) != EOF)
	{
		fputc(ch, myOutFile);
	}
	fclose(myInFile);
	fclose(myOutFile);
	return 0;
}