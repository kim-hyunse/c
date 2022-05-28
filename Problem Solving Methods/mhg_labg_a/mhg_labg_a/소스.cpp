#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

#define MAX_NAME_LEN 8
#define MAX_HOBBY_LEN 8
#define MAX_PERSONS_LEN 30

struct PERSONAL {
	char name[MAX_NAME_LEN];
	int age;
	char hobby[MAX_HOBBY_LEN];
};

void copy_element(const PERSONAL* src, PERSONAL* dest) {
	strcpy(dest->name, src->name);
	dest->age, src->age;
	strcpy(dest->hobby, src->hobby);
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
	while (fscanf(pFile, "%s %d %s", &read_person.name, &read_person.age, &read_person.hobby) == 3) {

		copy_element(&read_person, &persons[num]);
		persons[num].age = read_person.age;
		num++;
	}
	fclose(pFile);
	*num_persons = num;
	return true;
}


bool write_file(const char* fname, const PERSONAL persons[], const int num_persons) {
	FILE* pFile;
	pFile = fopen(fname, "w");
	if (pFile == NULL) {
		printf("error: Cannot open the file:%s\n", fname);
		return false;
	}
	for (int i = 0; i < num_persons; i++) {

		fprintf(pFile, "%8s %d %8s\n", persons[i].name, persons[i].age, persons[i].hobby);
	}
	fclose(pFile);
	return true;
}

void group_by_age(const PERSONAL original[],const int num_persons, PERSONAL grouped[]) {

	int index = 0;
	for (int i = 0; i < num_persons; i++) {
		int age = (original[i].age / 10) * 10;
		if (age == 10) {
			copy_element(&original[i], &grouped[index]);
			grouped[index].age = original[i].age;
			index++;
		}
	}
	for (int i = 0; i < num_persons; i++) {
		int age = (original[i].age / 10) * 10;
		if (age == 20) {
			copy_element(&original[i], &grouped[index]);
			grouped[index].age = original[i].age;
			index++;
		}
	}
	for (int i = 0; i < num_persons; i++) {
		int age = (original[i].age / 10) * 10;
		if (age == 30) {
			copy_element(&original[i], &grouped[index]);
			grouped[index].age = original[i].age;
			index++;
		}
	}
	for (int i = 0; i < num_persons; i++) {
		int age = (original[i].age / 10) * 10;
		if (age == 40) {
			copy_element(&original[i], &grouped[index]);
			grouped[index].age = original[i].age;
			index++;
		}
	}

}


int main() {

	PERSONAL persons[MAX_PERSONS_LEN];
	int num_persons = 0;

	if (!read_file("personal.txt", persons, &num_persons)) {
		return -1;
	}

	PERSONAL group_age[MAX_PERSONS_LEN];
    group_by_age(persons, num_persons, group_age);

	if (!write_file("age.txt", group_age, num_persons)) {
		return -1;
	}
	


	return 0;

}


