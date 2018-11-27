#include <cstdio>
#include <cmath>
using namespace std;

int fib(int number) {
	int sum = 0;
	int sum1 = 0;
	int sum2 = 1;
	if (number == 0)
		sum = sum1;
	else if (number == 1)
		sum = sum2;
	else for (int i = 2; i < number + 1; i++) {
		sum = sum1 + sum2;
		sum1 = sum2;
		sum2 = sum;
	}
	return sum;
}

int recFib(int number) {
	if (number == 0)
		return 0;
	else if (number == 1)
		return 1;
	else return  recFib(number - 1) + recFib(number - 2);
}

int main() {
	int number = 0;
	
	printf("enter the n-th number\n");
	scanf_s("%d", &number);
	if (number < 0)
		printf("error");
	else {
		fib(number);
		printf("value\n");
		printf("%d\t", fib(number));
		printf("%d\n", recFib(number));
	}
	scanf_s("%d", &number);
	return 0;
}