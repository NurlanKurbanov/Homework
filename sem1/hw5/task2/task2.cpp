#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;

void removeDuplicateLettersInWords(FILE *fout, char *string, int beginning, int end) {

	bool wasInThisWord[256]; 
	for (int i = 0; i < 256; i++)
		wasInThisWord[i] = false;

	for (int i = beginning; i < end; i++) {
		if (isalpha(string[i])) {
			int number = (int)tolower(string[i]);
			if (!wasInThisWord[number]) {
				wasInThisWord[number] = true;
				fprintf(fout, "%c", string[i]);
			}
		}
		else 
			fprintf(fout, "%c", string[i]);
	}
}

int main() {
	const int maxStringLength = 256;
	char line[maxStringLength];

	FILE *fin = fopen("doc.txt", "rt");
	FILE *fout = fopen("resul.txt", "wt");

	while (!feof(fin)) {

		fgets(line, maxStringLength, fin);
		int length = strlen(line);
		int beginning = 0;

		for (unsigned int i = 0; i < length; i++) {
			if (line[i] == ' ') {
				removeDuplicateLettersInWords(fout,line, beginning, i + 1);
				beginning = i++;
			}
		}
		removeDuplicateLettersInWords(fout, line, beginning, length);
	}


	fclose(fin);
	fclose(fout);
	
	return 0;
}