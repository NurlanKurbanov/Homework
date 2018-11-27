#define _CRT_SECURE_NO_WARNINGS
# include <cstdio>
# include <cmath>
#include <cstring>
#define size 50
using namespace std;

int main() {
	int balance = 0;
	char str[size] = "";
	fgets(str, size, fp);
	for (unsigned int i = 0; i < strlen(str); i++) {
		if (str[i] == ')') {
			balance++;
		}
		if (str[i] == '(') {
			balance--;
		}
	}
	printf("%d", balance);
	printf("\n");
	scanf("%d", &balance);
	return 0;
}
