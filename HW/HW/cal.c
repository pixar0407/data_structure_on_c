#include <stdio.h>  //
#include <stdlib.h> // atoi 함수가 선언된 헤더 파일
#include <string.h> //strlen, strcpy 함수가 선언된 헤더 파일
void append(char *dst, char c);
void main(void) { //+-*으로 이뤄진 연산 string에서 *먼저 해주는 함수
	char str[] = "1-0*0-1";
	char rearranged[101] = { "" };
	char temp[101] = { "" };//연속된 숫자
	char mul[101] = { "" };
	
	int len_str = strlen(str);
	int i, j;

	int p;
	char p_string[101] = { "" };

	for (i = 0; i <= len_str; i++) { //마지막 빈 곳으로 한칸 더 가서 밑에 else에 걸리게 해서 마지막 숫자까지확인!
		if (str[i] >= '0'&&str[i] <= '9') {
			append(temp, str[i]);
		}
		else if (str[i] == '+') {
			strcat(rearranged, temp);
			append(rearranged, '+');
			temp[0] = '\0';
		}
		else if (str[i] == '-') {
			strcat(rearranged, temp);
			append(rearranged, '-');
			temp[0] = '\0';
		}
		else if (str[i] == '*') {
			i++;
			while (str[i] >= '0'&&str[i] <= '9') {
				append(mul, str[i]);
				i++;
			}
			p=atoi(temp)*atoi(mul);
			sprintf(p_string, "%d", p);
			strcat(rearranged, p_string);
			temp[0] = '\0';
			mul[0] = '\0';
			i--;
		}
		
	}
	if (temp != 'W0') strcat(rearranged, temp);
	printf("%s\n", rearranged);
}
void append(char *dst, char c) {//문자열의 끝에 문자를 추가하는 함수
	char *p = dst;
	while (*p != '\0') p++; // 문자열 끝 탐색
	*p = c;
	*(p + 1) = '\0';
}