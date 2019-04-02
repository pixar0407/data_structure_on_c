#include <stdio.h>
#include <stdlib.h> 
#include <string.h> //HW1-1�� �ַ��2. ���� �ַ�� ��� ���� ����ȭ�� ����.
void append(char *dst, char c);
void func(char *str, char* ans, int length, int *depth, char c); //recursion�� �Ͼ�� �Լ�
void main(void) {
	char str[101]; //������ ����ڷ� ���� �޴� �Է��Դϴ�. �Һ�
	char ans[101] = { "" }; //recursion�� �ݺ��ϸ鼭 ���ڿ� '/'�� ä��������.

	int length = 0; //���ʷ� ����ڷ� ���� ���� �Է��� ����. recursion�ϴ� ���߿��� �Һ�
	int depth = 0; //ans�� ���� '����'�� ����. depth�� length�� ��ġ�ϴ��� Ȯ���Ͽ� recursion�� �����.

	scanf("%s", str);
	length = strlen(str);

	func(str, ans, length, &depth, 'n');
}
void append(char *dst, char c) {
	char *p = dst;
	while (*p != '\0') p++; // ���ڿ� �� Ž��
	*p = c;
	*(p + 1) = '\0';
}
void func(char *str, char* ans, int length, int *depth, char c) {//str�Һ�, length ��� || ans�� depth ��ȭ
	int temp_depth; //recursion ���� �� ans�� depth�� ���������� update���ֱ� ���� �Լ� �� ������.
	char temp_ans[101];

	switch (c) {
	case '/': {
		append(ans, '/');
		append(ans, str[*(depth)]);
		(*depth)++;
		break; }
	default: {
		append(ans, str[*(depth)]);
		(*depth)++;
		break; }
	}
	strcpy(temp_ans, ans);//������ �ӽ� ����
	temp_depth = *depth;

	if (length != *depth) {
		func(str, ans, length, depth, '/');
		strcpy(ans, temp_ans); //���� ��� �� �ֱ�ȭ �Ǿ��� ������ recursion ���� ��, ans depth ���������� update
		*depth = temp_depth;
		func(str, ans, length, depth, str[(*depth)]);
	}
	else {
		printf("%s\n", ans);
		ans[0] = '\0'; //���� ��� �� ans�� depth�� �ʱ�ȭ.
		*(depth) = 0;
	}
}
