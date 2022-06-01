#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

#define MAX_REGION_LEN 12
#define MAX_CANDIDATE_LEN 12

struct PERSONAL {
	char region[MAX_REGION_LEN];
	int age;
	char candidate_voted[MAX_CANDIDATE_LEN];
};



void copy_element(const PERSONAL* src, PERSONAL* dest) {
	strcpy(dest->region, src->region);
	dest->age, src->age;
	strcpy(dest->candidate_voted, src->candidate_voted);
}


bool read_file(const char* fname, PERSONAL persons[], int* num_persons) {
	FILE* pFile;
	pFile = fopen(fname, "r");
	if (pFile == NULL) {
		printf("error: Cannot read the file:%s\n", fname);
		*num_persons = 0;
		return false;
	}
	PERSONAL read_person;
	int num = 0;
	while (fscanf(pFile, "%s %d %s", &read_person.region,
		&read_person.age,
		&read_person.candidate_voted) == 3) {

		copy_element(&read_person, &persons[num]);
		persons[num].age = read_person.age;
		num++;
	}
	fclose(pFile);
	*num_persons = num;
	return true;
}



void compute_percent(const int num_persons, PERSONAL persons[]) {

	FILE* pFile;
	pFile = fopen("vote.txt", "r");
	int index = 0;

	PERSONAL read_person;

	while (fscanf(pFile, "%s %d %s", &read_person.region, &read_person.age, &read_person.candidate_voted) == 3) {
		int Washington = 0;
		int Roosevelt = 0;
		int Lincoln = 0;
		for (int i = 0; i < num_persons; i++) {


			copy_element(&persons[i], &read_person);

			char ch = read_person.candidate_voted[0];

			if (ch == 'W') {
				Washington++;

			}

			else if (ch == 'L') {
				Lincoln++;

			}
			else if (ch == 'R') {
				Roosevelt++;

			}

		}

		float W = (float)Washington / (2000) * 100;
		float L = (float)Lincoln / (2000) * 100;
		float R = (float)Roosevelt / (2000) * 100;
		printf("Washington :%.1lf \nLincoln:%.1lf \nRoosevelt:%.1lf", W, L, R);
		break;


	}


	fclose(pFile);

}


int main() {

	PERSONAL persons[2000];

	int num_persons = 0;
	if (!read_file("vote.txt", persons, &num_persons)) {
		return -1;
	}

	compute_percent(num_persons, persons);



	return 0;

}

