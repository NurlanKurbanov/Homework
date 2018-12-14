#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
using namespace std;


int main() {
	int beginning = 0;
	int length = 0;
	int maxLength = 0;

	const int maxStrLength = 100;
	char string[maxStrLength] = "";

	int numberOfWords = 0;

	fgets(string, maxStrLength, stdin);

	bool inWord = false;
	for (int i = 0; i < strlen(string) - 1; i++) {
		if (string[i] != ' ' &&  inWord == false){
			inWord = true;
			numberOfWords++;
		}
		else if (string[i] == ' ')
			inWord = false;

		if (isalpha(string[i])) {
			length ++;
		}
		if (!isalpha(string[i])) {
			if (length > maxLength) {
				maxLength = length;
				beginning = i - length;
				length = 0;
			}
		}
	}

	int alp[256];
	for (int i = 0; i < 256; i++)
		alp[i] = 0;

	int numberOfDifferentSignes = 1;
	for (int i = beginning; i < beginning + maxLength - 1; i++) {
		alp[string[i]]++;
	}
	for (int i = 0; i < 256; i++) {
		if (alp[i] == 1)
			numberOfDifferentSignes++;
	}

	printf("Number Od words:\n");
	printf("%d\n", numberOfWords);
	printf("numberOfDifferentSignes\n");
	printf("%d",numberOfDifferentSignes);
	scanf("%d", &numberOfWords);
}