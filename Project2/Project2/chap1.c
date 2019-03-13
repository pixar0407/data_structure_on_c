#include <stdio.h>
#define COMPARE(x,y) (((x)<(y)) ? -1:((x)==(y))? 0 :1)
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
#define MAX_SIZE 101
//fibonacci interative
int fibo(int n)
{ // '0'부터 시작해서 n번째의 값을 반환
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
			printf("%c", list[j]); //행렬 쭉 출력
		printf("    ");
	}
	else {
		for (j = i; j <= n; j++) {
			SWAP(list[i], list[j], temp); // (대라기 바꾸기)여기서 SWAP이 reference 접근인가? 다음 줄에서 바꾼 걸 list로 주네.
			perm(list, i + 1, n);         // 대가리가 바뀐 list가 바뀐 지금 그 아래 부분이 모두 바뀌어 가며...
			SWAP(list[i], list[j], temp); // (대가리 원위치)여기서 SWAP이 reference 접근인가?
		}
	}
}
//Recursive binary search
int binsearch2(int list[], int searchnum, int left, int right)
{
	int middle;
	if (left <= right) { // while도 되는데?
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
{//현재 list의 놈들이 nondecreasing order로 나열되어 있다.
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		switch (COMPARE(list[middle], searchnum)) {
			case -1: left = middle + 1;
				break;
			case 0: return middle; // 3칸 위의 코드가 실행되고, 나서 뽝! 결과.
			case 1: right = middle - 1;
		}
	}
	return -1;
}
void swap(int *x, int *y) { //복습하는 과정에서 배웠듯이 주소로 접근해서 그 값을 바꿔주는 것이다.
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
				min = j; //min을 update해주는 것.
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

	//포인터 변수 크기 확인
	//int num = 5;
	//int *pnum = &num;
	//printf("size of num : %d \n", sizeof(num));
	//printf("size of pnum : %d \n", sizeof(pnum));
	//printf("size of &pnum : %d \n", sizeof(&pnum));
	return 0;
}
