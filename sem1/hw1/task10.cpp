#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
	const int length = 200;
	bool isPalindrom = true;
	char a[length] = "";
	printf("enter the string:\t");
	fgets(a, length, stdin);

	for (unsigned int i = 0; i < (strlen(a) - 1) / 2; i++) {
		if (a[i] != a[strlen(a) - 2 - i]) {
			printf("It's not a palindrom\n");
			isPalindrom = false;
			break;
		}
	}

	if (isPalindrom) {
		printf("It's a palindrom \n");
	}
	printf("\n");
	getchar();
	return 0;
}
