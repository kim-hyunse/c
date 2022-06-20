#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

#define MAX_NAME_LEN 8
#define MAX_PERSONS_LEN 30

struct PERSONAL {
    char name[MAX_NAME_LEN];
    int age;
    float salary;
};

void copy_element(const PERSONAL* src, PERSONAL* dest) {
    strcpy(dest->name, src->name);
    dest->age, src->age;
    dest->salary, src->salary;
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
    while (fscanf(pFile, "%s %d %f", &read_person.name, &read_person.age, &read_person.salary) == 3) {

        copy_element(&read_person, &persons[num]);
        persons[num].age = read_person.age;
        persons[num].salary = read_person.salary;
        num++;
    }
    fclose(pFile);
    *num_persons = num;
    return true;
}


bool write_thir(const char* fname, PERSONAL persons[], const int num_persons) {
    FILE* pFile;
    pFile = fopen(fname, "w");
    if (pFile == NULL) {
        printf("error: Cannot open the file:%s\n", fname);
        return false;
    }
    for (int i = 0; i < num_persons; i++) {
        int age = (persons[i].age / 10) * 10;

        if (age == 30) {
            persons[i].salary = persons[i].salary * 1.2;
            fprintf(pFile, "%8s %d %lf\n", persons[i].name, persons[i].age, persons[i].salary);
        }
        else {
            fprintf(pFile, "%8s %d %lf\n", persons[i].name, persons[i].age, persons[i].salary);
        }
    }
    fclose(pFile);
    return true;
}

bool write_four(const char* fname, PERSONAL persons[], const int num_persons) {
    FILE* pFile;
    pFile = fopen(fname, "w");
    if (pFile == NULL) {
        printf("error: Cannot open the file:%s\n", fname);
        return false;
    }
    for (int i = 0; i < num_persons; i++) {
        int age = (persons[i].age / 10) * 10;

        if (age == 40) {
            persons[i].salary = persons[i].salary * 1.1;
            fprintf(pFile, "%8s %d %lf\n", persons[i].name, persons[i].age, persons[i].salary);
        }
        else {
            fprintf(pFile, "%8s %d %lf\n", persons[i].name, persons[i].age, persons[i].salary);
        }
    }
    fclose(pFile);
    return true;
}

void group_by(const PERSONAL original[], const int num_persons, PERSONAL grouped[]) {

    int index = 0;
    for (int i = 0; i < num_persons; i++) {
        copy_element(&original[i], &grouped[index]);
        grouped[index].age = original[i].age;
        grouped[index].salary = original[i].salary;
        index++;
    }
}
void compare(const char* fname, const char* fname2, PERSONAL persons[], PERSONAL persons3[], const int num_persons) {
    FILE* pFile;
    pFile = fopen(fname, "r");
    FILE* pFile2;
    pFile2 = fopen(fname2, "r");
    for (int i = 0; i < num_persons; i++) {

        printf("%s %d %lf -> %lf ", persons[i].name, persons[i].age, persons[i].salary, persons3[i].salary);
        if (persons[i].salary != persons3[i].salary) {
            printf("different salary\n");
        }
        else {
            printf("same salary\n");
        }
    }
    fclose(pFile);
    fclose(pFile2);
}
int main() {

    PERSONAL persons[MAX_PERSONS_LEN];
    int num_persons = 0;

    if (!read_file("salary_v1.txt", persons, &num_persons)) {
        return -1;
    }



    PERSONAL four_ten[MAX_PERSONS_LEN];
    group_by(persons, num_persons, four_ten);

    if (!write_four("salary2.txt", four_ten, num_persons)) {
        return -1;
    }

    PERSONAL thir_twen[MAX_PERSONS_LEN];
    group_by(four_ten, num_persons, thir_twen);
    if (!write_thir("salary3.txt", thir_twen, num_persons)) {
        return -1;
    }
    compare("salary_v1.txt", "salary3.txt", persons, thir_twen, num_persons);

    return 0;

}

