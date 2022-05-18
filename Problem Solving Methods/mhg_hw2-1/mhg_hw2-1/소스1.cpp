#include <stdio.h>
#include <string.h>
#define NUM_TEST_SET 5

int Search_String(char* string, char* search) {
	
	
	int cursor = 0, i=0, h=0;
	if (string[cursor] == search[i])
	{
		for (i = strlen(string); i <256; i++) {
			if (string=search) {
				h++;
			
			} 
			else {
				i++;
			}
		}
		cursor++; /* move the cursor on the string */
	}
	return 0;
}


int main() {

	char test_str[NUM_TEST_SET][256] = { "Is your name Bob?","No my name is Rob.",
		"Hello, Rob.","A thief named hong gil dong lived with friends named hong gil don and hong gil ja in a village named hong gil dong village.",
		"A thief named hong gil dong lived with friends named hong gil don and hong gil ja and hhhong gil dong and kong gil dong and honggil dong and hong gil donggg in a village named hong gil dong village" };
	char test_search_str[NUM_TEST_SET][128] = { "name","name","name","hong gil dong","hong gil dong" };

	for (int t = 0; t < NUM_TEST_SET; t++) {


		char* str = test_str[t];
		char* search_str = test_search_str[t];

		int num_matches = Search_String(str, search_str);
		printf("\n//---Experiment(%d)---\n", t + 1);
		printf("[String:] %s\n", str);
		printf("[Search:] %s\n", search_str);
		printf("[Num Matches:] %d\n", num_matches);
		
		}
	return 0;
}