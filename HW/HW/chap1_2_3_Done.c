#include <stdio.h>  //HW1-2의 솔루션1
#include <stdlib.h> // atoi 함수가 선언된 헤더 파일
#include <string.h> //strlen, strcpy 함수가 선언된 헤더 파일

void check(char *str, int sol, int * none);
void append(char *dst, char c);
void func(char *list, char* ans, int length, int *depth, char c,int sol, int * none); //recursion이 일어나는 함수
int doublezero(char *str);
void main(void) {
	int none = 0;

	char str[101]; //최초의 사용자로 부터 받는 입력입니다. 불변
	int sol;//두번째 입력
	char ans[101] = { "" }; //recursion을 반복하면서 숫자와 operator을 채워나갑니다. call by ref

	int length = 0; //최초로 사용자로 부터 받은 입력의 길이. recursion하는 와중에도 불변
	int depth = 0; //ans에 담기는 '숫자'의 갯수. depth와 length가 일치하는지 확인하여 recursion을 멈춘다.

	scanf("%s", &str);
	scanf("%d", &sol);
	length=strlen(str);
	
	func(str, ans, length, &depth, 'n',sol, &none);
	if (none == 0)
		printf("None\n");
}
//void append(char *dst, char c) {//문자열의 끝에 문자를 추가하는 함수
//	char *p = dst;
//	while (*p != '\0') p++; // 문자열 끝 탐색
//	*p = c;
//	*(p + 1) = '\0';
//}
void append(char *dst, char c) {//문자열의 끝에 문자를 추가하는 함수
	char *p = dst;
	while (*p != '\0') p++; // 문자열 끝 탐색
	*p = c;
	*(p + 1) = '\0';
}
void func(char *list, char* ans, int length, int *depth, char c, int sol, int * none) {//list불변, length 상수 - ans와 depth 는 계속 변함.
	int temp_depth; //recursion 복귀 후 ans와 depth를 구버전으로 update해주기 위한 함수 내 변수들.
	char temp_ans[101];

	switch (c) {
	case '+': {
		append(ans, '+');
		append(ans, list[*(depth)]);
		(*depth)++;
		break; }
	case '*': {
		append(ans, '*');
		append(ans, list[*(depth)]);
		(*depth)++;
		break; }
	case '-': {
		append(ans, '-');
		append(ans, list[*(depth)]);
		(*depth)++;
		break; }
	default: {
		append(ans, list[*(depth)]);
		(*depth)++;
		break; }
	}

	strcpy(temp_ans, ans);//구버전 임시 저장
	temp_depth = *depth;

	if (length != *depth) { //1) recursion이 계속 일어나야 하는 경우
		func(list, ans, length, depth, '+', sol, none);
		strcpy(ans, temp_ans); //최종 출력 후 초기화 되었기 때문에 recursion 복귀 후, ans depth 구버전으로 update
		*depth = temp_depth;

		func(list, ans, length, depth, '*', sol, none);
		strcpy(ans, temp_ans); //최종 출력 후 초기화 되었기 때문에 recursion 복귀 후, ans depth 구버전으로 update
		*depth = temp_depth;

		func(list, ans, length, depth, '-', sol, none);
		strcpy(ans, temp_ans); //최종 출력 후 초기화 되었기 때문에 recursion 복귀 후, ans depth 구버전으로 update
		*depth = temp_depth;

		func(list, ans, length, depth, list[(*depth)], sol, none);
	}
	else { //2) 입력 받은 숫자가 모두 쓰인 경우. 
		check(ans,sol, none);//사칙 연산이 맞는지 확인하고, 맞다면 출력을 해준다.
		ans[0] = '\0'; //최종 출력 후 ans와 depth를 초기화.
		*(depth) = 0;
	}
}
void check(char *str, int sol, int * none) {
	int num[101] = { 0 };
	char operator[101] = { "" };
	char temp[101] = { "" };

	int len_str = strlen(str);
	int len_operator=0;
	int i;
	int j = 0;
	int k = 0;


	for (i = 0; i <= len_str; i++) { //마지막 빈 곳으로 한칸 더 가서 밑에 else에 걸리게 해서 마지막 숫자까지확인!
		if (str[i] >= '0'&&str[i] <= '9') {
			append(temp, str[i]);
		}
		else {
			num[j++] = atoi(temp);
			temp[0] = '\0';
			operator[k++] = str[i];
		} // 끝에 숫자 연속으로 나와서 문제가 될 수 있음.
	}
	
	//곱셈 먼저
	i = 0;
	while (operator[i] != NULL)
	{
		if (operator[i] == '*') {
			num[i] = num[i] * num[i + 1];
			//num 떙겨주기
			j = i;
			while (j<99) {
				num[j + 1] = num[j + 2];
				j++;
			}
			//operator 떙겨주기
			j = i;
			while (operator[j] != NULL) {
				operator[j] = operator[j + 1];
				j++;
			}
		}
		else {
			i++;
		}
	}

	//+, - 하기 
	for (i = 0; i < 101; i++) {
		if (operator[i] == NULL) {
			break;
		}
		else {
			switch (operator[i]) {
			case '+': num[0] += num[i + 1]; break;
			default: num[0] -= num[i + 1]; break;
			}
		}
	}
	//

	//결과
	if (sol == num[0] && doublezero(str)) { //doublezero는 00나 01과 같이 존재하지 않는 형태의 수를 파악하여 출력x.
		printf("%s\n", str);
		(*none)++;
	}

}
int doublezero(char *str) {
	int i;
	int j=0;
	for (i = 0; i < strlen(str); i++) {
		if ( ((str[i] == '0') && (str[i + 1] == '0')) || ((str[i] >= '0'&&str[i] <= '9')&&(str[i-1]=='0'))) {
			return 0;
			break;
		}
	}
}
// 190322 문제점 
//1) none을 출력해야 한다. (main함수의 마지막에 나와야 하지 않을까 / func안에서 check와 소통하면 되지 않을까?)
//2) (해결) 00 : 이런 수가 없다. > doublezero라는 함수를 만들어서 문제 해결
//3) 곱셈은 먼저 : 내가 사직 연산을 설계를 잘못했다. 

/*

int main(void) {
	int num[101] = { 1,0,0,1 };
	char operator[101] = { '-','*','+' };
	int i=0,j;

	//곱셈 먼저
	while (operator[i]!=NULL)
	{
		if (operator[i] == '*') {
			num[i] = num[i] * num[i + 1];
			printf("%d\n", num[i]);
			//num 떙겨주기
			j = i;
			while (j<100) { //여기서 문제
				num[j + 1] = num[j + 2];
				j++;
			}
			//operator 떙겨주기
			j = i;
			while (operator[j] != NULL) {
				operator[j] = operator[j + 1];
				j++;
			}
		} else {
			i++;
		}
	}
	
	for(i=0;i<101;i++)
		printf("호호%d  \n", num[i]);
	printf("%s\n", operator);


	//+, - 하기 
	for (i = 0; i < 101; i++) {
		if (operator[i] == NULL) {
			break;
		}
		else {
			switch (operator[i]) {
			case '+': num[0] += num[i + 1]; break;
			default: num[0] -= num[i + 1]; break;
			}
		}
	}
	printf("\n%d\n", num[0]);
	return 0;


}

*/