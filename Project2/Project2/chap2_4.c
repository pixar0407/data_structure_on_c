#include <stdio.h>
#include <stdbool.h> // boolean을 datetype으로 쓸 수 있도록 해주는 Macro이다. 'bool'로 사용 가능하다.
#define MAX_SIZE 100
#define FALSE 0
#define TRUE 1
float sum(float[], int); //일단 선언하고 Main 함수 뒤에 정의해준다.
float input[MAX_SIZE], answer;
typedef struct {
	int month;
	int day;
	int year;
} date;
typedef struct {
	char name[10];
	int age;
	float salary;
	date dob;
}humanBeing;
int humans_equal(humanBeing person1, humanBeing person2)
{
	if (strcmp(person1.name, person2.name))
		return FALSE;
	if (person1.age != person2.age)
		return FALSE;
	if (person1.salary != person2.salary)
		return FALSE;
	return TRUE;
}
int COMPARE(float a, float b) {
	if (a < b) return -1;
	else if (a == b) return 0;
	else return 1;
}
// polynomial
#define MAX_DEGREE 101
typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

polynomial Zero(void)
{	
	polynomial x = { 0 };
	return x;
}
bool IsZero(polynomial p)
{
	if (p.degree != 0)
		return FALSE;
	else
		return TRUE;
}
float Coef(polynomial p, int expon) {
	if (p.coef[expon] != 0)
		return p.coef[expon];
	else return 0;
}
float LeadExp(polynomial a) // 이렇게 하는거 맞나요?
{
	return a.coef[a.degree];
}
polynomial Attach(polynomial *p, float coef, int exp) {
	if (exp > (*p).degree) // degree 바꾸는 것을 항상 잊지 마시오.
		(*p).degree = exp;
	if ((*p).coef[exp] != 0)
		return (*p);
	else
	{
		(*p).coef[exp] = coef;
		return (*p);
	}
}
polynomial Remove(polynomial *p, int exp)
{
	int i;
	if ((*p).degree == exp) {
		for (i = exp-1; i >= 0; i--) //제거 하고 혹시나 degree가 줄어들 일이 있으면, 줄인다.
		{
			if ((*p).coef[i] != 0)
				(*p).degree = i;
		}
	}
	(*p).coef[exp] = 0;
	return (*p);
}
polynomial Add(polynomial a, polynomial b){
	polynomial d = Zero();
	float sum;
	do {
		switch (COMPARE(LeadExp(a), LeadExp(b))) {
		case -1 : // a < b
			d = Attach(&d, Coef(b,LeadExp(b)), LeadExp(b));
			b = Remove(&b, LeadExp(b));
			break;
		case 0: sum = Coef(a, LeadExp(a)) + Coef(a, LeadExp(b)); // a == b
			if (sum) {
				d = Attach(&d, sum, LeadExp(a));
				a = Remove(&a, LeadExp(a));
				b = Remove(&b, LeadExp(b));
			}
			break;
		case 1: 
			d = Attach(&d, Coef(a, LeadExp(a)), LeadExp(a)); // a > b
			a = Remove(&a, LeadExp(a));
		}
	} while (!IsZero(a) && !IsZero(b)); //////////////////////여깁니다.
	if (IsZero(a)) {
	
	}
	else {

	}
}
// 현재까지 교과서에 있는 것 옮겼고, 필요한 함수들 정의했으며, datatype error가 있다. Add 함수를 바로 위 여깁니다 부분을 완성해야 한다.
int main(void)
{	
	polynomial poly1, poly2;
	bool x;
	poly1 = Zero();
	poly2 = Zero();
	poly1.degree = 5;
	poly1.coef[5] = 5.5;

	printf("degree : %d \n", poly1.degree);
	poly1 = Attach(&poly1, 7.5, 7);

	printf("%f \n", poly1.coef[7]);
	printf("%f \n", LeadExp(poly1));
	printf("degree : %d \n", poly1.degree);

	Remove(&poly1, 7);
	printf("%f \n", LeadExp(poly1));
	printf("degree : %d \n", poly1.degree);



	/*int i;
	for (i = 0; i < MAX_SIZE; i++)
		input[i] = i;
	answer = sum(input, MAX_SIZE);
	printf("The sum is: %f \n", answer);*/



	//humanBeing yanggon = {"kimyanggo", 26, 100}; // kimyanggon이라고 다 저장하면 10이라 꽉 찬다. 이는 문제다.
	//yanggon.dob.month = 4;
	//yanggon.dob.day = 7;
	//yanggon.dob.year = 1994;

	//printf("%d \n", yanggon.dob.month);
	//printf("%s \n", yanggon.name);
	return 0;
}

float sum(float list[], int n)
{
	int i;
	float tempsum = 0;
	for (i = 0; i < n; i++)
		tempsum += list[i];
	return tempsum;
}