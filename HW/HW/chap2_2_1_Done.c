#include <stdio.h>
#include <stdlib.h> // �ñ���, append ����, n>m �� m��ŭ �ȱ� �ϴµ� �̰͵� �����ִ� �ǰ�?
void append(char *dst, char c);// ���� �Ҵ� �� �� ���ΰ�?
void check_array(char *num, int n);
void max_min(int arr, int *max, int *min);
int main(void)
{
	int n;
	char * num = (char *)malloc(101 * sizeof(char));

	scanf("%d", &n);
	getchar(); // �ѹ� enter ġ�� ���� �Ծ� ��� �Ѵ�.
	scanf("%[^\n]s", num);
	check_array(num, n);
	free(num);
	return 0;
}
void append(char *dst, char c) {//���ڿ��� ���� ���ڸ� �߰��ϴ� �Լ�
	char *p = dst;
	while (*p != '\0') p++; // ���ڿ� �� Ž�� << �̷��� n>m�� m��ŭ �Ź� ���ִ� �� �ƴѰ�? 1+ 2+ 3+ ... n-1 = n(n-1)/2 �ε� �̷��� n^2�ε�???
	*p = c;
	*(p + 1) = '\0';
}
void check_array(char *num,int n) {
	int max, min, i = 0, j = 0, sum = 0;
	int * arr = (int *)malloc(101 * sizeof(int));
	char * temp = (char *)malloc(101 * sizeof(char));
	arr[0] = '\0'; temp[0] = '\0';

	while (num[i] != 0x00) {
		if ('0' <= num[i] && num[i] <= '9') {
			append(temp, num[i]);
		}
		else { //�� �������� ������ ���� �������� �ߴ���, if (num[i] == 0x20 || num[i] == 0x00) ������ �����.
			arr[j] = atoi(temp);
			temp[0] = '\0';
			if (j == 0) {
				max = arr[0];
				min = arr[0];
			}
			else {
				max_min(arr[j], &max, &min);
			}
			sum += arr[j]; j++;
		} i++;
	} // ������ ���� ��, num[i] == 0x00 �� ü�� ������ ������ ������ ���ڸ� arr�� �־���� �Ѵ�.
	arr[j] = atoi(temp);
	temp[0] = '\0';
	if (j == 0) {
		max = arr[0];
		min = arr[0];
	}
	max_min(arr[j], &max, &min);
	sum += arr[j];

	//arr[j] = 0x00; // ���� �־��ְ�, arr�� �� ������ �����ֱ� ���ؼ� NULL ���� �������ش�.
	if (((max + min) * n / 2 == sum) && ((max - min + 1) == n))
		printf("1");
	else
		printf("0");
	free(arr);
	free(temp);
}
void max_min(int arr, int *max, int *min) {
	if (arr > *max)
		*max = arr;
	if (arr < *min) {
		if (arr != 0)
			*min = arr;
	}
}