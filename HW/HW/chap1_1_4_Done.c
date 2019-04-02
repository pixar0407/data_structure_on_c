#include <stdio.h>
#include <stdlib.h> 
#include <string.h> //HW1-1의 솔루션2. 여러 솔루션 가운데 가장 최적화된 형태.
void append(char *dst, char c);
void func(char *str, char* ans, int length, int *depth, char c); //recursion이 일어나는 함수
void main(void) {
	char str[101]; //최초의 사용자로 부터 받는 입력입니다. 불변
	char ans[101] = { "" }; //recursion을 반복하면서 숫자와 '/'을 채워나간다.

	int length = 0; //최초로 사용자로 부터 받은 입력의 길이. recursion하는 와중에도 불변
	int depth = 0; //ans에 담기는 '숫자'의 갯수. depth와 length가 일치하는지 확인하여 recursion을 멈춘다.

	scanf("%s", str);
	length = strlen(str);

	func(str, ans, length, &depth, 'n');
}
void append(char *dst, char c) {
	char *p = dst;
	while (*p != '\0') p++; // 문자열 끝 탐색
	*p = c;
	*(p + 1) = '\0';
}
void func(char *str, char* ans, int length, int *depth, char c) {//str불변, length 상수 || ans와 depth 변화
	int temp_depth; //recursion 복귀 후 ans와 depth를 구버전으로 update해주기 위한 함수 내 변수들.
	char temp_ans[101];

	switch (c) {
	case '/': {
		append(ans, '/');
		append(ans, str[*(depth)]);
		(*depth)++;
		break; }
	default: {
		append(ans, str[*(depth)]);
		(*depth)++;
		break; }
	}
	strcpy(temp_ans, ans);//구버전 임시 저장
	temp_depth = *depth;

	if (length != *depth) {
		func(str, ans, length, depth, '/');
		strcpy(ans, temp_ans); //최종 출력 후 최기화 되었기 때문에 recursion 복귀 후, ans depth 구버전으로 update
		*depth = temp_depth;
		func(str, ans, length, depth, str[(*depth)]);
	}
	else {
		printf("%s\n", ans);
		ans[0] = '\0'; //최종 출력 후 ans와 depth를 초기화.
		*(depth) = 0;
	}
}
