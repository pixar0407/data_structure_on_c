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
void ShowArayElem(int * param, int len) //�Լ� ȣ��� ���� �ƴ� �ּҷ� ���ڸ� �޴� ���.
{
	int i;
	for (i = 0; i < len; i++)
		printf("%d ", param[i]);
	printf("\n");
}

void Swap(int * ptr1, int * ptr2) //�ּҸ� ���ؼ� �����ϱ� ������
{
	int temp = *ptr1;
	*ptr1 = *ptr2; //�ش� �ּҷ� ���� �� ���� �ٲ�.
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
// 19��
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
// 22��
struct point {
	int xpos;
	int ypos;
};
struct circle
{
	double radius;
	struct point * center;
};
//// scanf�� ��, %s�� �޾Ƶ��̸�, �پ� ���⸦ ������ ������ �Է��ϸ� ������ �ȴ�. �������� �ܾ ��� �Ѵ�.
int main(void) {
	//22�� ����ü�� ����� ���� �ڷ���1
	struct point cen = { 2, 4 };
	double rad = 5.5;

	struct circle ring = { rad, &cen };
	printf("���� ������ : %g \n", ring.radius);
	printf("���� �߽� [%d %d] \n", (ring.center)->xpos, (ring.center)->ypos);



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
	///*�� �� ������ �Ÿ� ���*/
	//distance = sqrt((double)((pos1.xpos-pos2.xpos)*(pos1.xpos - pos2.xpos) + (pos1.ypos - pos2.ypos)*(pos1.ypos - pos2.ypos)));
	//printf("�� �� ������ �Ÿ��� %g �Դϴ�.\n", distance);




	////21�� ���ڿ� ���ڿ� ���� �Լ�. EOF : End of File 1���� 2���� �ϰ� �Ѿ.
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



	////19�� �Լ� ������ ���� : �Լ��� ���� �ǹǷ�, ����� ��ġ�� ���� ���̴�. �Լ��� �̸����� �ҷ����δ�.
	//char * str[3] = { "C programming", "C++ Programming", "JAVA Programming" };
	//ShowAllString(3, str);
	



	//int age1 = 20;
	//int age2 = 30;
	//int first;

	//printf("������� 1 \n");
	//first = WhoIsFirst(age1, age2, OlderFirst);
	//printf("%d�� %d�� %d�� ���� ���� \n\n", age1, age2, first);
	//printf("������� 2 \n");
	//first = WhoIsFirst(age1, age2, YoungerFirst);
	//printf("%d�� %d�� %d�� ���� ���� \n\n", age1, age2, first);


	//char * str = "Function Pointer";
	//int num1 = 10, num2 = 20;

	//void(*fptr1)(int, int) = SimpleAdder;
	//void(*fptr2)(char *) = ShowString;

	//fptr1(num1, num2);
	//fptr2(str);



	
	//??? = arr1; 
	//!!! = arr2;
	// 1.
	// ???���� ������ ���� �ұ�? ���� ����� �� ���� arr1�� ������ ����Ű�� �ִ��� �̴�.
	// *(arr1)�� int�� �̱� ������ ������ ����Ű�Ƿ� arr1�� int�� ���� �����͸� ����Ų��.
	//���� int **dptr1 = arr1;�� �Ǿ�� �Ѵ�.

	// 2.
	// !!!���� ������ ���� �ұ�? ���� ����� �ϴ� ���� arr2�� ������ ����Ű�� �ִ��Ĵ� ���̴�.
	// *(arr2)�� int �� �̱� ������ �����̰�, ���� ���̰� [5]�̹Ƿ� 
	// int *(*ptr2)[5] =arr2;�� ���� ��Ÿ�� �� �ִ�.
	// 3�� 10��



	//int num = 10;
	//int *ptr = &num; // ptr�� &num�̿���. 
	//int **dptr = &ptr; // **dptr = ptr�� �ƴϴ�. 
	//int ***tptr = &dptr;

	//printf("%d %d \n", **dptr, ***tptr);
	//printf("%p %p \n", ptr, &ptr); //����! dptr�� ����Ű�� ���� �ſ���. ������? ptr�� ������ &ptr�̶�� �ؾ���.
	


	//int num1 = 10, num2 = 20, num3 = 30;
	//int *ptr1 = &num1;
	//int *ptr2 = &num2;
	//int *ptr3 = &num3;

	//int * ptrArr[] = { ptr1, ptr2, ptr3 }; //���� ������ �迭�� ����� ���ÿ� �ʱ�ȭ
	//int **dptr = ptrArr; // ���� ������ �迭�� ����� ���ÿ� �ʱ�ȭ???



	//int num1 = 10, num2 = 20;
	//int *ptr1, *ptr2;
	//ptr1 = &num1, ptr2 = &num2;
	//printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);

	//SwapIntPtr(&ptr1, &ptr2); // ���� ������ ����� ���ÿ� �ʱ�ȭ
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




	//p349�� ����3 ������ ��� ��ɸ��� �Լ��� ���� ����Ͽ���. �׷��� main �Լ����� 3�� �ۿ� ����.
	//int a[5][5] = { 0 } ; //ó���� �ʱ�ȭ�� �� ������� ������ �߻��ߴ�.
	//int i, j;
	//for (i = 0; i < 4; i++) {
	//	if (i == 0) {
	//		printf("ö��� ���� ���� ���� ���� ������ ���� �Է��ض�.\n");
	//	}
	//	else if (i == 1) {
	//		printf("ö���� ���� ���� ���� ���� ������ ���� �Է��ض�.\n");
	//	}
	//	else if (i == 2) {
	//		printf("����� ���� ���� ���� ���� ������ ���� �Է��ض�.\n");
	//	}
	//	else {
	//		printf("������ ���� ���� ���� ���� ������ ���� �Է��ض�.\n");
	//	}
	//	for (j = 0; j < 4; j++) {
	//		printf("give me specific answer \n");
	//		scanf("%d", &a[i][j]); //���� �����鼭 �ٷ� �����ҷ���!
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




	//p349�� ����2
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
	//		printf("�ּ� for %d : %p \n", arr[i][j], &arr[i][j]); // ������ �� ���� �ּҰ� ���� �Ҵ�ȴ�.
	//	}
	//}
		



	//3�� 9��
	/*int i = 5;
	SqByReference(&i);
	printf("Answer : %d\n", i);*/


	//int num1 = 10;
	//int num2 = 20;
	//printf("num1 num2: %d %d\n", num1, num2);
	//Swap(&num1, &num2);
	//printf("num1 num2: %d %d\n", num1, num2);



	//##3�� 7��
	//int arr1[3] = { 1,2,3 };
	//int arr2[5] = { 4, 5, 6, 7, 8 };
	//ShowArayElem(arr1, sizeof(arr1) / sizeof(int));
	//ShowArayElem(arr2, sizeof(arr2) / sizeof(int));
	



	//char * strArr[3] = { "Simple", "String", "Array" };
	//printf("%s \n", strArr); //�̰� char ** ���¶�� �ϳ׿�.
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
	//	ptr++; //ptr++���� �ϸ� ��� �ɱ��?����/ ptr+1���� �ϸ� ��� �ɱ��?
	//}
	//ptr -= 5; //�� ���ٱ��?
	///*for (i = 0; i < 5; i++) {
	//	*(ptr + i) += 2;
	//}*/
	//printf("%d %d %d %d %d\n", *ptr, *(ptr + 1), *(ptr + 2), *(ptr + 3), *(ptr + 4));
	//printf("%d %d %d %d %d\n", *arr, *(arr + 1), *(arr + 2), *(arr + 3), *(arr + 4));
	//printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
	//printf("%d %d %d %d %d\n", ptr[0], ptr[1], ptr[2], ptr[3], ptr[4]);



	
	//int arr[3] = { 11, 22, 33 };
	//int * ptr = arr; // �迭�� �̸��� pointer�� �̸�ó�� ����� �� �ִ�.
	//int num = 5;

	//printf("num : %d\n", num++); // ++num�� �ٸ���.
	//printf("num : %d\n\n", num);

	//printf("%d %d %d", *ptr, arr[0], *(++ptr)); //*ptr[1]�� �ȵ˴ϴ�(������ �迭�϶� �˴ϴ�.) *(++ptr)�� �˴ϴ�.
	//// arr[i] == *(arr+i)�� ���� ���踦 ������.

    
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
	//printf("size of num %d, size of pnum %d \n", sizeof(num), sizeof(pnum));//���� 4 byte, 4 byte
	////pnum�� 4 byte�� ������ 32��Ʈ �ý����̱� ������ 32/8 = 4 byte 



    //#define sq(a) a*a; //��ũ��
	//int ans;
	//ans = sq(2);
	//printf("%d \n", ans);



	//printf("%d",rfibo(4));



	//char str[50];
	//int idx = 0;
	//printf("���ڿ� �Է�: ");
	//scanf("%s", str);
	//printf("�Է� ���� ���ڿ�: %s \n", str);
	//printf("���� ���� ���: ");
	//while (str[idx] != '\0')
	//{
	//	printf("%c", str[idx]);
	//	idx++;
	//}  



	//char str[50] = "I like C programming";
	//printf("string: %s \n", str);

	//str[8] = 0; // str[8]='\n'�� ����
	//printf("string: %s \n", str);

	//str[6] = '\0';
	//printf("string: %s \n", str);

	//str[1] = '\0';
	//printf("string: %s \n", str);

	//printf("���� : %c \n", str[9]); // �׷��ٰ� Null ���� ������ �͵��� �������� �ʴ±�.
	return 0;
}