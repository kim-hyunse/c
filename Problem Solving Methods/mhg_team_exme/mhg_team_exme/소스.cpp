//------ Problem Solving Method Team project
//MEMBER INVOLVED - 202135506 KWON SO YOUNG

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

struct registration {
    int tag;
    char date[20];
    char fee_paid[10];
    char name[25];
    int age;
    char organization[35];
    char job[15];
};
struct NODE {
    int tag;
    char date[20];
    char fee_paid[10];
    char name[25];
    int age;
    char organization[35];
    char job[15];
    struct NODE* next;
};

typedef struct registration registration;

void readFile(struct registration persons[], struct NODE* head);
void search_choi_in_struct(struct registration persons[]);
void search_gachon_in_struct(struct registration persons[]);
void age_group(struct registration persons[], FILE* fp);//sort by age group
void print_member(struct registration persons[], FILE* fp, int j);//print struct member in txt file
void readList(struct NODE* head);
void search_choi_in_list(struct NODE* head);
void search_gachon_in_list(struct NODE* head);

int main() {

    int i = 0;
    struct registration persons[MAX];
    struct registration tmp[MAX];
    struct NODE node[MAX];
    struct NODE* head;
    head = (struct NODE*)malloc(sizeof(struct NODE));
    if (head) {
        head->next = node;
        for (int i = 0; i < MAX - 1; i++) {
            node[i].next = &node[i + 1];
        }
        node[MAX - 1].next = NULL;
    }
    else {
        printf("List error");
        exit(1);
    }

    readFile(persons, head);
    readList(head);

    //p 1-1 code
    search_choi_in_struct(persons);
    search_choi_in_list(head);
    //p 2 code
    search_gachon_in_struct(persons);
    search_gachon_in_list(head);

    //P 3-1 code
    //sort by tag number - using selection sort 
    for (i = 0; i < 30; i++) {
        for (int j = i + 1; j < 30; j++) {

            if (persons[i].tag > persons[j].tag) {
                tmp[i] = persons[i];
                persons[i] = persons[j];
                persons[j] = tmp[i];
            }
        }
    }

    printf("//------ Sorted by TAG number ------//\n");
    for (int j = 0; j < 30; j++) {
        printf("%d %s %s %s %d %s %s", persons[j].tag,
            persons[j].date,
            persons[j].fee_paid,
            persons[j].name,
            persons[j].age,
            persons[j].organization,
            persons[j].job);
    }

    //P 3-1 finish

    //P 5-1 sort by age group using selection sort
    for (i = 0; i < 30; i++) {

        for (int j = i + 1; j < 30; j++) {

            if (persons[i].age > persons[j].age) {
                tmp[i] = persons[i];
                persons[i] = persons[j];
                persons[j] = tmp[i];

            }
        }
    }
    FILE* fp1 = fopen("sorted_data.txt", "w");

    age_group(persons, fp1);

    fclose(fp1);

    //P 5-1 finish
    return 0;

}

void readFile(struct registration persons[], struct NODE* head) {
    FILE* fpointer = fopen("registration_data.txt", "r"); //파일명 확인하세요
    int i = 0;
    struct NODE* p = head->next;
    if (fpointer == NULL) {
        printf("file not found");
        exit(1);
    }
    else {
        char buffer[1024];
        char* field;
        int field_number;
        // input text file data  struct persons 에 저장
        while (fgets(buffer, 1024, fpointer) != NULL)
        {

            field_number = 0;
            field = strtok(buffer, "/");
            while (field)
            {
                switch (field_number)
                {
                case 0:
                    persons[i].tag = atoi(field);
                    p->tag = atoi(field);
                    break;
                case 1:
                    strcpy(persons[i].date, field);
                    strcpy(p->date, field);
                    break;
                case 2:
                    strcpy(persons[i].fee_paid, field);
                    strcpy(p->fee_paid, field);
                    break;
                case 3:
                    strcpy(persons[i].name, field);
                    strcpy(p->name, field);
                    break;
                case 4:
                    persons[i].age = atoi(field);
                    p->age = atoi(field);
                    break;
                case 5:
                    strcpy(persons[i].organization, field);
                    strcpy(p->organization, field);
                    break;
                case 6:
                    strcpy(persons[i].job, field);
                    strcpy(p->job, field);
                    break;
                }
                field = strtok(NULL, "/");
                field_number++;
            }
            i++;
            p = p->next;
        }
        fclose(fpointer);
    }
}
void readList(struct NODE* head) { //리스트 저장잘되어있나 출력용, main에서 readList(head);로 호출하시면 됩니다
    struct NODE* p = head->next;
    printf("readList\n");
    while (p) {
        printf("%d %s %s %s %d %s %s", p->tag,
            p->date,
            p->fee_paid,
            p->name,
            p->age,
            p->organization,
            p->job);
        p = p->next;
    }
}
void search_gachon_in_struct(struct registration persons[]) {
    printf("//------ Search Gachon University in struct ------//\n");
    for (int i = 0; i < 30; i++) {
        char* field = persons[i].organization;
        
        if (strcmp(field, "Gachon University") == 0) {
            printf("%d %s %s %s %d %s %s", persons[i].tag,
                persons[i].date,
                persons[i].fee_paid,
                persons[i].name,
                persons[i].age,
                persons[i].organization,
                persons[i].job);
        }
    }
    printf("\n");
}
void search_choi_in_struct(struct registration persons[]) {
    printf("//------ Search by Choi in struct ------//\n");
    for (int i = 0; i < 30; i++) {
        char* field = strtok(persons[i].name, " ");
        field = strtok(NULL, " ");
        if (strcmp(field, "Choi") == 0) {
            printf("%d %s %s %s %d %s %s", persons[i].tag,
                persons[i].date,
                persons[i].fee_paid,
                persons[i].name,
                persons[i].age,
                persons[i].organization,
                persons[i].job);
        }
    }
    printf("\n");
}

