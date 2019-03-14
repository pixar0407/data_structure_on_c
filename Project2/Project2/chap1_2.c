#include <stdio.h>
int main(void)
{
	char str[7];
	int i;

	for (i = 0; i < 3; i++)
	{
		fgets(str, sizeof(str), stdin);
		puts(str);//문장 출력 후 개행을 해준다.
		fputs(str, stdout); printf("\n"); // fputs는 출력 후 개행이 없다.
		printf("Read %d: %s \n", i + 1, str);
	}



	//char str[7];
	//fgets(str, sizeof(str), stdin);

	//puts(str); // 개행이 이뤄진다. 
	//fputs(str, stdout); // 개행이 이뤄지지 않는다.



	//int ch1, ch2;

	//ch1 = getchar();
	//ch2 = fgetc(stdin);

	//putchar(ch1);
	//fputc(ch2, stdout);
	return 0;
}