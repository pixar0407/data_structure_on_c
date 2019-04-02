#include <stdio.h>
#include <stdlib.h> // 궁금증, append 들어가면, n>m 인 m만큼 훑긴 하는데 이것도 세어주는 건가?
void append(char *dst, char c);// 동적 할당 잘 한 것인가?
void check_array(char *num, int n);
void max_min(int arr, int *max, int *min);
int main(void)
{
	int n;
	char * num = (char *)malloc(101 * sizeof(char));

	scanf("%d", &n);
	getchar(); // 한번 enter 치는 것을 먹어 줘야 한다.
	scanf("%[^\n]s", num);
	check_array(num, n);
	free(num);
	return 0;
}
void append(char *dst, char c) {//문자열의 끝에 문자를 추가하는 함수
	char *p = dst;
	while (*p != '\0') p++; // 문자열 끝 탐색 << 이러면 n>m인 m만큼 매번 해주는 것 아닌가? 1+ 2+ 3+ ... n-1 = n(n-1)/2 인데 이러면 n^2인데???
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
		else { //이 구간에서 다음과 같은 조건으로 했더니, if (num[i] == 0x20 || num[i] == 0x00) 문제가 생겼다.
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
	} // 마지막 나올 때, num[i] == 0x00 인 체로 나오기 때문에 마지막 숫자를 arr에 넣어줘야 한다.
	arr[j] = atoi(temp);
	temp[0] = '\0';
	if (j == 0) {
		max = arr[0];
		min = arr[0];
	}
	max_min(arr[j], &max, &min);
	sum += arr[j];

	//arr[j] = 0x00; // 숫자 넣어주고, arr의 끝 지점을 보여주기 위해서 NULL 값을 저장해준다.
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