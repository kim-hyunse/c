#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

struct CAR {
	char name[20];
	int year;
};// car[2] = { {"Avante", 2007 },{"Sonata", 2008 } };

int main() {
	CAR car[2] = { {"Avante", 2007 },{"Sonata", 2008 } };
	CAR car_2[2];

	FILE* myfile;
	FILE* myfile2;
	myfile = fopen("cars.txt", "w");
	int i = 0;
	int j = 0;
	if (myfile == NULL) {
		printf("file cannot open");
		exit(1);
	}

	else {
		while (i<2) {
			fprintf(myfile, "%s %d \n", car[i].name, car[i].year);
			i++;
		}
	}
	fclose(myfile);
	myfile2 = fopen("cars.txt", "r");

	
	while (fscanf(myfile2, "%s %d", &car_2[j].name, &car_2[j].year)==2) {

		printf("%s %d\n", car_2[j].name, car_2[j].year);
		j++;
	}
	


	fclose(myfile2);
	return 0;
}