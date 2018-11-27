# include <cstdio>
# include <cmath>
using namespace std;

int main() {
	int devidend = 0;
	int devider = 0;
	int integerPart = 0;
	printf("enter a devided and a devider ");
	scanf_s("%d", &devidend);
	scanf_s("%d", &devider);
	if (devider == 0) {
		printf("error ");
	}
	else if (devider != 0) {
		while (devidend > devider) {
			devidend = devidend - devider;
			integerPart++;
		}
		printf("integer part  ");
		printf("%d", integerPart);
	}
	printf("\n");
	scanf_s("%d", &devidend);
	return 0;
}