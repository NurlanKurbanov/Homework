#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;

int numberOfNonEmptyLines() {

	ifstream file("doc.txt");
	string line;
	int k = 0;

	while (getline(file, line)) {
		bool isEmpty = true;

		if (line[0] == '\n')
			isEmpty = true;
		else {
			for (unsigned int i = 0; i < line.size(); i++) {
				if (line[i] != ' ')
					isEmpty = false;
			}
		}
		if (!isEmpty)
			k++;
	}

	return k;
	file.close();
}

int main() {

	printf("number of non-empty lines:\t");
	printf("%d", numberOfNonEmptyLines());
	
	scanf("%%");
	return 0;
}
