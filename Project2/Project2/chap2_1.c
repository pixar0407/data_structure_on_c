#include <stdio.h>
int main(void)
{
	//1
	//char str1[] = "My String";   // 다른 위치를 가리킬 수 없음. 내용 변경이 가능
	//char * str2 = "Your String"; // 다른 위치를 가리킬 수 있음. 내용 변경이 불가능

	//printf("%p \n", str1); //004FF9AC
	//printf("%p \n", str1[0]); //0000004D 안됨. 이건 주소값이 아니야.
	//printf("%c \n", *(str1)); //M 됨
	//printf("%c \n", *(str1+1)); //y 됨
	//
	//printf("%p \n", str2); //01237B3C
	//printf("%p \n", str2[0]); //00000059 안됨
	//printf("%c \n", str2[1]); //o 됨

	//printf("%s \n", str1); //My String 주소값을 넣으면, s가 반환된다. 
	//printf("%s \n", str2); //Your String

	//printf("%c \n", str1); //? 안됨
	//printf("%c \n", str1[0]); //M
	//printf("%c \n", *str1); //M 됨
	//printf("%c \n", str2); //< 안됨
	//printf("%c \n", *str2); //Y 됨

	//printf("%c \n", str1[3]); //S  주소값을 넣으면 c가 반환된다.
	//printf("%c \n", str2[3]); //r 엥 얘도 배열로 할당된 것 처럼 행동하는데?



    //2
	//char * strArr[2] = { "Simple", "String" };//char * strArr[2]={0x1004, 0x1048}; 큰따옴표로 묶여서 표현되는 문자열은 그 형태에 상관없이 메모리 공간에 저장된 후 그 주소값을 반환
	//printf("%s \n", strArr[0]);//Simple
	//printf("%s \n", strArr[1]);//String
	//printf("%c \n", strArr[0][1]);//i
	//printf("%c \n", strArr[1][0]);//S



	//3
	int num1 = 10, num2 = 20, num3 = 30;
	int* arr[3] = { &num1, &num2, &num3 };

	printf("%d \n", *arr[0]);//10 
	printf("%p \n", arr[0]);//0055F788
	printf("%p \n", arr);//0055F75C
	printf("%p \n", &num1);//0055F788
	return 0;
}