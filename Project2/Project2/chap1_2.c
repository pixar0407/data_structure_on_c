#include <stdio.h>
void ClearLineFromReadBuffer(void)
{
	while (getchar != '\n');
}
int main(void)
{	
	char perID[7];
	char name[10];

	fputs("�ֹε�� 6�ڸ� �Է�", stdout);
	fgets(perID, sizeof(perID), stdin);//���͸� �����Ͽ� ��7���� �ԷµǾ���. �׷��� �ִ� 6���� �о���δ�(�ֳĸ� ���ڸ��� Null�� �ڵ����� �߰�). ���Ͱ� ���´�. 
	ClearLineFromReadBuffer(); // �� �Լ��� ���Ͱ� �ԷµǱ� ������ ��Ȧ�̴�. ���Ͱ� �ԷµǸ� �ڱⰡ ���۷� ���.

	fputs("�̸��Է�:", stdout);
	fgets(name, sizeof(name), stdin);

	printf("�ֹε�Ϲ�ȣ : %s \n", perID);
	printf("�̸�: %s\n", name);

	//char str[7];
	//int i;
	//printf("hohohoj");
	////while (1); // �� �Լ��� ��Ȧ�̴�.
	//printf("sjsj");
	////for (i = 0; i < 3; i++)
	////{
	////	fgets(str, sizeof(str), stdin);
	////	puts(str);//���� ��� �� ������ ���ش�.
	////	fputs(str, stdout); printf("\n"); // fputs�� ��� �� ������ ����.
	////	printf("Read %d: %s \n", i + 1, str);
	////}



	//char str[7];
	//fgets(str, sizeof(str), stdin);

	//puts(str); // ������ �̷�����. 
	//fputs(str, stdout); // ������ �̷����� �ʴ´�.



	//int ch1, ch2;

	//ch1 = getchar();
	//ch2 = fgetc(stdin);

	//putchar(ch1);
	//fputc(ch2, stdout);
	return 0;
}