# data_structure_on_c
data structure course, 19-1 at Sogang Univ

## March, 11, 2019 @project2
1.3 Algorithm Specification, Book "Fundamentals of Data Structure in C, 2nd, Horowitz&Sahni"<br>


***

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
p381-p490<br>
* TYPE형 구조체(struct) 변수의 멤버로 TYPE형 포인터 변수를 둘 수 있다.
* typedef 선언
<pre><code>
	typedef struct point
	{
		int xpos;
		int ypos;
		struct point * ptr; // 구조체 point의 포인터 변수 선언
	} Point; // 또는 아래와 같이
	typedef struct point Point;
	...
	int main(void)
	{
		Point point pos1{1,1}; // 이렇게 내가 선언해 준 type을 바로 써 줄 수 있다.
		struct point pos1{2,2};

		pos1.ptr = &pos2;
		pos2.ptr = &pos3;
		pos3.ptr = &pos1;

		printf("%d %d", pos1.ptr->xpos, pos1.ptr->ypos);
		...
	}
</code></pre>
## March, 11, 2019 @ project1
p391-p499<br>
* 공용체(Union)는 같은 주소에 다른 type으로 저장할 수 있게 해준다.
<pre><code>
	typedef struct dbshort
	{
		unsigned short upper;
		unsigned short lower;
	} DBShort;

	typedef union rdbuf 
	{
		int iBuf;
		char bBuf[4];
		DBShort sBuf;
	} RDBuf; //라고 선언 후 
	...
	printf("상위 2바이트 %u \n", buf.sBuf.upper);               // ( 1 Byte )( 1 Byte )( 1 Byte )( 1 Byte )
	printf("하위 2바이트 %u \n", buf.sBuf.lower);               // (bBuf[0] )(bBuf[1] )(bBuf[2] )(bBuf[3] )
	printf("상위 1바이트 아스키 코드: %c \n", buf.bBuf[0]);      // (    sBuf.upper    )(    sBuf.lower    )
	printf("하위 1바이트 아스키 코드: %c \n", buf.bBuf[3]);      // (                iBuf                  )
</code></pre>
* 열거형(Enum)은 이름(ex Do Re Mi)를 연관된 상수로 선언할 수 있도록 한다.
<pre><code>
	enum syllable
	{
		Do=1, Re=2, Mi=3, Fa=4
	} Syllable;
	// 또는 
	enum color {RED=1, BLUE=2, WHITE=3};
</code></pre>
### 이상 "윤성우 열혈 C 프로그래밍" 복습 끝!