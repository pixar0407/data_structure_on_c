#include <stdio.h>  //
#include <stdlib.h> // atoi �Լ��� ����� ��� ����
#include <string.h> //strlen, strcpy �Լ��� ����� ��� ����
void append(char *dst, char c);
void main(void) { //+-*���� �̷��� ���� string���� *���� ���ִ� �Լ�
	char str[] = "1-0*0-1";
	char rearranged[101] = { "" };
	char temp[101] = { "" };//���ӵ� ����
	char mul[101] = { "" };
	
	int len_str = strlen(str);
	int i, j;

	int p;
	char p_string[101] = { "" };

	for (i = 0; i <= len_str; i++) { //������ �� ������ ��ĭ �� ���� �ؿ� else�� �ɸ��� �ؼ� ������ ���ڱ���Ȯ��!
		if (str[i] >= '0'&&str[i] <= '9') {
			append(temp, str[i]);
		}
		else if (str[i] == '+') {
			strcat(rearranged, temp);
			append(rearranged, '+');
			temp[0] = '\0';
		}
		else if (str[i] == '-') {
			strcat(rearranged, temp);
			append(rearranged, '-');
			temp[0] = '\0';
		}
		else if (str[i] == '*') {
			i++;
			while (str[i] >= '0'&&str[i] <= '9') {
				append(mul, str[i]);
				i++;
			}
			p=atoi(temp)*atoi(mul);
			sprintf(p_string, "%d", p);
			strcat(rearranged, p_string);
			temp[0] = '\0';
			mul[0] = '\0';
			i--;
		}
		
	}
	if (temp != 'W0') strcat(rearranged, temp);
	printf("%s\n", rearranged);
}
void append(char *dst, char c) {//���ڿ��� ���� ���ڸ� �߰��ϴ� �Լ�
	char *p = dst;
	while (*p != '\0') p++; // ���ڿ� �� Ž��
	*p = c;
	*(p + 1) = '\0';
}