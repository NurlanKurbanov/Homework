#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"

void spiralOutput(int **array, int lengthOfArray) {
	int a = lengthOfArray / 2;
	int b = lengthOfArray / 2;
	int step = 0;

	do {
		step++;
		for (int i = 0; i < step; i++)
			printf("%d ", array[a--][b]);
		if (step == lengthOfArray)
			break;
		for (int i = 0; i < step; i++)
			printf("%d ", array[a][b++]);
		step++;
		for (int i = 0; i < step; i++)
			printf("%d ", array[a++][b]);
		for (int i = 0; i < step; i++)
			printf("%d ", array[a][b--]);
	} while (step);

}