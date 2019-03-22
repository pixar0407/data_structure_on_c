#include <stdio.h>
#include <string.h>
void append(char *dst, char c);
int main(void) {
	char str[101]; 
	char middle[101] = {""};
	int i = 0;

	char c;
	int ans = 0;
	int length = 0; 

	scanf("%s", &str);
	printf("%s\n", str);
	length = strlen(str);
	printf("length : %d\n", length);

	for (i = 0; i < length; i++) {
		switch (str[i]) {
		case '+': {
				printf("+\n");
				middle[0] = '\0';
				break;
			}
		case '-': printf("-\n"); break;
		case '*': printf("*\n"); break;

		default: {
				printf("숫자 : \n");
				printf("1: %s\n", middle);
				append(middle,str[i]);
				printf("2: %s\n", middle);
				break;
			}
		}
	}

}
void append(char *dst, char c) {
	char *p = dst;
	while (*p != '\0') p++; // 문자열 끝 탐색
	*p = c;
	*(p + 1) = '\0';
}