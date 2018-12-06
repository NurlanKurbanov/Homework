#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;
int const maxStringLength = 100;


int numberOfNonEmptyLines(const char *path) {
	FILE *file = fopen(path, "rt");

	if (file == NULL) {
		printf("file is empty");
		return -1;
	}
	else {
		char line[maxStringLength];
		int NonEmptyLines = 0;

		while (fgets(line, maxStringLength, file)) {
			bool isEmpty = true;

			if (line[0] == '\n')
				isEmpty = true;
			else {
				for (unsigned int i = 0; i < strlen(line); i++) {
					if (line[i] != ' ')
						isEmpty = false;
				}
			}
			if (!isEmpty)
				NonEmptyLines++;
		}
		return NonEmptyLines;
	}
	fclose(file);
}


int main() {
	const char path[] = "doc.txt";
	printf("number of non-empty lines:\t");
	printf("%d", numberOfNonEmptyLines("doc.txt"));
	scanf("%%");
	return 0;
}
