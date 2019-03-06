#include <stdio.h>
//int binsearch(int list[], int searchnum, int left, int right)
//{
//	int middle;
//	if (left <= right) {
//		middle = (left + right) / 2;
//		switch (COMPARE(list[middle], searchnum)) {
//		case -1: return binsearch(list, searchnum, middle + 1, right);
//		case 0 : return middle;
//		case 1: return binsearch(list, searchnum, left, middle - 1);
//		}
//	}
//	return -1;
//}


int rfibo(int n) //recursive 
{
	if (n > 1)
		return rfibo(n - 1) + rfibo(n - 2);
	else
		return n;
}
//// scanf할 때, %s로 받아들이면, 뛰어 쓰기를 포함한 문장을 입력하면 문제가 된다. 연속으로 단어를 써야 한다.
int main(void) {
	char * strArr[3] = { "Simple", "String", "Array" };
	printf("%s \n", strArr); //이건 char ** 형태라고 하네요.
	printf("%p \n", strArr);
	printf("%s \n", strArr[0]);
	printf("%s \n", strArr[1]);
	printf("%s \n", strArr[2]);
	printf("How about * : %c \n", *(strArr[2]+1)); //Good!! 
	printf("How about c : %p \n", strArr[0]);
	
	
	//int arr[5] = { 1, 2, 3, 4, 5 };
	//int * ptr = arr;
	//int i = 0;
	//

	//for (i = 0; i < 5; i++) {
	//	*(ptr) += 2;
	//	ptr++; //ptr++으로 하면 어떻게 될까요?ㅎㅎ/ ptr+1으로 하면 어떻게 될까요?
	//}
	//ptr -= 5; //왜 해줄까요?
	///*for (i = 0; i < 5; i++) {
	//	*(ptr + i) += 2;
	//}*/
	//printf("%d %d %d %d %d\n", *ptr, *(ptr + 1), *(ptr + 2), *(ptr + 3), *(ptr + 4));
	//printf("%d %d %d %d %d\n", *arr, *(arr + 1), *(arr + 2), *(arr + 3), *(arr + 4));
	//printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
	//printf("%d %d %d %d %d\n", ptr[0], ptr[1], ptr[2], ptr[3], ptr[4]);



	
	//int arr[3] = { 11, 22, 33 };
	//int * ptr = arr; // 배열의 이름은 pointer의 이름처럼 사용할 수 있다.
	//int num = 5;

	//printf("num : %d\n", num++); // ++num과 다르다.
	//printf("num : %d\n\n", num);

	//printf("%d %d %d", *ptr, arr[0], *(++ptr)); //*ptr[1]은 안됩니다(포인터 배열일때 됩니다.) *(++ptr)가 됩니다.
	//// arr[i] == *(arr+i)와 같은 관계를 가진다.

    
	//int num1 = 10;
	//int num2 = 20;
	//int *ptr1 = &num1;
	//int *ptr2 = &num2;
	//*ptr1 += 10; //num1 = 20
	//*ptr2 -= 10; //num2 = 10;

	//ptr1 = &num2;
	//ptr2 = &num1;
	//printf("ptr1 = %d\nptr2 = %d\n", *ptr1, *ptr2);


	//int num = 7;
	//int * pnum;
	//pnum = &num;

	//printf("address of num is %p\n", &num);
	//printf("pnum is %p\n", pnum);
	//printf("address of pnum is %p \n", &pnum);
	//printf("size of num %d, size of pnum %d \n", sizeof(num), sizeof(pnum));//각각 4 byte, 4 byte
	////pnum이 4 byte인 이유가 32비트 시스템이기 때문에 32/8 = 4 byte 



    //#define sq(a) a*a; //매크로
	//int ans;
	//ans = sq(2);
	//printf("%d \n", ans);



	//printf("%d",rfibo(4));



	//char str[50];
	//int idx = 0;
	//printf("문자열 입력: ");
	//scanf("%s", str);
	//printf("입력 받은 문자열: %s \n", str);
	//printf("문자 단위 출력: ");
	//while (str[idx] != '\0')
	//{
	//	printf("%c", str[idx]);
	//	idx++;
	//}  



	//char str[50] = "I like C programming";
	//printf("string: %s \n", str);

	//str[8] = 0; // str[8]='\n'과 동일
	//printf("string: %s \n", str);

	//str[6] = '\0';
	//printf("string: %s \n", str);

	//str[1] = '\0';
	//printf("string: %s \n", str);

	//printf("과연 : %c \n", str[9]); // 그렇다고 Null 문자 이후의 것들을 지우지는 않는군.
	return 0;
}