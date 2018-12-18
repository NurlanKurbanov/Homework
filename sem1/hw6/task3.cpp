#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <ctime>
using namespace std;

int numberOfDigits(int a) {
	if (a == 0)
		return 1;
	int k = 0;
	a = abs(a);
	while (a > 0) {
		k++;
		a /= 10;
	}
	return k;
}


int main() {
	int numberOfCoeff = 0;
	printf("enter the number of coefficients:\t");
	scanf("%d", &numberOfCoeff);
	int *coeff = new int[numberOfCoeff]; 
	int deg = numberOfCoeff - 1; 

	printf("If you want to enter the coefficients press 0. If you want to randomize them press 1\t");
	int answer = 0; 
	scanf("%d", &answer);
	if (answer) {
		srand((unsigned int)time(NULL));
		for (int i = deg; i > -1; i--)
			coeff[i] = rand() % 100 - 50;
	}
	else {
		for (int i = deg; i > -1; i--) {
			printf("coefficient ");
			printf("%d\t", i + 1);
			scanf("%d", &coeff[i]);
		}
	} 


	printf("polynomial:\n");
	int *numberOfSpaces = new int[numberOfCoeff];

	if (coeff[deg] > 0) {
		if (abs(coeff[deg]) != 1)
			numberOfSpaces[deg] = numberOfDigits(coeff[deg]) + 1;
		else numberOfSpaces[deg] =  1;
	}
	else {
		if (abs(coeff[deg]) != 1)
			numberOfSpaces[deg] = 2 + numberOfDigits(coeff[deg]) + 1;
		else numberOfSpaces[deg] = 3;
	}

	for (int i = deg - 1; i > 0; i--) {
		if (abs(coeff[i]) != 1) 
			numberOfSpaces[i] = 2 + numberOfDigits(coeff[i]) + 1;
		else numberOfSpaces[i] = 2 + 1;
	}

	for (int i = deg; i > 1; i--) {
		if (coeff[i] != 0) {
			for (int j = 0; j < numberOfSpaces[i]; j++) {
				printf(" ");
			}
			printf("%d", i);
		}
	}
	printf("\n");
	 

	if (coeff[deg] < 0) 
		printf("- ");
	if (abs(coeff[deg]) != 1) 
		printf("%d", abs(coeff[deg]));
	if (numberOfCoeff != 1)
		printf("x");

	int previous = deg;
	for (int i = deg - 1; i > -1; i--) {
		if (coeff[i] != 0) {
			for (int j = 0; j < numberOfDigits(previous); j++) 
				printf(" ");
			previous = i;
			if (coeff[i] < 0)
				printf("- ");
			else printf("+ ");
			if (abs(coeff[i]) != 1)
				printf("%d", abs(coeff[i]));
			if (i != 0)
				printf("x");
		}
	}

	scanf("%d", &numberOfCoeff);
	
	delete[] coeff;
	delete[] numberOfSpaces;
	return 0;
}