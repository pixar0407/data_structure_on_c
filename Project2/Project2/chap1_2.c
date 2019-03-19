#include <stdio.h>
void ClearLineFromReadBuffer(void)
{
	while (getchar != '\n');
}
int main(void)
{	
	char perID[7];
	char name[10];

	fputs("주민등록 6자리 입력", stdout);
	fgets(perID, sizeof(perID), stdin);//엔터를 포함하여 총7개가 입력되었다. 그러나 최대 6개를 읽어들인다(왜냐면 한자리는 Null이 자동으로 추가). 엔터가 남는다. 
	ClearLineFromReadBuffer(); // 이 함수는 엔터가 입력되기 전까지 블랙홀이다. 엔터가 입력되면 자기가 버퍼로 흡수.

	fputs("이름입력:", stdout);
	fgets(name, sizeof(name), stdin);

	printf("주민등록번호 : %s \n", perID);
	printf("이름: %s\n", name);

	//char str[7];
	//int i;
	//printf("hohohoj");
	////while (1); // 이 함수는 블랙홀이다.
	//printf("sjsj");
	////for (i = 0; i < 3; i++)
	////{
	////	fgets(str, sizeof(str), stdin);
	////	puts(str);//문장 출력 후 개행을 해준다.
	////	fputs(str, stdout); printf("\n"); // fputs는 출력 후 개행이 없다.
	////	printf("Read %d: %s \n", i + 1, str);
	////}



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