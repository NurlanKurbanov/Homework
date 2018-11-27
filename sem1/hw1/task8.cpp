#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
using namespace std;

int fact(int factorial) {
	int x = 1;
	for (int i = 1; i < factorial + 1; i++)
		x *= i;
	return x;
}
int factRec(int factorial) {
	if (factorial == 0)
		return 1;
	else
		return factorial * factRec(factorial - 1);
}

int main() {
	int factorial = 1;

	printf("enter the factorial\t");
	scanf("%d", &factorial);
	printf("\n");
	printf("result\t");

	if (factorial < 0)
			printf("error");
	else {
		printf("%d", fact(factorial));
		printf("\t");
		printf("%d", factRec(factorial));
	}
	scanf("%d", &factorial);
	return 0;
}