#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;

void pushDown(int *numbers, int currentRoot, int currentLastElement) {
	bool itIsTheFirstRow = false;
	int maxChild = 0;

	while ((currentRoot * 2 <= currentLastElement) && (!itIsTheFirstRow)) {
		if ((currentRoot * 2 == currentLastElement) || (numbers[currentRoot * 2] > numbers[currentRoot * 2 + 1]))
			maxChild = currentRoot * 2;
		else 
			maxChild = currentRoot * 2 + 1;

		if (numbers[currentRoot] < numbers[maxChild]) {
			swap(numbers[currentRoot], numbers[maxChild]);
			currentRoot = maxChild;
		}
		else 
			itIsTheFirstRow = true;
	}
}
void pyramydalSort(int *numbers, int length) {
	for (int i = length / 2 - 1; i >= 0; i--)
		pushDown(numbers, i, length - 1);
	for (int i = length - 1; i >= 1; i--) {
		swap(numbers[0], numbers[i]);
		pushDown(numbers, 0, i - 1);
	}
};
	


int main() {
	int length = 0;
	printf("Enter the length\t");
	scanf("%d", &length);
	int *numbers = new int[length];

	printf("Numbers:\n");
	srand((unsigned int)time(NULL));
	for (int i = 0; i < length; i++) {
		numbers[i] = rand();
		printf("%d\t", numbers[i]);
	}
	printf("\n");

	pyramydalSort(numbers, length);
	printf("Sorted numbers: \n");
	for (int i = 0; i < length; i++) {
		printf("%d\t", numbers[i]);
	}

	scanf("%d", &length);
	delete[] numbers;
	return 0;
}