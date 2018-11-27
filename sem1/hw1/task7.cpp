#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
using namespace std;

bool isPrime(int number) {
	int k = 0;
	for (int i = 2; i < number + 1; i++) {
		if (number % i == 0)
			k++;
	}
	return (k == 1); 
}

int main() {
	int number = 0;
	printf("Enter the number\t");
	scanf("%d", &number);
	printf("All prime numbers before it:\n");
	for (int i = 2; i < number + 1; i++) {
		if (isPrime(i)) {
			printf("%d", i);
			printf("\n");
		}
	}
	scanf("%d", &number);
	return 0;
}