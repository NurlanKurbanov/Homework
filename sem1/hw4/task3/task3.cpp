#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdio>
#include <fstream>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;
int const maxStringLength = 100;


int numberOfNonEmptyLines(const char *path) {
	FILE *file = fopen(path, "rt");

	if (file == NULL) {
		printf("file is empty");
		return -1;
	}

	char line[maxStringLength];
	int nonEmptyLines = 0;
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
			nonEmptyLines++;
	}

	fclose(file);
	return nonEmptyLines;
}


int main() {
	const char path[] = "doc.txt";
	printf("number of non-empty lines:\t");
	printf("%d", numberOfNonEmptyLines(path));
	scanf("%%");
	return 0;
}
