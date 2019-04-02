#include <stdio.h>  //HW1-2�� �ַ��1
#include <stdlib.h> // atoi �Լ��� ����� ��� ����
#include <string.h> //strlen, strcpy �Լ��� ����� ��� ����
void check(char *str, int target, int * none);
void append(char *dst, char c);
void func(char *str, char* ans, int length, int *depth, char c,int target, int * none); //recursion�� �Ͼ�� �Լ�
int zerohead(char *str);
void main(void) {
	int none = 0;

	char str[101]; //������ ����ڷ� ���� �޴� �Է��Դϴ�. �Һ�
	int target;//�ι�° �Է�
	char ans[101] = { "" }; //recursion�� �ݺ��ϸ鼭 ���ڿ� operator�� ä�������ϴ�. call by ref

	int length = 0; //���ʷ� ����ڷ� ���� ���� �Է��� ����. recursion�ϴ� ���߿��� �Һ�
	int depth = 0; //ans�� ���� '����'�� ����. depth�� length�� ��ġ�ϴ��� Ȯ���Ͽ� recursion�� �����.

	scanf("%s", &str);
	scanf("%d", &target);
	length=strlen(str);
	
	func(str, ans, length, &depth, 'n',target, &none);
	if (none == 0)
		printf("None\n");
}
void append(char *dst, char c) {//���ڿ��� ���� ���ڸ� �߰��ϴ� �Լ�
	char *p = dst;
	while (*p != '\0') p++; // ���ڿ� �� Ž��
	*p = c;
	*(p + 1) = '\0';
}
void func(char *str,char* ans, int length, int *depth, char c, int target, int * none) {//str�Һ�, length ��� - ans�� depth �� ��� ����.
	int temp_depth; //recursion ���� �� ans�� depth�� ���������� update���ֱ� ���� �Լ� �� ������.
	char temp_ans[101];

	switch (c) {
	case '+': {
		append(ans, '+');
		append(ans, str[*(depth)]);
		(*depth)++;
		break; }
	case '*': {
		append(ans, '*');
		append(ans, str[*(depth)]);
		(*depth)++;
		break; }
	case '-': {
		append(ans, '-');
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

	if (length != *depth) { //1) recursion�� ��� �Ͼ�� �ϴ� ���
		func(str, ans, length, depth, '+', target, none);
		strcpy(ans, temp_ans); //���� ��� �� �ʱ�ȭ �Ǿ��� ������ recursion ���� ��, ans depth ���������� update
		*depth = temp_depth;

		func(str, ans, length, depth, '*', target, none);
		strcpy(ans, temp_ans); //���� ��� �� �ʱ�ȭ �Ǿ��� ������ recursion ���� ��, ans depth ���������� update
		*depth = temp_depth;

		func(str, ans, length, depth, '-', target, none);
		strcpy(ans, temp_ans); //���� ��� �� �ʱ�ȭ �Ǿ��� ������ recursion ���� ��, ans depth ���������� update
		*depth = temp_depth;

		func(str, ans, length, depth, str[(*depth)], target, none);
	}
	else { //2) �Է� ���� ���ڰ� ��� ���� ���. 
		check(ans,target, none);//��Ģ ������ �´��� Ȯ���ϰ�, �´ٸ� ����� ���ش�.
		ans[0] = '\0'; //���� ��� �� ans�� depth�� �ʱ�ȭ.
		*(depth) = 0;
	}
}
void check(char *ans, int target, int * none) {
	int num[101] = { 0 };
	char operator[101] = { "" };
	char temp[101] = { "" }; // ���ӵ� ���ڰ� �� ��� temp�� ���

	int len_ans = strlen(ans);
	int i;
	int j = 0;
	int k = 0;


	for (i = 0; i <= len_ans; i++) { //������ �� ������ ��ĭ �� ���� �ؿ� else�� �ɸ��� �ؼ� ������ ���ڱ���Ȯ��!
		if (ans[i] >= '0'&&ans[i] <= '9') {
			append(temp, ans[i]);
		}
		else {
			num[j++] = atoi(temp);
			temp[0] = '\0';
			operator[k++] = ans[i];
		} // ���� ���� �������� ���ͼ� ������ �� �� ����. temp
	}
	
	//���� ����
	i = 0;
	while (operator[i] != '\0')
	{
		if (operator[i] == '*') {
			num[i] = num[i] * num[i + 1];
			//num �����ֱ�
			j = i;
			while (j<99) {
				num[j + 1] = num[j + 2];
				j++;
			}
			//operator �����ֱ�
			j = i;
			while (operator[j] != '\0') {
				operator[j] = operator[j + 1];
				j++;
			}
		}
		else {
			i++;
		}
	}

	//+, - �ϱ� 
	for (i = 0; i < 101; i++) {
		if (operator[i] == '\0') {
			break;
		}
		else {
			switch (operator[i]) {
			case '+': num[0] += num[i + 1]; break;
			default: num[0] -= num[i + 1]; break;
			}
		}
	}
	//��� ���
	if (target == num[0] && zerohead(ans)) { //zerohead�� 00�� 01�� ���� �������� �ʴ� ������ ���� �ľ��Ͽ� ���x.
		printf("%s\n", ans);
		(*none)++;
	}
}
int zerohead(char *str) {
	int i;
	int j=0;
	int len_str = strlen(str);
	for (i = 0; i < len_str; i++) {
		if ( ((str[i] == '0') && (str[i + 1] == '0')) || ((str[i] >= '0'&&str[i] <= '9')&&(str[i-1]=='0'))) {
			j += 1;
		}
	}
	if (j > 0)
		return 0;
	else
		return 1;
}
// 190322 ������ 
//1) none�� ����ؾ� �Ѵ�. (main�Լ��� �������� ���;� ���� ������ / func�ȿ��� check�� �����ϸ� ���� ������?)
//2) (�ذ�) 00 : �̷� ���� ����. > zerohead��� �Լ��� ���� ���� �ذ�
//3) ������ ���� : ���� ���� ������ ���踦 �߸��ߴ�. 