#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"


int type(char symbol) 
{
	if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
		return 1;
	if (isdigit(symbol))
		return 2;
	if (symbol == ' ')
		return 3;
	return -1;
}


int operation(char symbol, int a, int b) 
{
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


void calc(char *expression, int lengthOfExpression)
{
	Stack *stack = createStack();
	for (int i = 0; i < lengthOfExpression; i++) {
		switch (type(expression[i]))
		{
		case 1:
			if (stack->count == 1) {
				push(stack, 0);
				stack->top->previous->value = operation(expression[i], stack->top->value, stack->top->previous->value);
			}
			else {
				stack->top->previous->value = operation(expression[i], stack->top->previous->value, stack->top->value);
			}
			pop(stack);
			break;
		case 2:
			if (i != 0 && isdigit(expression[i - 1]))
				stack->top->value = 10 * stack->top->value + (expression[i] - '0');
			else
				push(stack, expression[i] - '0');
			break;
		}

	}
	printf("%d", returnTop(stack));
}