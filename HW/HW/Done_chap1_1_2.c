#include <stdio.h> //HW1-1 내가 만든 첫번째 답안
void func(char *list, char* ans,int *length, int *depth) { //length(초기 str길이)와 depth(front합값)는 call by ref.
	char front[101];
	char back[101];
	char temp[101];
	int temp_depth=*depth;

	int i,j;//이 변수들은 for문에서 초기화가 될 예정입니다.
	int len_list=0; // 변수 초기화를 잘 해줍시다.
	int len_ans=0;


	//정보 획득
	//list의 길이를 측정하는 코드
	for (i = 0; i < 101; i++) {
		len_list++;
		if (list[i] == NULL)
			break;
	}
	len_list--;

	//recursion 시작
	if (*(depth) == *(length)) { // 종료 조건
		
	}
	else {
		for (i = 1; i <= len_list; i++) { //여기서 i는 front의 길이로 update되어, (i)for 안에서는 상수처럼 쓰인다.

			len_ans = 0; // (i)for문에서 반복 될 텐데, for문 안에서 초기화 해야 한다.
			for (j = 0; j < 101; j++) {
				len_ans++;
				if (ans[j] == NULL)
					break;
			}
			len_ans--;

			//ans를 temp에 넣어서 일시저장
			temp[0] = '\0';
			//temp만들어주기
			for (j = 0; j <= len_ans - 1; j++)
				temp[j] = ans[j];
			temp[j] = 0;

			front[0] = '\0';
			//front만들어주기
			for (j = 0; j <= i-1; j++)
				front[j] = list[j];
			front[j] = 0;

			back[0] = '\0';
			//back만들어주기
			for (j = 0; j <= len_list - i; j++)
				back[j] = list[i + j];
			back[j] = 0;
			//ans에 front를 붙여주는 작업을 시작합니다.
			//ans의 길이를 측정합니다.
			len_ans = 0; // (i)for문에서 반복 될 텐데, for문 안에서 초기화 해야 한다.
			for (j = 0; j < 101; j++) {
				len_ans++;
				if (ans[j] == NULL)
					break;
			}
			len_ans--;
			for (j = 0; j <= i - 1; j++) { // front의 길이만큼 해야 겠죠? 여기서 len_ans는 depth와 다르다. '/' 때문에
				ans[len_ans + j] = front[j];
			}
			*depth += i;

			if (*depth != *length) { 
				ans[i + len_ans] = '/';
				ans[i + len_ans+1] = 0;
				func(back, ans, length, depth); // 여기부터는 length와 depth가 pointer입니다.
			}
			else {//가득 찼다면, 마지막 '/'추가하지 않rh, 바로 출력을 준다.
				printf("%s\n", ans);
				ans[0] = '\0';
				*(depth) = 0;
			}

			//빈털털이로 돌아온 친구들 다시 채워줘야 한다.
			*depth = temp_depth;
			//ans 구버전으로 만들어주기
			for (j = 0; j <= i + len_ans - 1; j++)
				ans[j] = temp[j];
			ans[j] = 0;
		}
	}
}
int main(void) {
	char str[101];
	char ans[101] = { "" };
	//char ans[] = "123" ;
	int i=0;
	int count1=0, count2=0;

	int depth = 0;
	int length = 0;



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