#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
using namespace std;

void decomposition(int *a, int x, int y, int i)
{
	if (x < 0) return;
	if (x == 0) {

		int j;
		for (j = 0; j < i; j++) {
			printf("%d ", a[j]);
		}
		printf("\n");
	}
	else {
		if (x - y >= 0) {
			a[i] = y;
			decomposition( a, x - y, y, i + 1);
		}
		if (y - 1 > 0) {
			decomposition( a, x, y - 1, i);
		}
	}
	return;
}
int main() {
	const int size = 20;
	int number = 0;
	scanf("%d", &number);

	int numberOfUnits[size];
	for (int i = 0; i <= number; i++) {
		numberOfUnits[i] = 0;
	}
	decomposition(numberOfUnits, number, number, 0);
	scanf("%d", &number);
	return 0;
}