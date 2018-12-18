#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "infixToPostfix.h"
using namespace std;


int main() {

	const char path1[] = "doc1.txt";
	const char path2[] = "doc2.txt";
	infixToPostfix(path1, path2);

	
	return 0;
}