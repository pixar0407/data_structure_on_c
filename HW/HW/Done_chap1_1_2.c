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

	//recursion ����
	if (*(depth) == *(length)) { // ���� ����
		
	}
	else {
		for (i = 1; i <= len_list; i++) { //���⼭ i�� front�� ���̷� update�Ǿ�, (i)for �ȿ����� ���ó�� ���δ�.

			len_ans = 0; // (i)for������ �ݺ� �� �ٵ�, for�� �ȿ��� �ʱ�ȭ �ؾ� �Ѵ�.
			for (j = 0; j < 101; j++) {
				len_ans++;
				if (ans[j] == NULL)
					break;
			}
			len_ans--;

			//ans�� temp�� �־ �Ͻ�����
			temp[0] = '\0';
			//temp������ֱ�
			for (j = 0; j <= len_ans - 1; j++)
				temp[j] = ans[j];
			temp[j] = 0;

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
			//ans�� front�� �ٿ��ִ� �۾��� �����մϴ�.
			//ans�� ���̸� �����մϴ�.
			len_ans = 0; // (i)for������ �ݺ� �� �ٵ�, for�� �ȿ��� �ʱ�ȭ �ؾ� �Ѵ�.
			for (j = 0; j < 101; j++) {
				len_ans++;
				if (ans[j] == NULL)
					break;
			}
			len_ans--;
			for (j = 0; j <= i - 1; j++) { // front�� ���̸�ŭ �ؾ� ����? ���⼭ len_ans�� depth�� �ٸ���. '/' ������
				ans[len_ans + j] = front[j];
			}
			*depth += i;

			if (*depth != *length) { 
				ans[i + len_ans] = '/';
				ans[i + len_ans+1] = 0;
				func(back, ans, length, depth); // ������ʹ� length�� depth�� pointer�Դϴ�.
			}
			else {//���� á�ٸ�, ������ '/'�߰����� ��rh, �ٷ� ����� �ش�.
				printf("%s\n", ans);
				ans[0] = '\0';
				*(depth) = 0;
			}

			//�������̷� ���ƿ� ģ���� �ٽ� ä����� �Ѵ�.
			*depth = temp_depth;
			//ans ���������� ������ֱ�
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

	//1) str�� ���̸� �����ϴ� �ڵ�
	for (i = 0; i < 101; i++) {
		count1++;
		if (str[i] == NULL)
			break;
	}
	count1--; length = count1; //�ְ�str���̰��� length�� call by ref�� ����
	

	func(str, ans, &length, &depth);
	return 0;
}