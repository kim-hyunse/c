
#include <stdio.h>

struct CARS{
	int number;
	int miles;
	int gallons;
	
}cars[5] = {
	{25, 1450, 62},
	{36, 3240, 136},
	{44, 1792, 76},
	{52, 2360, 105},
	{68, 2114, 67},
};



int main() {
	
	for (int i = 0; i < 5; i++)
	{
	
			printf("car number is (%d),the miles driven by the car is (%d),the number of gallons used by each car is (%d) and the average miles per gallon achieved is approximately (%d) \n"
				, cars[i].number, cars[i].miles, cars[i].gallons, cars[i].miles / cars[i].gallons);
	}

	return 0;
}



