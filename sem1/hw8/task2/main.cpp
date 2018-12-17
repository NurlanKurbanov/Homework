#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "string.h"

int main() {
	char a[] = "dgg";
	char b[] = "sg dg";
	String *s1 = createNewString(a);
	addToString(s1, b);
	cout << s1->string << endl;
	String *s2 = clone(s1);
	compare(s1, s2);
	printf("\n");
	cout << s2->string << endl;
	printf("%d\n", length(s2));
	printf("%d\n", isEmpty(s2));
	deleteString(s2);
	char *c = selectSubstring(s1, 2, 4);
	cout << c << endl;
	scanf("%c", &a[1]);
	return 0;
}