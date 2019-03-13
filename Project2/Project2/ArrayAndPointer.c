#include <stdio.h>

int main(void) {
	char str1[] = "My String";
	char * str2 = "Your String";

	printf("%p \n", str1);
	printf("%p \n", str2);

	return 0;
}