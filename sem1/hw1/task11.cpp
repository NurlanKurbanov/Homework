#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <ctime>
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
	printf(" Enter the length\t ");
	scanf("%d", &length);
	int *a = new int[length];

	srand((unsigned int)time(NULL));
	for (int i = 0; i < length; i++) {
		a[i] = rand();
	}
	for (int i = 0; i < length; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("Sorted numbers: \n");
	sort(a, 0, length-1); 

	for (int i = 0; i < length; i++)
		printf("%d ", a[i]);
	printf("\n");
	scanf("%d", &a[1]);

	delete[] a;
	return 0;
}