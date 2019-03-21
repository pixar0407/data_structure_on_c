#include <stdio.h>

void func(char *front, char* ans, int *length, int *depth) {

}
int main(void) {
	char str[101];
	char ans[101] = { "" };
	//char ans[] = "123" ;
	int i = 0;
	int count1 = 0, count2 = 0;

	int depth = 0;
	int length = 0;

	char front[101];
	char back[101];

	scanf("%s", &str);

	//1) str의 길이를 측정하는 코드
	for (i = 0; i < 101; i++) {
		count1++;
		if (str[i] == NULL)
			break;
	}
	count1--; length = count1; //최고str길이값을 length에 call by ref로 저장


	func(str, ans, &length, &depth);

	return 0;
}