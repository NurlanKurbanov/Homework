#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack.h"
using namespace std;


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


int main() {

	ifstream fin("doc1.txt");
	ofstream fout("doc2.txt");
	Stack *stack1 = createStack();
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
					return 1;
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
			return 1;
		}
		fout << returnTop(stack1) << ' ';
		pop(stack1);
	}
	fout.close();

	deleteStack(stack1);
	return 0;
}