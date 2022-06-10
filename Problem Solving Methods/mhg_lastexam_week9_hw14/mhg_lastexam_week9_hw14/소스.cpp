#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

struct EMPLOYEE {

	char name[20];
	char first[10];
	int salary;
	double aver;
	char count[15];
};


bool make_file(const char* file, EMPLOYEE* employee){

	FILE* pfile;
	pfile = fopen(file, "w");
	int i = 0;

	if (pfile == NULL) {
		printf("file open failed");
		exit(1);
		return false;
	}

	else {
		while (i < 5) {
			fprintf(pfile, "%s  %s  %d  %lf  %s\n", employee[i].name, employee[i].first,
				employee[i].salary, employee[i].aver, employee[i].count);
			i++;
		}
		

	}
	fclose(pfile);
	return true;
	
}

bool read_file(const char* file, const char* file2) {
	FILE* pfile;
	FILE* pfile2;
	pfile = fopen(file, "r");
	pfile2 = fopen(file2, "w");
	int j = 0;

	char name[20];
	char first[10];
	int salary;
	double aver;
	char count[15];

	while (fscanf(pfile, "%s %s %d %lf %s", &name, &first,
		&salary, &aver, &count) == 5) {

		fprintf(pfile2, "%s %s %d %lf %s \n", name, first,
			salary, aver, count);
		j++;
	}
	return true;

}

int main() {

	struct EMPLOYEE employee[5];
	employee[0] = { "Anthony", "A.J.", 10031, 7.82, "12/18/62" };
	employee[1] = { "Burrows", "W.K.", 10067, 9.14, "6/9/63" };
	employee[2] = { "Fain", "B.D", 10083, 8.79, "5/18/59" };
	employee[3] = { "Janney", "P.", 10095, 10.57, "9/28/62" };
	employee[4] = { "Smith", "G.J.",10105,8.50, "12/20/61" };


	if (!make_file("employee.txt",employee)) {
		return -1;
	}
	if (!read_file("employee.txt", "employee2.txt")) {
		return -1;
	}



	return 0;
}