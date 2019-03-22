#include <stdio.h>
#include <string.h>
#include <stdlib.h>    // atoi �Լ��� ����� ��� ����
void append(char *dst, char c);
void check(char *str);
int main(void) {
	char str[101];
	int sol;

	scanf("%s", &str);
	scanf("%d", &sol);
	printf("sol : %d\n", sol);

	check(str);
}
void check(char *str) {
	int num[101] = { 0 };
	char operator[101] = { "" };
	char temp[101] = { "" };

	int len_str = strlen(str);
	char c;
	int i;
	int j = 0;
	int k = 0;
	
	printf("len_str : %d\n", len_str);
	for (i = 0; i <= len_str; i++) { //������ �� ������ ��ĭ �� ���� �ؿ� else�� �ɸ��� �ؼ� ������ ���ڱ���Ȯ��!
		if (str[i] >= '0'&&str[i] <= '9') {
			append(temp, str[i]);
		}
		else {
			num[j++]=atoi(temp);
			temp[0] = '\0';
			operator[k++] = str[i];
		} // ���� ���� �������� ���ͼ� ������ �� �� ����.
	}


	//���� ��� Ȯ��
	printf("operator : %s\n", operator);
	for (i = 0; i < 101; i++) {
		if (num[i])
			printf("%d\n", num[i]);
	}


	//num�� operator�� ������ ��ƺ���
	for (i = 0; i < 101; i++) {
		if (operator[i] == NULL) {
			break;
		} else {
			switch (operator[i]) {
			case '+': num[0] += num[i + 1]; break;
			case '-': num[0] -= num[i + 1]; break;
			default: num[0] *= num[i + 1]; break;
			}
		}
	}
	printf("���� : %d\n", num[0]);


}
void append(char *dst, char c) {
	char *p = dst;
	while (*p != '\0') p++; // ���ڿ� �� Ž��
	*p = c;
	*(p + 1) = '\0';
}