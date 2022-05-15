#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
struct {

	char name[20];
	float share;
	float ratio;
}Company[5];
int main() {
	
	for (int i = 0; i < 5; i++)
	{
		printf("Type (%d) campany's name, share, ratio \n",i+1);
		scanf("%s %f %f", &Company[i].name, &Company[i].share, &Company[i].ratio);

	}


	for (int i = 0; i < 5; i++)
	{
		printf("[%d] %s's stock price : %lf \n", i + 1, Company[i].name, Company[i].share * Company[i].ratio);
	}




	return 0;
}