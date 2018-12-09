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


void infixToPostfix(const char *path1, const char *path2, Stack *stack)
{
	ifstream fin(path1);
	ofstream fout(path2);
	char ch = 0;


	while (fin >> ch) {
		switch (type(ch))
		{
		case 1:
			while (type(returnTop(stack)) == 1 && prior(ch) <= prior(returnTop(stack))) {
				fout << returnTop(stack) << ' ';
				pop(stack);
			}
			push(stack, ch);
			break;

		case 2:
			push(stack, ch);
			break;
		case 3:
			while (returnTop(stack) != '(') {
				if (isEmpty(stack)) {
					fout << ' ' << "Error: not enough parentheses\n";
					printf("Error: not enough parentheses");
					return;
				}
				fout << returnTop(stack) << ' ';
				pop(stack);
			}
			pop(stack);
			if (type(ch) == 1)
				fout << ch << ' ';
			break;
		case 4:
			fout << ch << ' ';
			break;
		}
	}
	fin.close();

	while (!isEmpty(stack)) {
		if (returnTop(stack) == '(') {
			fout << ' ' << "Error: not enough parentheses\n";
			printf("Error: not enough parentheses");
			return;
		}
		fout << returnTop(stack) << ' ';
		pop(stack);
	}
	fout.close();
}