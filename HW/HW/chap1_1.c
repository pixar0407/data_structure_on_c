#include <stdio.h>
#include <string.h>
#define MAX_LEN 101
char func(char *list, int len, char *ans) // list������, n list�� ����

{

	int i = 0, j = 0;
	char front[MAX_LEN];
	char back[MAX_LEN];
	int llfront = 1; //llfront�� ���� ����.
	int count = 0, count1 = 0;
	int count2 = 0;

	if (len == 1) { //��������
		strcat(ans, list);
		printf("\n ���� ��� %s \n", ans);
		char ans[MAX_LEN] = { "" };
	}
	else {
		//llfront update
		for (llfront = 1; llfront <= len; llfront++) {
			//front������ֱ�
			for (i = 0; i <= llfront - 1; i++)
				front[i] = list[i];
			front[i] = 0;
			//back������ֱ�
			for (i = 0; i <= len - llfront; i++)
				back[i] = list[llfront + i];
			back[i] = 0;
			//back�� ���̸� �����ϴ� �ڵ�
			for (i = 0; i < MAX_LEN; i++) {
				count++;
				if (back[i] == NULL)
					break;
			}
			count--;
			printf("front : %s \n", front);
			printf("back : %s \n", back);
			//answer �׾��ֱ�
			//1) str�� ���̸� �����ϴ� �ڵ�
			for (i = 0; i < MAX_LEN; i++) {
				count1++;
				if (list[i] == NULL)
					break;
			}
			count1--;

			//1) ans�� ���̸� �����ϴ� �ڵ�
			for (i = 0; i < MAX_LEN; i++) {
				count2++;
				if (ans[i] == 0)
					break;
			}
			count2--;

			//��ġ��
			for (i = 0; i <= count1; i++)
				ans[count2 + i] =+ front[i];
			
			func(back, count, ans);
		}
	}
}

int main(void)
{
	char str[MAX_LEN];
	char ans[MAX_LEN] = { "" }; // �ֺ� string�� �������.
	int llfront = 1, i = 0, count = 0, count2 = 0;

	scanf("%s", &str);

	//1) str�� ���̸� �����ϴ� �ڵ�
	for (i = 0; i < MAX_LEN; i++) {
		count++;
		if (str[i] == NULL)
			break;
	}
	count--;

	////1) ans�� ���̸� �����ϴ� �ڵ�
	//for (i = 0; i < MAX_LEN; i++) {
	//	count2++;
	//	if (ans[i] == 0)
	//		break;
	//}
	//count2--;
	//
	////��ġ��
	//for (i = 0; i <= count; i++)
	//	ans[count2 + i] = str[i];

	//printf("COUNT : %d \n", count);
	//printf("COUNT2 : %d", count2);
	//printf("\n ����ϴ� : %s", ans);

	func(str, count, ans);


	return 0;

}