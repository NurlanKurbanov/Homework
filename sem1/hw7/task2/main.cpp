#define _CRT_SECURE_NO_WARNINGS
#include "set.h"

int main() {
	printf("1 - add new element to set\n");
	printf("2 - delete element from set\n");
	printf("3 - check if element belongs to set\n");
	printf("4 - print the set in increasing order\n");
	printf("5 - print the set in decreasing order\n");
	printf("6 - print the set\n");
	printf("0 - exit\n");

	int option = 0;
	scanf("%d", &option);
	Set *set = createSet();

	int element = 0;

	while (option != 0) {
		switch (option) {
		case 1: {
			printf("Enter the element\n");
			scanf("%d", &element);
			addSetElement(set, element);
			break;
		}
		case 2: {
			printf("Enter the element\n");
			scanf("%d", &element);
			deleteSetElement(set, element);
			break;
		}
		case 3: {
			printf("Enter the element\n");
			scanf("%d", &element);
			if (exist(set, element))
				printf("Belongs\n");
			else
				printf("Not belongs\n");
			break;
		}
		case 4: {
			ascendingSetPrint(set);
			break;
		}
		case 5: {
			descendingSetPrint(set);
			break;
		}
		case 6: {
			printSet(set);
			break;
		}
		default: {
			printf("Error. You entered a wrong number\n");
			break;
		}
		}
		printf("Choose a number\n");
		scanf("%d", &option);
	}

	deleteSet(set);
	return 0;
}