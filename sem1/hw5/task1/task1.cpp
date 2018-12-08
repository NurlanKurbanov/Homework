#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"
using namespace std;

int main() {
	int lengthOfArray = 0;
	printf("Enter the length of array\t");
	scanf("%d", &lengthOfArray);

	int **array = new int*[lengthOfArray];
	for (int i = 0; i < lengthOfArray; i++) {
		array[i] = new int[lengthOfArray];
	}
	srand((int)time(NULL));
	for (int i = 0; i < lengthOfArray; i++) {
		for (int j = 0; j < lengthOfArray; j++)
			array[i][j] = rand() % 50;  /*просто для удобства*/
	}

	printf("array:\n");
	for (int i = 0; i < lengthOfArray; i++) {
		for (int j = 0; j < lengthOfArray; j++) {
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	spiralOutput(array, lengthOfArray);

	scanf("%d", &lengthOfArray);

	for (int i = 0; i < lengthOfArray; i++)
		delete[] array[i];
	delete[] array;
	return 0;
}

