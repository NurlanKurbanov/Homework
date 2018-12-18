#define _CRT_SECURE_NO_WARNINGS
#include "infixToPostfix.h"

int prior(char symbol) {
	if (symbol == '+' || symbol == '-')
		return 1;
	if (symbol == '*' || symbol == '/')
		return 2;
}


int type(char symbol) {
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
		switch (type(ch))
		{
		case 1:
			while (type(returnTop(stack1)) == 1 && prior(ch) <= prior(returnTop(stack1))) {
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
			if (type(ch) == 1)
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