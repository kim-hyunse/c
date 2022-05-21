
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct {
	char RRN[14]; // constraint: unique
	char name[20];
	float salary;
	float bonus; // constraint: bonus < salary
} employee[1000];

struct{
	char RRN[14]; 
	char name[20];
	float salary;
	float bonus;}
inform[5] = {{"0206225527563","Yun",2000,300},
	{"9703092155463","Kim",1751,2000},
	{"0304012228465","Lee",300,20},
	{"0304012228465","Min",800,60},
	{"8807561234567","Park",712,634}};

int search(int i, char str1[], char str2[]) {
	int re;
	
	for (i = 0; i < 5; i++) {

		re = strcmp(str1, str2);
		                   
	}
	return re;

}

	
	int main(){
		
		
		for ( int i = 0; i < 5; i++)
		{         int j=0;
			
				if (search(j,inform[i].RRN, employee[j].RRN) != 0) {

					
					  if (inform[i].salary > inform[i].bonus) {

						strcpy(employee[i].RRN, inform[i].RRN);
						strcpy(employee[i].name, inform[i].name);
						employee[i].salary = inform[i].salary;
						employee[i].bonus = inform[i].bonus;
					   printf("RRN: %s, name: %s, salary:% f, bonus: %f\n", employee[i].RRN, employee[i].name, employee[i].salary, employee[i].bonus);
					 
					  }
					

					  else {
						
						printf("error:salary is smaller than bonus\n");
					
					  }
					

				}
				else {
					printf("error:same RRN\n");
				
				}

            
			}
			

		

		return 0;
}