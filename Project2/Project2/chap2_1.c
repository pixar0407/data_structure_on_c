#include <stdio.h>
#include <stdlib.h> // c언어 표준 라이브러리
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

	////arr_2 = (int*)malloc(sizeof(int) * 5); // 4type 짜리 5개.

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
				printf("(%10p) %10p", myArray + i, myArray[i]);//바로 아래의 myArray[i] + 0과 동일.
			}
			printf("%10p", (myArray[i] + j));
		}
		printf("\n");
	}
	
	printf("%p \n", myArray); //001559D0
	printf("%p \n", myArray[0]); //001555F8
	printf("%p \n", *myArray);//myArray가 가리키는 것은 포인터 myArray[0] 001555F8
	printf("%p \n", myArray[1]); //012558E0
	printf("%p \n", *(myArray + 1)); //012558E0

	printf("%d \n", **myArray);//myArray를 따라가면 최종적으로 myArray[0][0]
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