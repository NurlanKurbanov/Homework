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

	printf("Survived:\t");
	int i = 0;
	while (size(army) != 1) {
		ListElement *current = army->first;
		for (int i = 0; i < m - 2; i++)
			current = current->next;
		ListElement *temp = current->next;
		current->next = temp->next;
		delete temp;
		army->first = current->next;
	}

	print(army);

	scanf("%d", &n);
	return 0;
}
