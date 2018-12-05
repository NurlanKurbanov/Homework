#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	double x = 0;
	printf("Enter the number:\t");
	scanf("%lf", &x);

	unsigned char * b = (unsigned char*)&x;
	int sign = (unsigned)b[7] / 128;
	if (sign)
		printf("-");
	else printf("+");

	int exp = ((unsigned)b[7] % 128) * 16 + ((unsigned)b[6] / 16) - 1023;
	double mantissa = 1;
	long long q = 2;
	for (int i = 8; i > 0; i /= 2) {
		mantissa += (double)(((unsigned)b[6] / i) % 2) / q;
		q *= 2;
	}

	for (int i = 5; i > -1; i--) {
		for (int j = 128; j > 0; j /= 2) {
			mantissa += (double)(((unsigned)b[i] / j) % 2) / q;
			q *= 2;
		}
	}

	printf("%0.52g", mantissa);
	printf("*2^");
	printf("%d", exp);

	scanf("%lf", &x);
	return 0;
}