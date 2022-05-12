//call by reference

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date
{
	int month;
	int day;
	int year;
}date;



void update_record(struct Date* co) {

	(*co).month = 1;
	(*co).day = 1;
	(*co).year = 2001;
}


int Days(struct Date,struct Date* co) {
	

		int tt = 30 * (co->month - date.month) + co->day - date.day + 360 * (co->year - date.year);

		return tt;

	}


int main(){


	update_record(&date);
	
	int total = 30 * ( date.month-1) + date.day-1+360 * ( date.year-2000);
	
	printf("%d months, %d years, %d days\n" ,date.month,date.year,date.day);
	printf("total days: %d \n",total);

	return 0;
}

