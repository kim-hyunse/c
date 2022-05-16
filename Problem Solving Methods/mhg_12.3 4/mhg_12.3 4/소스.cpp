/*Write a C function named recent() that returns the later
date of any two dates passed to it. For example, if the dates
10/9/2001 and 11/3/2001 are passed to recent(), the second date
would be returned.
 12.3 4b Include the recent() function in a complete program. Store
the data structure returned by recent() in a separate date structure
and display the member values of the returned date.*/

#include <stdio.h>


struct Date
{
	int month;
	int day;
	int year;
}date1;

struct Date2
{
	int month;
	int day;
	int year;
}date2;

void recent(struct Date, struct Date2) {

	int total1 = date1.day + date1.month * 30 + date1.year * 360;
	int total2 = date2.day + date2.month * 30 + date2.year * 360;
	int recent;

	if (total1 > total2) {
		recent = total1;
	}
	else {
		recent = total2;
	}

}

int main() {

	int total1 = date1.day + date1.month * 30 + date1.year * 360;
	int total2 = date2.day + date2.month * 30 + date2.year * 360;


	printf("type some dates:day/month/year:\n");
	scanf_s("%d %d %d", date1.day, date1.month, date1.year);
	printf("%d /%d /%d", date1.day, date1.month, date1.year);
	printf("type another dates:day/month/year:\n");
	scanf_s("%d %d %d", date2.day, date2.month, date2.year);
	printf("%d /%d /%d", date2.day, date2.month, date2.year);
	if (total1 > total2) {
		printf("%d %d %d is recent than %d %d %d", date1.day, date1.month, date1.year, date2.day, date2.month, date2.year);
	}
	else {
		printf("%d %d %d is recent than %d %d %d", date2.day, date2.month, date2.year, date1.day, date1.month, date1.year);
	}

	return 0;
}
