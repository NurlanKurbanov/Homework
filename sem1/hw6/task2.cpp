#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

void invert(bool *a) {
	for (int i = 31; i > -1; i--) {
		if (a[i] == 0)
			a[i] = 1;
		else a[i] = 0;
	}
}

int convertBinaryToDecimal(bool *binary) {
	if (binary[0] == 1)
		printf("-");

	int number = 0;
	for (int i = 1; i < 32; i++) {
		number += binary[i] * pow(2, 31 - i);
	}
	return number;
}

void convertDecimalToBinary(int a, bool *binary) {
	for (int i = 0; i < 32; i++)
		binary[i] = 0;
	if (a >= 0)
		binary[0] = 0;
	else binary[0] = 1;

	for (int i = 31; i > 0; i--) {
		binary[i] = a % 2;
		if (a == 0)
			break;
		a = a / 2;
	}
}


void sum(bool *a, bool *b, bool *sum1) {
	for (int i = 0; i < 32; i++)
		sum1[i] = 0;

	bool areInverse = true;
	for (int i = 31; i > -1; i--) {
		if (a[i] == b[i])
			areInverse = false;
	}
	if (areInverse) {
		for (int i = 0; i < 32; i++)
			sum1[i] = 0;
		return;
	}

	bool digitPlaceIsOverfilled = false;
	for (int i = 31; i > -1; i--) {
		if (a[i] == 0 && b[i] == 0) {
			if (digitPlaceIsOverfilled == false)
				sum1[i] = 0;
			else {
				sum1[i] = 1;
				digitPlaceIsOverfilled = false;
			}
		}
		if ((a[i] == 1 && b[i] == 0) || (b[i] == 1 && a[i] == 0)) {
			if (digitPlaceIsOverfilled == false)
				sum1[i] = 1;
			else sum1[i] = 0;
		}
		if (a[i] == 1 && b[i] == 1) {
			if (digitPlaceIsOverfilled == false) {
				sum1[i] = 0;
				digitPlaceIsOverfilled = true;
			}
			else sum1[i] = 1;
		}
	}

	if (digitPlaceIsOverfilled == true) {
		bool unitInBinary[32];
		bool sum2[32];
		for (int i = 31; i > -1; i--) {
			unitInBinary[i] = 0;
			sum2[i] = 0;
		}
		unitInBinary[31] = 1;
		sum(sum1, unitInBinary, sum2);
		for (int i = 31; i > -1; i--)
			sum1[i] = sum2[i];
	}
}



int main() {
	bool number1[32];
	int num1 = 0;
	bool number2[32];
	int num2 = 0;

	printf("enter the numbers:\t");
	scanf("%d%d", &num1, &num2);
	convertDecimalToBinary(num1, number1);
	convertDecimalToBinary(num2, number2);

	printf("binary num1:\n");
	for (int i = 0; i < 32; i++)
		printf("%d", number1[i]);
	printf("\n");
	printf("binary num2:\n");
	for (int i = 0; i < 32; i++)
		printf("%d", number2[i]);
	printf("\n");

	if (number1[0] == 1) {
		invert(number1);
		number1[0] = 1;
	}

	if (number2[0] == 1) {
		invert(number2);
		number2[0] = 1;
	}

	bool sumArray[32];
	sum(number1, number2, sumArray);

	if (sumArray[0] == 1) {
		invert(sumArray);
		sumArray[0] = 1;
		}

	printf("BinarySum:\n");
	for (int i = 0; i < 32; i++)
		printf("%d", sumArray[i]);
	printf("\n");

	printf("sum:\n");
	printf("%d", convertBinaryToDecimal(sumArray));

	scanf("%d", &num1);
	return 0;
}