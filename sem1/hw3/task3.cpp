# define _CRT_SECURE_NO_WARNINGS
# include <cstdio>
#include <cmath>
using namespace std;

float powerOfNumber(int number, int power) {
	float result = 1;
	while (power > 0) {
		if (power % 2 == 1)
			result *= number;
		number *= number;
		power = power / 2;
	}
	return result;
}

int main() {
	int number = 0;
	int power = 0;
	printf("enter the number\t");
	scanf("%d", &number);
	printf("\n");
	printf("enter the power\t");
	scanf("%d", &power);
	printf("result:\t");

	if (number == 0 && power < 0)
		printf("error");
	else if (number > 0 && power < 0) {
		power = abs(power);
		printf("%f", 1 / powerOfNumber(number, power));
	}
	else {
		printf("%f", powerOfNumber(number, power));
	}
	scanf("%d", &number);
	return 0;
}