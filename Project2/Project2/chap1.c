#include <stdio.h>
#define COMPARE(x,y) (((x)<(y)) ? -1:((x)==(y))? 0 :1)
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
#define MAX_SIZE 101
//fibonacci interative
int fibo(int n)
{ // '0'���� �����ؼ� n��°�� ���� ��ȯ
	int g, h, f, i;
	if (n > 1) {
		g = 0;
		h = 1;
		for (i = 2; i <= n; i++) {
			f = g + h;
			g = h;
			h = f;
		}
	}
	else f = n;
	return f;
}
int rfibo(int n)
{
	if (n > 1) {
		return rfibo(n - 1) + rfibo(n - 2);
	}
	else {
		return n;
	}
}
	

//permutation
void perm(char *list, int i, int n)
{
	int j, temp;
	if (i == n) {
		for (j = 0; j <= n; j++)
			printf("%c", list[j]); //��� �� ���
		printf("    ");
	}
	else {
		for (j = i; j <= n; j++) {
			SWAP(list[i], list[j], temp); // (���� �ٲٱ�)���⼭ SWAP�� reference �����ΰ�? ���� �ٿ��� �ٲ� �� list�� �ֳ�.
			perm(list, i + 1, n);         // �밡���� �ٲ� list�� �ٲ� ���� �� �Ʒ� �κ��� ��� �ٲ�� ����...
			SWAP(list[i], list[j], temp); // (�밡�� ����ġ)���⼭ SWAP�� reference �����ΰ�?
		}
	}
}
//Recursive binary search
int binsearch2(int list[], int searchnum, int left, int right)
{
	int middle;
	if (left <= right) { // while�� �Ǵµ�?
		middle = (left + right) / 2;
		switch (COMPARE(list[middle], searchnum)) {
		case -1: return binsearch2(list, searchnum, middle + 1, right);
		case 0: return middle;
		case 1: return binsearch2(list, searchnum, left, middle-1);
		}
	}
	return -1;
}
//Binary search
int binsearch(int list[], int searchnum, int left, int right) //ist[7] = { 3, 4, 5, 6, 6, 7, 8 };
{//���� list�� ����� nondecreasing order�� �����Ǿ� �ִ�.
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		switch (COMPARE(list[middle], searchnum)) {
			case -1: left = middle + 1;
				break;
			case 0: return middle; // 3ĭ ���� �ڵ尡 ����ǰ�, ���� ��! ���.
			case 1: right = middle - 1;
		}
	}
	return -1;
}
void swap(int *x, int *y) { //�����ϴ� �������� ������� �ּҷ� �����ؼ� �� ���� �ٲ��ִ� ���̴�.
	int temp = *x;
	*x = *y;
	*y = temp;
}
// Selection sort
void sort(int list[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[min])
				min = j; //min�� update���ִ� ��.
		}
		SWAP(list[i], list[min], temp);
	}
}
int main(void) {

	int i = 1, j = 2;
	double d = 3.4;
	char c = 'j';
	char *pc = &c;
	int *pii = &i;
	double *pd = &d;
	printf("%d \n", sizeof(pii));
	printf("%d \n", sizeof(pd));
	printf("%d \n", sizeof(pc));
	printf("%d", sizeof(d));

	


	//fibonacci
	//int n = 5;
	//printf("this is iterative result : %d \n", fibo(n));
	//printf("this is recursive result : %d \n", rfibo(n));

	//binary search
	//int list[12] = { 3, 4, 5, 6, 6, 7, 8, 8,9, 10, 11, 13 };
	//int searchnum = 5;
	//int left = 0, right = 11;
	//int ans;
	//ans = binsearch2(list, searchnum, left, right);
	//printf("This is ans : %d \n", ans);

	//permutation
	//char list[] = { 'a', 'b', 'c', 'd' };
	//int i = 0, n = 3;
	//perm(list, i, n);

	//������ ���� ũ�� Ȯ��
	//int num = 5;
	//int *pnum = &num;
	//printf("size of num : %d \n", sizeof(num));
	//printf("size of pnum : %d \n", sizeof(pnum));
	//printf("size of &pnum : %d \n", sizeof(&pnum));
	return 0;
}
