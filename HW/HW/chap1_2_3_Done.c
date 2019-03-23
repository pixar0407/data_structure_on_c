#include <stdio.h>  //HW1-2�� �ַ��1
#include <stdlib.h> // atoi �Լ��� ����� ��� ����
#include <string.h> //strlen, strcpy �Լ��� ����� ��� ����
void check(char *str, int sol);
void append(char *dst, char c);
void func(char *list, char* ans, int length, int *depth, char c,int sol); //recursion�� �Ͼ�� �Լ�
int doublezero(char *str);
void main(void) {
	char str[101]; //������ ����ڷ� ���� �޴� �Է��Դϴ�. �Һ�
	int sol;//�ι�° �Է�
	char ans[101] = { "" }; //recursion�� �ݺ��ϸ鼭 ���ڿ� operator�� ä�������ϴ�. call by ref

	int length = 0; //���ʷ� ����ڷ� ���� ���� �Է��� ����. recursion�ϴ� ���߿��� �Һ�
	int depth = 0; //ans�� ���� '����'�� ����. depth�� length�� ��ġ�ϴ��� Ȯ���Ͽ� recursion�� �����.

	scanf("%s", &str);
	scanf("%d", &sol);
	length=strlen(str);
	
	func(str, ans, length, &depth, 'n',sol);
}
//void append(char *dst, char c) {//���ڿ��� ���� ���ڸ� �߰��ϴ� �Լ�
//	char *p = dst;
//	while (*p != '\0') p++; // ���ڿ� �� Ž��
//	*p = c;
//	*(p + 1) = '\0';
//}
void append(char *dst, char c) {//���ڿ��� ���� ���ڸ� �߰��ϴ� �Լ�
	char *p = dst;
	while (*p != '\0') p++; // ���ڿ� �� Ž��
	*p = c;
	*(p + 1) = '\0';
}
void func(char *list, char* ans, int length, int *depth, char c, int sol) {//list�Һ�, length ��� - ans�� depth �� ��� ����.
	int temp_depth; //recursion ���� �� ans�� depth�� ���������� update���ֱ� ���� �Լ� �� ������.
	char temp_ans[101];

	switch (c) {
	case '+': {
		append(ans, '+');
		append(ans, list[*(depth)]);
		(*depth)++;
		break; }
	case '*': {
		append(ans, '*');
		append(ans, list[*(depth)]);
		(*depth)++;
		break; }
	case '-': {
		append(ans, '-');
		append(ans, list[*(depth)]);
		(*depth)++;
		break; }
	default: {
		append(ans, list[*(depth)]);
		(*depth)++;
		break; }
	}

	strcpy(temp_ans, ans);//������ �ӽ� ����
	temp_depth = *depth;

	if (length != *depth) { //1) recursion�� ��� �Ͼ�� �ϴ� ���
		func(list, ans, length, depth, '+', sol);
		strcpy(ans, temp_ans); //���� ��� �� �ʱ�ȭ �Ǿ��� ������ recursion ���� ��, ans depth ���������� update
		*depth = temp_depth;

		func(list, ans, length, depth, '*', sol);
		strcpy(ans, temp_ans); //���� ��� �� �ʱ�ȭ �Ǿ��� ������ recursion ���� ��, ans depth ���������� update
		*depth = temp_depth;

		func(list, ans, length, depth, '-', sol);
		strcpy(ans, temp_ans); //���� ��� �� �ʱ�ȭ �Ǿ��� ������ recursion ���� ��, ans depth ���������� update
		*depth = temp_depth;

		func(list, ans, length, depth, list[(*depth)], sol);
	}
	else { //2) �Է� ���� ���ڰ� ��� ���� ���. 
		check(ans,sol);//��Ģ ������ �´��� Ȯ���ϰ�, �´ٸ� ����� ���ش�.
		ans[0] = '\0'; //���� ��� �� ans�� depth�� �ʱ�ȭ.
		*(depth) = 0;
	}
}
void check(char *str, int sol) {
	int num[101] = { 0 };
	char operator[101] = { "" };
	char temp[101] = { "" };

	int len_str = strlen(str);
	int i;
	int j = 0;
	int k = 0;

	for (i = 0; i <= len_str; i++) { //������ �� ������ ��ĭ �� ���� �ؿ� else�� �ɸ��� �ؼ� ������ ���ڱ���Ȯ��!
		if (str[i] >= '0'&&str[i] <= '9') {
			append(temp, str[i]);
		}
		else {
			num[j++] = atoi(temp);
			temp[0] = '\0';
			operator[k++] = str[i];
		} // ���� ���� �������� ���ͼ� ������ �� �� ����.
	}

	//num[]�� operator[]�� ������ ���� ����� ����Ͽ� sol�� ���Ѵ�.
	for (i = 0; i < 101; i++) {
		if (operator[i] == NULL) {
			break;
		}
		else {
			switch (operator[i]) {
			case '+': num[0] += num[i + 1]; break;
			case '-': num[0] -= num[i + 1]; break;
			default: num[0] *= num[i + 1]; break;
			}
		}
	}
	if (sol == num[0] && doublezero(str) ) //doublezero�� 00�� 01�� ���� �������� �ʴ� ������ ���� �ľ��Ͽ� ���x.
		printf("%s\n", str);


	//printf("%s\n", str);

}
int doublezero(char *str) {
	int i;
	int j=0;
	for (i = 0; i < strlen(str); i++) {
		if ( ((str[i] == '0') && (str[i + 1] == '0')) || ((str[i] >= '0'&&str[i] <= '9')&&(str[i-1]=='0'))) {
			return 0;
			break;
		}
	}
}
// 190322 ������ 
//1) none�� ����ؾ� �Ѵ�. (main�Լ��� �������� ���;� ���� ������ / func�ȿ��� check�� �����ϸ� ���� ������?)
//2) (�ذ�) 00 : �̷� ���� ����. > doublezero��� �Լ��� ���� ���� �ذ�
//3) ������ ���� : ���� ���� ������ ���踦 �߸��ߴ�. 