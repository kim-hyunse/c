#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

struct DATA {
	int num;
	char name[5];
	int age;
	char hobby[10];
} dataset[5] = { {0, "Kim", 39, "Tennis"},
	{1, "Ko", 15, "Soccer"},
	{2, "Lee", 17, "Soccer"},
	{3, "Choi", 21,"Tennis"},
	{4, "Park", 10, "Tennis"}};

struct INDEX {
	char name[5];
	int num;
} index[5] = { {"Kim", 0},
	{"Ko", 1 },
	{"Lee", 2},
	{"Choi", 3},
	{"Park" ,4} };

int main() {

	int i = 0; 
	int j = 0;
	index[i].name;
	dataset[j].name;
	
	printf("type name for print information\n");
	scanf("%s", index[i].name);
	

	for (j = 0; j < 5; j++) {
		if (strcmp(dataset[j].name, index[i].name) == 0) {

			printf("num: %d ,name: %s, age: %d, hobby: %s\n", dataset[j].num, dataset[j].name, dataset[j].age, dataset[j].hobby);

		}
		else {
			continue;
		}
	
	}
	return 0;
}