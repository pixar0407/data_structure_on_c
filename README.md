# Data Structure on C
data structure course, 19-1 at Sogang Univ
### March, 13, 2019 @project2
* Array as ADT(Abstract Data Type)
  index를 넣으면 상응하는 value가 나오는 함수이다. (1:1대응)<br>
  
  Array(Function) | *Array* Create(j, list) - Creater, j는 크기. 결과로 list라는 Array을 return 해야 한다. <br>
                  | *Item* Retrieve(A, i) - Observer, A라는 Array의 i 인덱스에 접근하여 하면, item를 return해야 한다. <br>
                  | *Array* Store(A, i, x) - Transformer, A라는 Array의 i 인덱스에 접근하여, x 값을 저장하고, 다시 Array를 반환한다.	 <br>

### March, 12, 2019 @project2
1.5.3 Asymptotic Notation
* 팁 : 2차원 배열 동일한 간격으로 뽑고 싶으면
```c
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%5d", list[i][j]); // 이와 같이 간격을 주어 출력하면 된다.
		}
		printf("\n");
	}
	printf("\n\n");
```
### March, 11, 2019 @project2
1.3 Algorithm Specification, Book "Fundamentals of Data Structure in C, 2nd, Horowitz&Sahni"<br>
* switch 문에서는 break;가 없으면 case에 성립 안해도 아래 코드 다 실행한다. 아니면, return을 줘도 된다.
```c
	switch (COMPARE(list[middle], searchnum)) {
		case -1: left = middle + 1;
			break; // 여기서 break가 없으면 문제가 발생한다.
		case 0: return middle; // 3칸 위의 코드가 실행되고, 나서 뽝! 결과. //return 후에는 빠져 나온다.
		case 1: right = middle - 1;
	}
```
* p14에 while을 if로 바꾸라고 하는데, while로 그대로 해도 되는데?<br>
* Array of Character
```c
	char list[] = { a, b, c, d }; // (X) 여기서는 a, b, c, d를 변수라고 본다.
	char list[] = { 'a', 'b', 'c', 'd' }; // (O)
```
* define으로 선언한 SWAP은 Call by Reference 인가?<br>
```c
	#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
	...
	SWAP(list[i], list[j], temp); 
	perm(list, i + 1, n);          //여기서 SWAP된 list가 넘어간다.
	SWAP(list[i], list[j], temp); 
	...
```
1.5 Performance Analysis
* Space Complexity : S(p) = c + Sp(I)
  I가 고정값이면, Sp(3)는 0이다. array처럼 dependent on particular I(n개)해야 Sp(I)=Sp(n)=n이다. Recursion의 횟수도 곱으로 포함된다.<br>
  Call-by-Reference이면 Sp()=0이다.<br>
* Time Complexity : s/e 방식을 쓰되, for문이나 while의 마지막 false도 1회차로 count한다.
```c
	int i; //이건 count 하지 않는다.
	int j=0; //이건 count 한다.
	return i; //이것도 count 한다.
```
***
***
### March, 6, 2019 @ project1
p274-p308, book "윤성우 열혈 C 프로그래밍" <br> 
* 포인터 변수의 크기는 프로그램이 32bits로 돌아가냐, 64bits으로 돌아가냐에 따라 다르다.<br>
  32bit의 경우, 주소를 32bits로 표현하기 때문에 4byte고 64bit의 경우, 8byte이다.

* 문자열을 저장하는 포인터 배열
```c
	char * strArr[2]={"Simple", "String"};//char * strArr[2]={0x1004, 0x1048}; 큰따옴표로 묶여서 표현되는 문자열은 그 형태에 상관없이 메모리 공간에 저장된 후 그 주소값을 반환
	printf("%s \n", strArr[0]);
	printf("%s \n", strArr[1]);
```
### March, 7, 2019 @ project1
p309-p342<br> 

* arr[i]==*(arr+i)<br>
* (arr+i)==&arr[i]<br> //arr+i 했을 때, i만큼 증가하는 것에서 int인지, char 인지 어떻게 알지? sizeof(int)로 알 수 있다.
```c
	int arr1[2][2] = {
	{1,2}, {3,4}
    };
	int (*ptr)[2]; // 포인터 연산(ptr+1)시 int 만큼 2칸씩 ( int int ) 증가하는 포인터! 
	tpr=arr1; //
	printf("%d %d", ptr[1][0], ptr[0][0]); // 주소를 잘 찾아가고, []로 잘 꺼낸다.
```
### March, 9, 2019 @ project1
p343-p380<br> 
* 포인터의 사용 목적은 <strong>가리키기</strong>위함이다. <br>
* 딱딱한 말로는 변수의 주소값을 저장하기 위함이다.<br>
```c
	int num = 10;
	int *ptr = &num; // ptr은 &num이에요. 
	int **dptr = &ptr; // **dptr = ptr이 아니다. 
	int ***tptr = &dptr;

	printf("%d %d \n", **dptr, ***tptr);
	printf("%p %p \n", ptr, &ptr); //아하! dptr은 가리키고 싶은 거에요. 무엇을? ptr를. 때문에 &ptr이라고 해야함.	
```
* 포인터는 이름을 기준으로 생각하자.
```c
	int * arr1[20]; //arr1이 가리키는 첫 번째 요소는 int형 싱글 포인터이니, '배열이름 arr1'은 int형 더블 포인터가 된다.
	double * arr2[30]; //arr2가 가리키는 첫 번째 요소는 double형 싱글 포인터이니, '배열이름' arr2는 double형 더블 포인터이다.
```
### March, 10, 2019 @ project1
p381-p490<br>
* TYPE형 구조체(struct) 변수의 멤버로 TYPE형 포인터 변수를 둘 수 있다.
* typedef 선언
```c
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
```
### March, 11, 2019 @ project1
p391-p499<br>
* 공용체(Union)는 같은 주소에 다른 type으로 저장할 수 있게 해준다.
```c
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
```
* 열거형(Enum)은 이름(ex Do Re Mi)를 연관된 상수로 선언할 수 있도록 한다.
```c
	enum syllable
	{
		Do=1, Re=2, Mi=3, Fa=4
	} Syllable;
	// 또는 
	enum color {RED=1, BLUE=2, WHITE=3};
```
#### 이상 "윤성우 열혈 C 프로그래밍" 공부 끝!