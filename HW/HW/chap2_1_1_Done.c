#include <stdio.h> //2.7 String HW2-1 Done
#include <string.h>
#define max_string_size 100
#define max_pattern_size 100
void pmatch_all(char *string, char *pat, int *failure);
void fail(char *pat, int *failure);
/* input
abcabcacab
bbbbbabbbbbc */
int main(void) {
	char string[max_string_size];
	char pat[max_pattern_size];
	int failure[max_pattern_size] = { 0 };

	scanf("%s", string);
	scanf("%s", pat);
	fail(pat, failure);

	pmatch_all(string, pat, failure);

	return 0;
}
void fail(char * pat, int *failure) {
	int n = strlen(pat), j = 0, i = 0;
	failure[0] = -1;
	for (j = 1; j < n; j++) {
		i = failure[j - 1];
		while ((pat[j] != pat[i + 1]) && (i >= 0))
			i = failure[i];

		if (pat[j] == pat[i + 1])
			failure[j] = i + 1;
		else failure[j] = -1;
	}
}
void pmatch_all(char *string, char *pat, int *failure) {
	int i = 0, j = 0;
	int lens = strlen(string); //i
	int lenp = strlen(pat);    //j
	while (i < lens && j < lenp) { //현재 i가 끝나지 않아도, j가 lenp에 도달하면, while문을 빠져나감.
		if (string[i] == pat[j]) {
			i++; j++;
		}
		else if (j == 0) i++; //처음부터 안 맞았으므로 string 1 증가
		else j = failure[j - 1] + 1;

		if (j == lenp) {
			printf("%d\n", i - lenp);
			if (failure[j - 1] == -1) {
				j = j - lenp; // j=0
			}
			else {
				j = failure[j - 1] + 1;
			}
		}
	}
}