void search_gachon_in_list(struct NODE* head){
    struct NODE* p = head->next;
    printf("//------ Search Gachon University in list ------//\n");
    for (int i = 0; i < 30; i++) {
        char* field = p->organization;
       
        if (strcmp(field, "Gachon University") == 0) {
            printf("%d %s %s %s %d %s %s", p->tag,
                p->date,
                p->fee_paid,
                p->name,
                p->age,
                p->organization,
                p->job);
        }
        p = p->next;
    }
    printf("\n");
}
void search_choi_in_list(struct NODE* head)
{
    struct NODE* p = head->next;
    printf("//------ Search by Choi in list ------//\n");
    for (int i = 0; i < 30; i++) {
        char* field = strtok(p->name, " ");
        field = strtok(NULL, " ");
        if (strcmp(field, "Choi") == 0) {
            printf("%d %s %s %s %d %s %s", p->tag,
                p->date,
                p->fee_paid,
                p->name,
                p->age,
                p->organization,
                p->job);
        }
        p = p->next;
    }
    printf("\n");
}
void print_member(struct registration persons[], FILE* fp, int j) {

    fprintf(fp, "%d %s %s %s %d %s %s", persons[j].tag,
        persons[j].date,
        persons[j].fee_paid,
        persons[j].name,
        persons[j].age,
        persons[j].organization,
        persons[j].job);

}

void age_group(struct registration persons[], FILE* fp) {

    fprintf(fp, "--------Age group :10 - 19--------\n");
    for (int i = 0; i < 30; i++) {
        if (persons[i].age < 20) {
            print_member(persons, fp, i);
        }
    }
    fprintf(fp, "--------Age group :20 - 29--------\n");
    for (int i = 0; i < 30; i++) {
        if (persons[i].age < 30 && persons[i].age > 19) {
            print_member(persons, fp, i);
        }
    }
    fprintf(fp, "--------Age group :30 - 39--------\n");
    for (int i = 0; i < 30; i++) {
        if (persons[i].age < 40 && persons[i].age > 29) {
            print_member(persons, fp, i);
        }
    }
    fprintf(fp, "--------Age group :40 - 49--------\n");
    for (int i = 0; i < 30; i++) {
        if (persons[i].age < 50 && persons[i].age > 39) {
            print_member(persons, fp, i);
        }
    }
    fprintf(fp, "--------Age group :50 - 59--------\n");
    for (int i = 0; i < 30; i++) {
        if (persons[i].age < 60 && persons[i].age > 49) {
            print_member(persons, fp, i);
        }
    }
    fprintf(fp, "--------Age group :60 - 69--------\n");
    for (int i = 0; i < 30; i++) {
        if (persons[i].age < 70 && persons[i].age > 59) {
            print_member(persons, fp, i);
        }
    }
    fprintf(fp, "--------Age group :70 - 79--------\n");
    for (int i = 0; i < 30; i++) {
        if (persons[i].age < 80 && persons[i].age > 69) {
            print_member(persons, fp, i);
        }
    }
}


