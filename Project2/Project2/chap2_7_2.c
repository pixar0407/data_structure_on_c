#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
int main(void) {
	char s[] = "amobile";
	char t[] = "uto";
	char string[MAX_SIZE];
	char temp[25] = "\0"; // string에 [25]와 같이 범위를 지정해 주지 않고, 초기화 하면 문제가 발생한다.
	int i = 0;

	strncpy(temp, s, 1);
	printf("temp : %s\n", temp);
	strcat(temp, t);
	printf("temp : %s\n", temp);
	strcat(temp, (s + 1));

	printf("temp : %s\n", temp);

	return 0;
}
void append(char *dst, char c) {
	char *p = dst;
	while (*p != '\0') p++; // 문자열 끝 탐색
	*p = c;
	*(p + 1) = '\0';
}