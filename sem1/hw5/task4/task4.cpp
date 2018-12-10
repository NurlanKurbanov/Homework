#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "calculator.h"
using namespace std;


int main() {
	char *expression = new char[maxLength];
	printf("Enter the expression:\t");
	fgets(expression, maxLength, stdin);
	int lengthOfExpression = strlen(expression);
	Stack *stack1 = createStack();

	calc(expression, lengthOfExpression, stack1);

	printf("%d", returnTop(stack1));
	scanf("%%");
	delete[] expression;
	return 0;
}
