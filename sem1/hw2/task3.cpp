#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

void qsort(int *numbers, int leftElement, int rightElement)
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
		qsort(numbers, leftElement, firstNumber - 1);
	if (rightElement > firstNumber)
		qsort(numbers, firstNumber + 1, rightElement);
}

int gcd(int a, int b) {
	while (a != b) {
		if (a > b)
			a = a - b;
		else b = b - a;
	}
	return a;
}

int main() {
	const int size = 20;
	int numerator[size];
	int denominator[size];
	int n = 0;
	int k = 0;

	printf("enter the denominator :\n");
	scanf_s("%d", &n);
	printf("simple fractions:\n");
	for (int i = 2; i < n + 1; i++) {
		for (int j = 1; j < i; j++) {
			if (gcd(j, i) == 1) {
				numerator[k] = j;
				denominator[k] = i;
				k++;
			}
		}
	}
	

	int commonDenominator = 1;
	for (int i = 0; i < k; i++)
		commonDenominator *= denominator[i];

	for (int i = 0; i < k; i++) {
		numerator[i] = (commonDenominator / denominator[i]) * numerator[i];
	}
	
	qsort(numerator, 0, k - 1);

	for (int i = 0; i < k; i++) {
		printf("%d", numerator[i] / (gcd(numerator[i], commonDenominator)));
		printf("/");
		printf("%d", commonDenominator / (gcd(numerator[i], commonDenominator)));
		printf("\n");
	}
	scanf_s("%d", &k);
	return 0;
}