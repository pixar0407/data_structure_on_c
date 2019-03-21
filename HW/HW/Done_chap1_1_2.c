#include <stdio.h> //HW1-1 ���� ���� ù��° ���
void func(char *list, char* ans,int *length, int *depth) { //length(�ʱ� str����)�� depth(front�հ�)�� call by ref.
	char front[101];
	char back[101];
	char temp[101];
	int temp_depth=*depth;

	int i,j;//�� �������� for������ �ʱ�ȭ�� �� �����Դϴ�.
	int len_list=0; // ���� �ʱ�ȭ�� �� ���ݽô�.
	int len_ans=0;


	//���� ȹ��
	//list�� ���̸� �����ϴ� �ڵ�
	for (i = 0; i < 101; i++) {
		len_list++;
		if (list[i] == NULL)
			break;
	}
	len_list--;


	//�ݺ��� ���۰� �ݺ��� �ȿ��� recursion
	for (i = 1; i <= len_list; i++) { //���⼭ i�� front�� ���̷� update�Ǿ�, (i)for �ȿ����� ���ó�� ���δ�.


		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@������ �迭 ���� ����
		//temp �̱� ���ؼ�
		//len_ans = 0; // (i)for������ �ݺ� �� �ٵ�, for�� �ȿ��� �ʱ�ȭ �ؾ� �Ѵ�. �ٷ� ++�� ���� �ȵȴ�.
		//for (j = 0; j < 101; j++) {
		//	len_ans++;
		//	if (ans[j] == NULL)
		//		break;
		//} len_ans--; // ������ ������ ����.
		//ans�� temp�� �־ �Ͻ�����. recursion�� ������ ���� ans�� ���������� �����ϴ� �뵵. 
		//temp[0] = '\0';
		////temp������ֱ�
		//for (j = 0; j <= len_ans - 1; j++)
		//	temp[j] = ans[j];
		//temp[j] = 0;
		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@������ �迭 ���� ����


		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@�迭 �����ϱ� �ٸ� ����
		temp[0] = '\0';
		for (j = 0; j <= 101; j++) {
			if (ans[j] == NULL)
				break;
			else
				temp[j] = ans[j];
		} temp[j] = 0;

		front[0] = '\0';
		//front������ֱ�
		for (j = 0; j <= i-1; j++)
			front[j] = list[j];
		front[j] = 0;

		back[0] = '\0';
		//back������ֱ�
		for (j = 0; j <= len_list - i; j++)
			back[j] = list[i + j];
		back[j] = 0;

		
		//ans�� ���̸� �����մϴ�.
		len_ans = 0; // (i)for������ �ݺ� �� �ٵ�, for�� �ȿ��� �ʱ�ȭ �ؾ� �Ѵ�.
		for (j = 0; j < 101; j++) {
			len_ans++;
			if (ans[j] == NULL)
				break;
		}
		len_ans--;

		//ans�� front�� �ٿ��ִ� �۾��� �����մϴ�.
		for (j = 0; j <= i - 1; j++) { // front�� ���̸�ŭ �ؾ� ����? ���⼭ len_ans�� depth�� �ٸ���. '/' ������
			ans[len_ans + j] = front[j];
		}
		*depth += i;

		//recursion�� ���� ��, ��� recursion���� �����մϴ�.
		if (*depth != *length) { //���� �������� �������� ���ߴٸ�, recursion�� �Ѵ�.
			ans[i + len_ans] = '/'; 
			ans[i + len_ans+1] = 0;
			func(back, ans, length, depth); //���⼭�� length�� depth�� pointer�Դϴ�.
		}
		else {//���� á�ٸ�, ������ '/'�߰����� �ʰ�, �ٷ� ����� �ָ�, recursion�� �����Ѵ�.
			printf("%s\n", ans);
			ans[0] = '\0';
			*(depth) = 0;
		}

		//recursion�� ������ �������� depth�� ans�� �ʱ�� ���׽��ϴ�. �ٽ� ������ ���������� ans�� depth�� ����.
		*depth = temp_depth;
		for (j = 0; j <= i + len_ans - 1; j++)
			ans[j] = temp[j];
		ans[j] = 0;
	}
}
int main(void) {
	char str[101]; //������ ����ڷ� ���� �޴� �Է��Դϴ�.
	char ans[101] = { "" }; //recursion�� �ݺ��ϸ鼭 ���ڿ� '/' ����� ä�������ϴ�. call by ref
	int i=0;

	int length = 0; //���ʷ� ����ڷ� ���� ���� �Է��� ����.
	int depth = 0; //ans�� ���� ������ ����. depth�� length�� ��ġ�ϴ��� Ȯ���Ͽ� recursion�� �����.
	
	scanf("%s", &str);

	//1) str�� ���̸� �����ϴ� �ڵ�
	for (i = 0; i < 101; i++) {
		length++;
		if (str[i] == NULL)
			break;
	} length--; //�ְ� str ���̰��� length�� call by ref�� ����

	func(str, ans, &length, &depth);
	return 0;
}