#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
int main(void) {
	char s[] = "amobile";
	char t[] = "uto";
	char string[MAX_SIZE];
	char temp[25] = "\0"; // string�� [25]�� ���� ������ ������ ���� �ʰ�, �ʱ�ȭ �ϸ� ������ �߻��Ѵ�.
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
	while (*p != '\0') p++; // ���ڿ� �� Ž��
	*p = c;
	*(p + 1) = '\0';
}