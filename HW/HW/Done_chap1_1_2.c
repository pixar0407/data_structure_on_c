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


	//반복의 시작과 반복문 안에서 recursion
	for (i = 1; i <= len_list; i++) { //여기서 i는 front의 길이로 update되어, (i)for 안에서는 상수처럼 쓰인다.


		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@기존의 배열 이전 버전
		//temp 뽑기 위해서
		//len_ans = 0; // (i)for문에서 반복 될 텐데, for문 안에서 초기화 해야 한다. 바로 ++로 들어가면 안된다.
		//for (j = 0; j < 101; j++) {
		//	len_ans++;
		//	if (ans[j] == NULL)
		//		break;
		//} len_ans--; // 길이의 정량을 저장.
		//ans를 temp에 넣어서 일시저장. recursion이 끝나고 나서 ans를 구버전으로 복원하는 용도. 
		//temp[0] = '\0';
		////temp만들어주기
		//for (j = 0; j <= len_ans - 1; j++)
		//	temp[j] = ans[j];
		//temp[j] = 0;
		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@기존의 배열 이전 버전


		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@배열 이전하기 다른 버전
		temp[0] = '\0';
		for (j = 0; j <= 101; j++) {
			if (ans[j] == NULL)
				break;
			else
				temp[j] = ans[j];
		} temp[j] = 0;

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

		
		//ans의 길이를 측정합니다.
		len_ans = 0; // (i)for문에서 반복 될 텐데, for문 안에서 초기화 해야 한다.
		for (j = 0; j < 101; j++) {
			len_ans++;
			if (ans[j] == NULL)
				break;
		}
		len_ans--;

		//ans에 front를 붙여주는 작업을 시작합니다.
		for (j = 0; j <= i - 1; j++) { // front의 길이만큼 해야 겠죠? 여기서 len_ans는 depth와 다르다. '/' 때문에
			ans[len_ans + j] = front[j];
		}
		*depth += i;

		//recursion을 끝낼 지, 계속 recursion할지 결정합니다.
		if (*depth != *length) { //아직 최종까지 도달하지 못했다면, recursion을 한다.
			ans[i + len_ans] = '/'; 
			ans[i + len_ans+1] = 0;
			func(back, ans, length, depth); //여기서는 length와 depth가 pointer입니다.
		}
		else {//가득 찼다면, 마지막 '/'추가하지 않고, 바로 출력을 주며, recursion을 종료한다.
			printf("%s\n", ans);
			ans[0] = '\0';
			*(depth) = 0;
		}

		//recursion이 끝나는 지점에서 depth와 ans를 초기와 시켰습니다. 다시 복귀한 지점에서의 ans와 depth로 복원.
		*depth = temp_depth;
		for (j = 0; j <= i + len_ans - 1; j++)
			ans[j] = temp[j];
		ans[j] = 0;
	}
}
int main(void) {
	char str[101]; //최초의 사용자로 부터 받는 입력입니다.
	char ans[101] = { "" }; //recursion을 반복하면서 숫자와 '/' 출력을 채워나갑니다. call by ref
	int i=0;

	int length = 0; //최초로 사용자로 부터 받은 입력의 길이.
	int depth = 0; //ans에 담기는 숫자의 갯수. depth와 length가 일치하는지 확인하여 recursion을 멈춘다.
	
	scanf("%s", &str);

	//1) str의 길이를 측정하는 코드
	for (i = 0; i < 101; i++) {
		length++;
		if (str[i] == NULL)
			break;
	} length--; //최고 str 길이값을 length에 call by ref로 저장

	func(str, ans, &length, &depth);
	return 0;
}