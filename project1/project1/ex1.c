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
//// scanf�� ��, %s�� �޾Ƶ��̸�, �پ� ���⸦ ������ ������ �Է��ϸ� ������ �ȴ�. �������� �ܾ ��� �Ѵ�.
int main(void) {
	char * strArr[3] = { "Simple", "String", "Array" };
	printf("%s \n", strArr); //�̰� char ** ���¶�� �ϳ׿�.
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