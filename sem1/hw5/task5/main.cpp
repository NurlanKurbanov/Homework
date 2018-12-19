#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "calculator.h"
#include <iostream>
using namespace std;


int main() {
	printf("Enter the expression\n");
	char string[maxStrLength] = "";
	fgets(string, maxStrLength, stdin);

	const char path1[] = "doc1.txt";
	const char path2[] = "doc2.txt";

	ofstream fout(path1, ios::out);
	fout << string;
	fout.close();

	infixToPostfix(path1, path2);

	ifstream fin(path2, ios::in);
	fin.getline(string, maxStrLength);
	fin.close();
	calc(string, strlen(string));

	scanf("%%");
	return 0;
}