#include <stdio.h> //2.7 String
#define MAX_LEN 101
int main(void) {
	char s[MAX_LEN] = "asd";
	char h[MAX_LEN] = "qwe";
	strncat(s, h, 2);

	printf("%s", s);
	return 0;
}