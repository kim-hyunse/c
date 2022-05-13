#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM_TEST_SET 8
#pragma warning(disable:4996)

void Divide_Search_String(char* search,char* first, char* second) 
{
	char str[10]="hong dong";
	first = strtok(str, " "); 

	if (first != NULL) {
		second = strtok(NULL, " ");}
}

int Exact_match(char* string, char* search)
{
	int i, j, count;
	count = 0;
	for (i = 0; string[i] != NULL; i++)
	{
		int count2 = 0;
		for (j = 0; search[j] != NULL; j++)
		{
			if (string[i + j] == search[j])
			{
				count2++;
				
			}
			else
				continue;
		}

		if (j == count2)
			count++;
	}
	return count;
}

int Partial_Match_Count( char* string, char* first, char* second) {
	int p, q,r, count3;
	count3 = 0;
	for (p = 0; string[p] != NULL; p++)
	{
		int count4= 0;
		for (q = 0; first[q] != NULL; q++)
		{
			for (r = 0; second[r] != NULL; r++)
			{
				if (string[r + q] == first[q])
					count4++;
				else
					continue;
			}
			
			
		}

		if (p == count4)
			count3++;
	}
	return count3;
}

int main() {
	char test_str[NUM_TEST_SET][256] = { "hello, mister monkey","hello, mister monkey","My name is hong gil dong.My brother is hong je dong. My sister is hong gilja,and her friend is hongdong.","hello, mister monkey",
	"A thief named hong gil dong lived with friends named hong gil don and hong gil ja in a village named hong gil dong village.","my name is lee jungho","my name is lee jungho",
	"A thief named hong gil dong lived with friends named hong gil don and hong gil ja and hhhong gil dong and kong gil dong and honggil dong and hong gil donggg in a village named hong gil dong village." };
	char test_search_str[NUM_TEST_SET][128] = { "money","m*y","hong*dong","mo*ey","lee*ho","lee*ha","hong*dong","hong*dong" };

	for (int t = 0; t < NUM_TEST_SET; t++)
	{
		char* str = test_str[t];
		char* search_str = test_search_str[t];
		char* first= search_str;
		char* second=search_str;
		printf("\n//---Experiment(%d)---\n", t + 1);
		printf("[String:] %s\n", str);
        Divide_Search_String(str,first, second);
	    printf("[Serach first:] %s\n", first);
		printf("[Serach second:] %s\n", second);

		Exact_match(search_str, first);
		Exact_match(search_str, second);
	
				
		int num_matches = Partial_Match_Count(str, first, second);
		printf("[Num matches] %d\n", num_matches);
	}
	return 0;
}