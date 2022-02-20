#include <stdio.h>

int main()

{
	char message[] = "Program";
	char names[10][20] = { "Hong Gil Dong",
		"cha1","cha2","cha3","cha4","cha5" };

	puts(message);
	puts(names[4]);

	return 0;
}