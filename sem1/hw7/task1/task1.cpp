#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include "Set.h"

int main() {
	int n = 0;
	Tree *set = createSet();
	for (int i = 0; i < 5; i++)
		addToSet(set, i);
	ascendingSetPrint(set);
	printf("\n");
	addToSet(set, 3);
	descendingSetPrint(set);
	printf("\n");
	printf("%d\n", existAtSet(set,2));
	deleteSetElement(set, 2);
	printf("%d\n", existAtSet(set, 2));
	printSet(set);
	scanf("%d", &n);
}