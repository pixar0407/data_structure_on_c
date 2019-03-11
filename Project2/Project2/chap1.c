#include <stdio.h>
// Selection sort
void swap(int *x, int *y) { //�����ϴ� �������� ������� �ּҷ� �����ؼ� �� ���� �ٲ��ִ� ���̴�.
	int temp = *x;
	*x = *y;
	*y = temp;
}
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
#define MAX_SIZE 101
void sort(int[], int); //selection sort
int main(void) {
	int i, n;
	int list[MAX_SIZE];

}
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