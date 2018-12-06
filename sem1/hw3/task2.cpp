#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

int main() {
	const int size = 50;
	char *s1 = new char[size];
	char *s2 = new char[size];
	printf("enter the first string\n");
	fgets(s1, size, stdin);
	printf("enter the first string\n");
	fgets(s2, size, stdin);


	if (strlen(s1) == strlen(s2)) {

		int const  arraySize = 256;
		int firstLineCharacters[arraySize];
		int secondLineCharacters[arraySize];
		for (int i = 0; i < arraySize; i++) {
			firstLineCharacters[i] = 0;
			secondLineCharacters[i] = 0;
		}

		for (int i = 0; i < strlen(s1); i++) 
		{
			firstLineCharacters[s1[i]]++;
			secondLineCharacters[s2[i]]++;
		}

		bool areEqual = true;
		for (int i = 0; i < arraySize; i++) {
			if (firstLineCharacters[i] != secondLineCharacters[i])
				areEqual = false;
		}

		if (areEqual)
			printf("The second line can be obtained by rearranging the characters in the first");
		else
			printf("The second line can't be obtained by rearranging the characters in the first");
	}
	else
		printf("The second line can't be obtained by rearranging the characters in the first");

	scanf("%%");
	delete[] s1;
	delete[] s2;
	return 0;
}
