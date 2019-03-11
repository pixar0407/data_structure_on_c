#include <stdio.h>
// Selection sort
void swap(int *x, int *y) { //복습하는 과정에서 배웠듯이 주소로 접근해서 그 값을 바꿔주는 것이다.
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
				min = j; //min을 update해주는 것.
		}
		SWAP(list[i], list[min], temp);
	}
}