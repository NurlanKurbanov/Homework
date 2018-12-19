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


int prior(char symbol) {
	if (symbol == '+' || symbol == '-')
		return 1;
	if (symbol == '*' || symbol == '/')
		return 2;
}


int type1(char symbol) {
	if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
		return 1;
	if (symbol == '(')
		return 2;
	if (symbol == ')')
		return 3;
	if (isdigit(symbol))
		return 4;
}


void infixToPostfix(const char *path1, const char *path2)
{
	Stack *stack1 = createStack();
	ifstream fin(path1, ios::in);
	ofstream fout(path2, ios::out);
	char ch = 0;


	while (fin >> ch) {
		switch (type1(ch))
		{
		case 1:
			while (type1(returnTop(stack1)) == 1 && prior(ch) <= prior(returnTop(stack1))) {
				fout << returnTop(stack1) << ' ';
				pop(stack1);
			}
			push(stack1, ch);
			break;

		case 2:
			push(stack1, ch);
			break;
		case 3:
			while (returnTop(stack1) != '(') {
				if (isEmpty(stack1)) {
					fout << ' ' << "Error: not enough parentheses\n";
					printf("Error: not enough parentheses");
					return;
				}
				fout << returnTop(stack1) << ' ';
				pop(stack1);
			}
			pop(stack1);
			if (type1(ch) == 1)
				fout << ch << ' ';
			break;
		case 4:
			fout << ch << ' ';
			break;
		}
	}
	fin.close();

	while (!isEmpty(stack1)) {
		if (returnTop(stack1) == '(') {
			fout << ' ' << "Error: not enough parentheses\n";
			printf("Error: not enough parentheses");
			return;
		}
		fout << returnTop(stack1) << ' ';
		pop(stack1);
	}
	deleteStack(stack1);
	fout.close();
}