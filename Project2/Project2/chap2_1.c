#include <stdio.h>
int main(void)
{
	//1
	//char str1[] = "My String";   // �ٸ� ��ġ�� ����ų �� ����. ���� ������ ����
	//char * str2 = "Your String"; // �ٸ� ��ġ�� ����ų �� ����. ���� ������ �Ұ���

	//printf("%p \n", str1); //004FF9AC
	//printf("%p \n", str1[0]); //0000004D �ȵ�. �̰� �ּҰ��� �ƴϾ�.
	//printf("%c \n", *(str1)); //M ��
	//printf("%c \n", *(str1+1)); //y ��
	//
	//printf("%p \n", str2); //01237B3C
	//printf("%p \n", str2[0]); //00000059 �ȵ�
	//printf("%c \n", str2[1]); //o ��

	//printf("%s \n", str1); //My String �ּҰ��� ������, s�� ��ȯ�ȴ�. 
	//printf("%s \n", str2); //Your String

	//printf("%c \n", str1); //? �ȵ�
	//printf("%c \n", str1[0]); //M
	//printf("%c \n", *str1); //M ��
	//printf("%c \n", str2); //< �ȵ�
	//printf("%c \n", *str2); //Y ��

	//printf("%c \n", str1[3]); //S  �ּҰ��� ������ c�� ��ȯ�ȴ�.
	//printf("%c \n", str2[3]); //r �� �굵 �迭�� �Ҵ�� �� ó�� �ൿ�ϴµ�?



    //2
	//char * strArr[2] = { "Simple", "String" };//char * strArr[2]={0x1004, 0x1048}; ū����ǥ�� ������ ǥ���Ǵ� ���ڿ��� �� ���¿� ������� �޸� ������ ����� �� �� �ּҰ��� ��ȯ
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