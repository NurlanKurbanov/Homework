#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
using namespace std;


void sort(int *numbers, int leftElement, int rightElement)
{
	int firstNumber;
	int leftBorder = leftElement;
	int rightBorder = rightElement;
	firstNumber = numbers[leftElement];
	while (leftElement < rightElement)
	{
		while ((numbers[rightElement] >= firstNumber) && (leftElement < rightElement))
			rightElement--;
		if (leftElement != rightElement) {
			numbers[leftElement] = numbers[rightElement];
			leftElement++;
		}
		while ((numbers[leftElement] <= firstNumber) && (leftElement < rightElement))
			leftElement++;
		if (leftElement != rightElement) {
			numbers[rightElement] = numbers[leftElement];
			rightElement--;
		}
	}
	numbers[leftElement] = firstNumber;
	firstNumber = leftElement;
	leftElement = leftBorder;
	rightElement = rightBorder;
	if (leftElement < firstNumber)
		sort(numbers, leftElement, firstNumber - 1);
	if (rightElement > firstNumber)
		sort(numbers, firstNumber + 1, rightElement);
}


int main() {
	int length = 0;

	printf("enter the length\t");
	scanf("%d", &length);
	int *numbers = new int[length];

	printf("enter the numbers:\n");
	for (int i = 0; i < length; i++) {
		scanf("%d", &numbers[i]);
	}
	
	sort(numbers, 0, length-1);

	printf("Highest number occurring more than once:\t");
	for (int i = length - 1; i > -1; i--) {
		if (numbers[i - 1] == numbers[i]) {
			printf("%d\n", numbers[i]);
			break;
		}
	}
	scanf("%d", &length);
	return 0;
}