#include <stdio.h>
#include <math.h>
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


//int rfibo(int n) //recursive 
//{
//	if (n > 1)
//		return rfibo(n - 1) + rfibo(n - 2);
//	else
//		return n;
//}
void ShowArayElem(int * param, int len) //함수 호출시 값이 아닌 주소로 인자를 받는 방법.
{
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", param[i]);
	printf("\n");
}

void Swap(int * ptr1, int * ptr2) //주소를 통해서 접근하기 때문에
{
	int temp = *ptr1;
	*ptr1 = *ptr2; //해당 주소로 가서 그 값을 바꿈.
	*ptr2 = temp;
}

void SqByReference(int * ptr1)
{
	int num = *ptr1;
	*ptr1 = num*num;
}
void SwapIntPtr(int **dp1, int **dp2)
{
	int * temp = *dp1;
	*dp1 = *dp2;
	*dp2 = temp;
}
// 19장
void SimpleAdder(int n1, int n2)
{
	printf("%d + %d = %d \n", n1, n2, n1 + n2);
}
void ShowString(char * str)
{
	printf("%s \n", str);
}
int WhoIsFirst(int age1, int age2, int(*cmp)(int n1, int n2))
{
	return cmp(age1, age2);
}
int OlderFirst(int age1, int age2)
{
	if (age1 > age2)
		return age1;
	else if (age1 < age2)
		return age2;
	else
		return 0;
}
int YoungerFirst(int age1, int age2)
{
	if (age1 < age2)
		return age1;
	else if (age1 > age2)
		return age2;
	else
		return 0;
}
void ShowAllString(int argc, char * argv[]) {
	int i;
	for (i = 0; i < argc; i++)
		printf("%s \n", argv[i]);
}
// 22장
struct point {
	int xpos;
	int ypos;
};
struct circle
{
	double radius;
	struct point * center;
};
//// scanf할 때, %s로 받아들이면, 뛰어 쓰기를 포함한 문장을 입력하면 문제가 된다. 연속으로 단어를 써야 한다.
int main(void) {
	//22장 구조체와 사용자 정의 자료형1
	struct point cen = { 2, 4 };
	double rad = 5.5;

	struct circle ring = { rad, &cen };
	printf("원의 반지름 : %g \n", ring.radius);
	printf("원의 중심 [%d %d] \n", (ring.center)->xpos, (ring.center)->ypos);



	//struct point pos1 = { 1,2 };
	//struct point pos2 = { 100,200 };
	//struct point * pptr = &pos1;

	//(*pptr).xpos += 4;
	//(*pptr).ypos += 5;
	//printf("[%d %d] \n", pptr->xpos, pptr->ypos);

	//pptr = &pos2;
	//(*pptr).xpos += 1;
	//(*pptr).ypos += 2;
	//printf("[%d %d] \n", pptr->xpos, pptr->ypos);




	//struct point pos1, pos2;
	//double distance;

	//fputs("point1 pos:", stdout);
	//scanf("%d %d", &pos1.xpos, &pos1.ypos);

	//fputs("point2 pos:", stdout);
	//scanf("%d %d", &pos2.xpos, &pos2.ypos);
	///*두 점 사이의 거리 계산*/
	//distance = sqrt((double)((pos1.xpos-pos2.xpos)*(pos1.xpos - pos2.xpos) + (pos1.ypos - pos2.ypos)*(pos1.ypos - pos2.ypos)));
	//printf("두 점 사이의 거리는 %g 입니다.\n", distance);




	////21장 문자와 문자열 관련 함수. EOF : End of File 1절과 2절만 하고 넘어감.
	//int ch;

	//while (1)
	//{
	//	ch = getchar();
	//	if (ch == EOF)
	//		break;
	//	putchar(ch);
	//}




	//int ch1, ch2;
	//ch1 = getchar();
	//ch2 = fgetc(stdin);

	//putchar(ch1);
	//fputc(ch2, stdout);



	////19장 함수 포인터 변수 : 함수도 저장 되므로, 저장된 위치가 있을 것이다. 함수의 이름으로 불러들인다.
	//char * str[3] = { "C programming", "C++ Programming", "JAVA Programming" };
	//ShowAllString(3, str);
	



	//int age1 = 20;
	//int age2 = 30;
	//int first;

	//printf("입장순서 1 \n");
	//first = WhoIsFirst(age1, age2, OlderFirst);
	//printf("%d와 %d중 %d가 먼저 입장 \n\n", age1, age2, first);
	//printf("입장순서 2 \n");
	//first = WhoIsFirst(age1, age2, YoungerFirst);
	//printf("%d와 %d중 %d가 먼저 입장 \n\n", age1, age2, first);


	//char * str = "Function Pointer";
	//int num1 = 10, num2 = 20;

	//void(*fptr1)(int, int) = SimpleAdder;
	//void(*fptr2)(char *) = ShowString;

	//fptr1(num1, num2);
	//fptr2(str);



	
	//??? = arr1; 
	//!!! = arr2;
	// 1.
	// ???에는 무엇이 들어가야 할까? 먼저 살펴야 될 것은 arr1이 무엇을 가리키고 있느냐 이다.
	// *(arr1)이 int형 싱글 포인터 변수를 가리키므로 arr1은 int형 더블 포인터를 가리킨다.
	//따라서 int **dptr1 = arr1;이 되어야 한다.

	// 2.
	// !!!에는 무엇이 들어가야 할까? 먼저 살펴야 하는 것은 arr2가 무엇을 가리키고 있느냐는 것이다.
	// *(arr2)가 int 형 싱글 포인터 변수이고, 가로 길이가 [5]이므로 
	// int *(*ptr2)[5] =arr2;와 같이 나타낼 수 있다.
	// 3월 10일



	//int num = 10;
	//int *ptr = &num; // ptr은 &num이에요. 
	//int **dptr = &ptr; // **dptr = ptr이 아니다. 
	//int ***tptr = &dptr;

	//printf("%d %d \n", **dptr, ***tptr);
	//printf("%p %p \n", ptr, &ptr); //아하! dptr은 가리키고 싶은 거에요. 무엇을? ptr를 때문에 &ptr이라고 해야함.
	


	//int num1 = 10, num2 = 20, num3 = 30;
	//int *ptr1 = &num1;
	//int *ptr2 = &num2;
	//int *ptr3 = &num3;

	//int * ptrArr[] = { ptr1, ptr2, ptr3 }; //더플 포인터 배열의 선언과 동시에 초기화
	//int **dptr = ptrArr; // 더블 포인터 배열의 선언과 동시에 초기화???



	//int num1 = 10, num2 = 20;
	//int *ptr1, *ptr2;
	//ptr1 = &num1, ptr2 = &num2;
	//printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);

	//SwapIntPtr(&ptr1, &ptr2); // 더블 포인터 선언과 동시에 초기화
	//printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);


	//double num = 3.14;
	//double * ptr = &num;
	//double ** dptr = &ptr;
	//double *ptr2;

	//printf("%9p %9p \n", ptr, *dptr);
	//printf("%9g %9g \n", num, **dptr);
	//ptr2 = *dptr;
	//*ptr2 = 10.99;
	//printf("%9g %9g \n", num, **dptr);




	//p349쪽 문제3 답지의 경우 기능마다 함수를 만들어서 사용하였다. 그래서 main 함수에는 3줄 밖에 없다.
	//int a[5][5] = { 0 } ; //처음에 초기화를 안 해줬더니 문제가 발생했다.
	//int i, j;
	//for (i = 0; i < 4; i++) {
	//	if (i == 0) {
	//		printf("철희야 국어 영어 수학 국사 순으로 점수 입력해라.\n");
	//	}
	//	else if (i == 1) {
	//		printf("철수야 국어 영어 수학 국사 순으로 점수 입력해라.\n");
	//	}
	//	else if (i == 2) {
	//		printf("영희야 국어 영어 수학 국사 순으로 점수 입력해라.\n");
	//	}
	//	else {
	//		printf("영수야 국어 영어 수학 국사 순으로 점수 입력해라.\n");
	//	}
	//	for (j = 0; j < 4; j++) {
	//		printf("give me specific answer \n");
	//		scanf("%d", &a[i][j]); //정보 받으면서 바로 저장할래용!
	//		a[i][4] += a[i][j];
	//		a[4][j] += a[i][j];
	//	}
	//	a[4][4] += a[i][4];
	//}

	//for (i = 0; i < 5; i++) {
	//	for (j = 0; j < 5; j++) {
	//		printf("%d ", a[i][j]);
	//	}
	//	printf("\n");
	//}




	//p349쪽 문제2
	//int a[2][4] = { 1,2,3,4,5,6,7,8 };
	//int b[4][2];
	//int i, j;
	//for (i = 0; i < 2; i++) {
	//	for (j = 0; j < 4; j++) {
	//		printf("%d ", a[i][j]);
	//		b[j][i] = a[i][j];
	//	}
	//	printf("\n");
	//}
	//printf("the answer starts here \n \n");
	//for (i = 0; i < 4; i++) {
	//	for (j = 0; j < 2; j++) {
	//		printf("%d ", b[i][j]);
	//	}
	//	printf("\n");
	//}

	//int arr[3][2] = {
	//	{1, 2},
	//    {3, 4},
	//    {6, 7}
	//};
	//int i, j;
	//for (i = 0; i < 3; i++) {
	//	for (j = 0; j < 2; j++) {
	//		printf("주소 for %d : %p \n", arr[i][j], &arr[i][j]); // 실행할 때 마다 주소가 새로 할당된다.
	//	}
	//}
		



	//3월 9일
	/*int i = 5;
	SqByReference(&i);
	printf("Answer : %d\n", i);*/


	//int num1 = 10;
	//int num2 = 20;
	//printf("num1 num2: %d %d\n", num1, num2);
	//Swap(&num1, &num2);
	//printf("num1 num2: %d %d\n", num1, num2);



	//##3월 7일
	//int arr1[3] = { 1,2,3 };
	//int arr2[5] = { 4, 5, 6, 7, 8 };
	//ShowArayElem(arr1, sizeof(arr1) / sizeof(int));
	//ShowArayElem(arr2, sizeof(arr2) / sizeof(int));
	



	//char * strArr[3] = { "Simple", "String", "Array" };
	//printf("%s \n", strArr); //이건 char ** 형태라고 하네요.
	//printf("%p \n", strArr);
	//printf("%s \n", strArr[0]);
	//printf("%s \n", strArr[1]);
	//printf("%s \n", strArr[2]);
	//printf("How about * : %c \n", *(strArr[2]+1)); //Good!! 
	//printf("How about c : %p \n", strArr[0]);
	
	
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