#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack.h"
using namespace std;


int type(char symbol) {
	if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
		return 1;
	if (isdigit(symbol))
		return 2;
	if (symbol == ' ')
		return 3;
	return -1;
}

int operation(char symbol, int a, int b) {
	if (symbol == '+')
		return a + b;
	if (symbol == '-')
		return a - b;
	if (symbol == '*')
		return a * b;
	if (symbol == '/')
		return a / b;
	return -1;
}


int main() {
	char *expression = new char[maxLength];
	printf("Enter the expression:\t");
	fgets(expression, maxLength, stdin);
	int LengthOfExpression = strlen(expression);
	Stack *stack1 = createStack();

	int result;
	for (int i = 0; i < LengthOfExpression; i++) {
		switch (type(expression[i]))
		{
		case 1:
			if (stack1->count == 1) {
				push(stack1, 0);
				stack1->top->previous->value = operation(expression[i], stack1->top->value, stack1->top->previous->value);
			}
			else {
				stack1->top->previous->value = operation(expression[i], stack1->top->previous->value, stack1->top->value);
			}
			pop(stack1);
			break;
		case 2:
			if (i != 0 && isdigit(expression[i - 1]))
				stack1->top->value = 10 * stack1->top->value + (expression[i] - '0');
			else 
				push(stack1, expression[i] - '0');
			break;
		}

	}

	printf("%d", returnTop(stack1));
	delete[] expression;
	return 0;
}
