#include <stdio.h> //2.7 String HW2-1 Done
#include <string.h>
#define max_string_size 100
#define max_pattern_size 100
int pmatch(char *string, char *pat);
void fail(char *pat);
int failure[max_pattern_size] = {3};
/*
abcabcacab

bbbbbabbbbbc
*/
char string[max_string_size] = "bbbbbabbbbbabc";
char pat[max_pattern_size] = "aa";
int main(void) {
	int i;

	fail(pat);
	for (i = 0; failure[i] < max_pattern_size; i++)
		printf("%2d", failure[i]);
	printf("\n");

	return 0;
}
void fail(char * pat) {
	int n = strlen(pat), j=0, i=0;
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
int pmatch(char *string, char *pat) {
	int ans[101];
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
			printf("%d\n", i-lenp);
			if (failure[j - 1] == -1) {
				j = j - lenp; // j=0
			}
			else {
				j = failure[j - 1] + 1;
			}
			
		}
	}
}
