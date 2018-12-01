#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;

int numberOfMatchingElements(int arr1[], int arr2[], int length) {
	int k = 0;
	for (int i = 0; i < length; i++) {
		if (arr1[i] == arr2[i])
			k++;
	}
	return k;
}
int numberOfSameElements(int arr1[], int arr2[], int length) {
	int k = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (arr1[i] == arr2[j] && i != j)
				k++;
		}
	}
	return k;
}


int main() {
	int bulls = 0;
	int cows = 0;
	int length = 0;

	printf("Bulls and cows\n");
	printf("Enter number of digits (difficulty)\n");
	scanf("%d", &length);
	int *inputValues = new int[length];
	int *numbers = new int[length];


	srand((unsigned int)time(NULL));
	do {
		numbers[0] = rand() % 10;
	} while (numbers[0] == 0);

	bool usedNumbers[10] = { 0 };
	usedNumbers[numbers[0]] = 1;
	int k = 1;
	do {
		int y = rand() % 10;
		if (usedNumbers[y] == 0) {
			numbers[k] = y;
			usedNumbers[y] = 1;
			k++;
		}
	} while (k != length);

	for (int i = 0; i < length; i++)
		printf("%d", numbers[i]);



	while (bulls != length) {   
		int bulls = 0;
		int cows = 0;

		printf("\n");
		printf("enter numbers (non-repeatable): \n");
		for (int i = 0; i < length; i++) {
			scanf("%d", &inputValues[i]);
		}

		bulls = numberOfMatchingElements(numbers, inputValues, length);
		cows = numberOfSameElements(numbers, inputValues, length);

		printf("bulls:\t");
		printf("%d", bulls);
		printf("\n");
		printf("cows:\t");
		printf("%d", cows);
		if (bulls == length)
			break;
	}

	printf("\n");
	printf("YOU WIN\n");
	scanf("%d", &length);
	return 0;
}
