#include <stdio.h>
int main(void)
{
	char str[7];
	int i;

	for (i = 0; i < 3; i++)
	{
		fgets(str, sizeof(str), stdin);
		puts(str);//���� ��� �� ������ ���ش�.
		fputs(str, stdout); printf("\n"); // fputs�� ��� �� ������ ����.
		printf("Read %d: %s \n", i + 1, str);
	}



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