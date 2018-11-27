#define _CRT_SECURE_NO_WARNINGS
# include <cstdio>
# include <cmath>
using namespace std;

float pow(int baseNumber, int powerOfNumber) {
	float x = 1;
	if (powerOfNumber > 0 && baseNumber != 0) {
		while (powerOfNumber > 0) {
			x = x * baseNumber;
			powerOfNumber--;
		}
		return x;
	}
	else if (powerOfNumber < 0 && baseNumber != 0) {
		powerOfNumber = abs(powerOfNumber);
		while (powerOfNumber > 0) {
			x = x * baseNumber;
			powerOfNumber--;
		}
		return 1 / x;
	}
	else return 0;
}

float recPow(int baseNumber, int powerOfNumber) {
	float x = 1;
	if (powerOfNumber == 0)
		return 1;
	if (powerOfNumber > 0)
		return baseNumber * recPow(baseNumber, powerOfNumber - 1);
	if (powerOfNumber < 0) {
		powerOfNumber = abs(powerOfNumber);
		return 1 / (baseNumber * recPow(baseNumber, powerOfNumber - 1));
	}
	else return 0;
}


int main() {
	int baseNumber = 1;
	int  powerOfNumber = 1;
	printf("enter the base number and the power\n");
	scanf("%d%d", &baseNumber, &powerOfNumber);
	printf("result\t");

	if (powerOfNumber == 0 && baseNumber != 1)
		printf("1");
	else if (baseNumber == 0) {
		if (powerOfNumber == 0)
			printf("1");
		else if (powerOfNumber > 0)
			printf("0");
		else printf("error");
	}
	else {
		printf("%f", pow(baseNumber, powerOfNumber));
		printf("\t");
		printf("%f", recPow(baseNumber, powerOfNumber));
	}
	scanf("%d", &baseNumber);
	return 0;
}
