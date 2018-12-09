#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list.h"
using namespace std;

int main()
{
	int n = 0;
	printf("Enter the number of warriors:\t");
	scanf("%d", &n);
	int m = 0;
	printf("Enter the kill-step:\t");
	scanf("%d", &m);

	List *army = createList();
	for (int i = 0; i < n; i++)
		add(army, i);
	print(army);

	ListElement *current = returnListFirstElement(army);
	int temp = 0;

	int step = 1;
	while (true) {
		if (size(army) == 1)
			break;
		if (step == m) {
			temp = returnElementNumber(current);
			current = nextElement(current);
			deleteElement(army, temp);
			step = 1;
		}
		else {
			current = nextElement(current);
			step++;
		}
	}

	printf("Survived:\t");
	print(army);


	deleteList(army);
	scanf("%d", &n);
	return 0;
}
