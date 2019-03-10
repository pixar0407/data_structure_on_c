# data_structure_on_c
data structure course, 19-1 at Sogang Univ

## March, 6, 2019 @ project1
p274-p308, book "윤성우 열혈 C 프로그래밍" <br> 

## March, 7, 2019 @ project1
p309-p342<br> 

* arr[i]==*(arr+i)<br>
<pre><code>
	int arr1[2][2] = {
	{1,2}, {3,4}
    };
	int (*ptr)[2]; // 포인터 연산(ptr+1)시 int 만큼 2칸씩 ( int int ) 증가하는 포인터! 
	tpr=arr1; //
	printf("%d %d", ptr[1][0], ptr[0][0]); // 주소를 잘 찾아가고, []로 잘 꺼낸다.
</code></pre>
## March, 9, 2019 @ project1
p343-p380<br> 
* 포인터의 사용 목적은 <strong>가리키기</strong>위함이다. <br>
* 딱딱한 말로는 변수의 주소값을 저장하기 위함이다.<br>
<pre><code>
	int num = 10;
	int *ptr = &num; // ptr은 &num이에요. 
	int **dptr = &ptr; // **dptr = ptr이 아니다. 
	int ***tptr = &dptr;

	printf("%d %d \n", **dptr, ***tptr);
	printf("%p %p \n", ptr, &ptr); //아하! dptr은 가리키고 싶은 거에요. 무엇을? ptr를. 때문에 &ptr이라고 해야함.	
</code></pre>
* 포인터는 이름을 기준으로 생각하자.
<pre><code> 
	int * arr1[20]; //arr1이 가리키는 첫 번째 요소는 int형 싱글 포인터이니, '배열이름 arr1'은 int형 더블 포인터가 된다.
	double * arr2[30]; //arr2가 가리키는 첫 번째 요소는 double형 싱글 포인터이니, '배열이름' arr2는 double형 더블 포인터이다.
</code></pre>
## March, 10, 2019 @ project1
p381-p415<br>
* TYPE형 구조체 변수의 멤버로 TYPE형 포인터 변수를 둘 수 있다.
<pre><code>
	struct point
	{
		int xpos;
		int ypos;
		struct point * ptr; // 구조체 point의 포인터 변수 선언
	}

	...

	int main(void)
	{
		struct point pos1{1,1};
		struct point pos1{2,2};

		pos1.ptr = &pos2;
		pos2.ptr = &pos3;
		pos3.ptr = &pos1;

		printf("%d %d", pos1.ptr->xpos, pos1.ptr->ypos);
		...
	}
</code></pre>
