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
	killEach(m, army);
	print(army);


	deleteList(army);
	scanf("%d", &n);
	return 0;
}
