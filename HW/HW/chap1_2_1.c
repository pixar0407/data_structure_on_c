#include <stdio.h>
#include <string.h>
#include <stdlib.h>    // atoi 함수가 선언된 헤더 파일
void append(char *dst, char c);
void check(char *str);
int main(void) {
	char str[101];
	int sol;

	scanf("%s", &str);
	scanf("%d", &sol);
	printf("sol : %d\n", sol);

	check(str);
}
void check(char *str) {
	int num[101] = { 0 };
	char operator[101] = { "" };
	char temp[101] = { "" };

	int len_str = strlen(str);
	char c;
	int i;
	int j = 0;
	int k = 0;
	
	printf("len_str : %d\n", len_str);
	for (i = 0; i <= len_str; i++) { //마지막 빈 곳으로 한칸 더 가서 밑에 else에 걸리게 해서 마지막 숫자까지확인!
		if (str[i] >= '0'&&str[i] <= '9') {
			append(temp, str[i]);
		}
		else {
			num[j++]=atoi(temp);
			temp[0] = '\0';
			operator[k++] = str[i];
		} // 끝에 숫자 연속으로 나와서 문제가 될 수 있음.
	}


	//나눈 결과 확인
	printf("operator : %s\n", operator);
	for (i = 0; i < 101; i++) {
		if (num[i])
			printf("%d\n", num[i]);
	}


	//num과 operator만 가지고 놀아보자
	for (i = 0; i < 101; i++) {
		if (operator[i] == NULL) {
			break;
		} else {
			switch (operator[i]) {
			case '+': num[0] += num[i + 1]; break;
			case '-': num[0] -= num[i + 1]; break;
			default: num[0] *= num[i + 1]; break;
			}
		}
	}
	printf("최종 : %d\n", num[0]);


}
void append(char *dst, char c) {
	char *p = dst;
	while (*p != '\0') p++; // 문자열 끝 탐색
	*p = c;
	*(p + 1) = '\0';
}