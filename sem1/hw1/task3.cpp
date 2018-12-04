#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstring>    
#include <algorithm>
using namespace std;

void swap(char *x, int length, int a, int b) {     
	for (int i = 0; i < length/2  ; i++)
		swap (x[a + i], x[b - 1 - i]);
}

int main() {
	char str[] = "abcdefg";
	int length = strlen(str);
	int length1 = 0;
	printf("enter the length of the first segment\t");
	scanf("%d", &length1);

	swap(str, length1, 0, length1);
	swap(str, length - length1, length1, length);
	swap(str, length, 0, length);

	printf("changed segments:\n");
	printf(str);
	printf("\n");
	scanf("%%");
	return 0;
}
