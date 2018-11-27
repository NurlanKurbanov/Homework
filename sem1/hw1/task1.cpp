#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	float x = 0;
	printf( "enter the x\n");
	scanf("%f", &x);
	float xSquared = x * x;
	printf("result ");
	printf("%f", (xSquared + 1) * (xSquared + x) + 1);
	printf("\n");
	scanf("%f", &x);
	return 0;
}

