

#include <stdio.h>


struct Date
{	int month;
	int day;
	int year;
}date = {1,1,2000};

int nmonth = 0, nday = 0, nyear = 0;

int Days(struct Date, int nmonth, int nday, int nyear)
{
	int total=30 * (nmonth - date.month) + 360 * (nyear -date.year) + nday - date.day;

	return total;
	
}



int main() {


	
	printf("type the date:month, day, year\n");
	scanf_s("%d %d %d", &nmonth, &nday, &nyear);

	printf("total days: %d \n", 30 * (nmonth - date.month) + 360 * (nyear - date.year) + nday - date.day);

	return 0;
}