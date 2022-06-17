#include <stdio.h>
#include <string.h>

int my_strlen(const char* str) {

	int i=0;

	for (i = 0; i < 20; i++) {
    
		if (str[i] == '\0') { break; }
	   	
	}
	
	return i;
}

int main() {


	char str[20] = "hello_world!";
	str[5] = 0;



	printf("my_len(%d) vs len(%d) %s\n",my_strlen(str),strlen(str), str);


	return 0;
}