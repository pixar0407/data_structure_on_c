#include <stdio.h>
#include <stdlib.h> // c��� ǥ�� ���̺귯��
int** make2dArray(int rows, int cols)
{
	int **x, i;
	x = (int**)malloc(cols* sizeof(int*));

	for (i = 0; i < cols; i++)
		x[i] = (int*)malloc(rows * sizeof(int));

	return x;
}
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
	//int num1 = 10, num2 = 20, num3 = 30;
	//int* arr[3] = { &num1, &num2, &num3 };

	//printf("%d \n", *arr[0]);//10 
	//printf("%p \n", arr[0]);//0055F788
	//printf("%p \n", arr);//0055F75C
	//printf("%p \n", &num1);//0055F788
	//return 0;



	//4
	//int arr_1[5];
	//int *arr_2;
	//int i;
	//
	//for (i = 0; i < 5; i++) {
	//	arr_1[i] = i + 1;
	//}

	////arr_2 = (int*)malloc(sizeof(int) * 5); // 4type ¥�� 5��.

	//for (i = 0; i < 5; i++) {
	//	arr_2[i] = arr_1[i];
	//}
	//for (i = 0; i < 5; i++) {
	//	printf("%3d", arr_2[i]);
	//}
	//free(arr_2);

	//printf("\n");
	//for (i = 0; i < 5; i++) {
	//	printf("%3d", arr_1[i]);
	//}



	//5
	int **myArray;
	int i, j;
	int col = 5, row = 10;
	myArray = make2dArray(col, row);

	for (i = 0; i < col; i++) {
		for (j = 0; j < row; j++) {
			myArray[i][j] = i + j*2;
		}
	}
	
	for (i = 0; i < col; i++) {
		for (j = 0; j < row; j++) {
			printf("%3d", myArray[i][j]);
		}
		printf("\n");
	}
	
	for (i = 0; i < col; i++) {
		for (j = 0; j < row; j++) {
			if (j==0) {
				printf("(%10p) %10p", myArray + i, myArray[i]);//�ٷ� �Ʒ��� myArray[i] + 0�� ����.
			}
			printf("%10p", (myArray[i] + j));
		}
		printf("\n");
	}
	
	printf("%p \n", myArray); //001559D0
	printf("%p \n", myArray[0]); //001555F8
	printf("%p \n", *myArray);//myArray�� ����Ű�� ���� ������ myArray[0] 001555F8
	printf("%p \n", myArray[1]); //012558E0
	printf("%p \n", *(myArray + 1)); //012558E0

	printf("%d \n", **myArray);//myArray�� ���󰡸� ���������� myArray[0][0]
	printf("%d \n", *myArray[0]);//0
	printf("%d \n", *(myArray[0]+1));//1
	printf("%d \n", **(myArray + 1));//2

	for (i = 0; i < col; i++)
		free(myArray[i]);
	free(myArray);

	//6
	//int i=9;
	//int *pi = &i;
	//int **dp = 
	//printf("%p \n", pi);//0057FC0C
	//printf("%p \n", &pi);//00CFFAB8
	//printf("%p \n", &i);//0057FC0C

	return 0;
}