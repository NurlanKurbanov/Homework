#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#define length 100 
using namespace std;

int main() {
	int k = 0;
	int j = 0;
	int numberOfOccurrences = 0;
	char s1[length] = "";
	char s2[length] = "";
	char s3[length] = "";
	char s4[length] = "";

	printf("enter string 1\n");
	fgets(s1, length, stdin);
	printf("enter string 2\n");
	fgets(s2, length, stdin);

	for (unsigned int i = 0; i < strlen(s2) - 1 ; i++) {
		s3[i] = s2[i];
	}
	for (unsigned int i = 0; i < strlen(s1) - 1; i++) {
		s4[i] = s1[i];
	}
	
	for (unsigned int i = 0; i < strlen(s4); i++) {
		char c[length] = "";
		k = 0;
		if (s4[i] == s3[0]) {
			int j = i;
			while (s4[j] == s2[k]) {
				c[k] = s4[j];
				j++; 
				k++;
			}
			if (!(strcmp(s3, c)))
				numberOfOccurrences++;
		}
	}
	printf("Number of occurrences:\t ");
	printf("%d", numberOfOccurrences);
	printf("\n");
	scanf("%d", &k);
}