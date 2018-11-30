#include <cstdio>
#include <cmath>
#include <algorithm>
#define size 50
using namespace std;

int numberOfDigits(int a) {
	int i = 0;
	while (a > 0) {
		a = a / 10;
		i++;
	}
	return i;
}

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
	int n = 0;
	int k = 0;
	printf("enter the number\n");
	scanf_s("%d", &n);
	int number[size];
	k = numberOfDigits(n);
	for (int i = 0; i < k; i++) {
		number[i] = n % 10;
		n = n / 10;
	}
	sort(number, 0, k - 1);
	if (number[0] == 0) {
		for (int i = 1; i < k; i++) {
			if (number[i] != 0) {
				swap(number[0], number[i]);
				break;
			}
		}
	}
	printf("\n");
	printf("The smallest number is:\n");
	for (int i = 0; i < k; i++)
		printf("%d", number[i]);
	printf("\n");
	scanf_s("%d", &n);
	return 0;
}