#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int expose(int *student, int i) {
	if (student[i] < 4)
		return student[i];
	return expose(student, student[i]);
}


int main() {
	int numberOfStudents = 0;
	printf("Enter the number of students\t");
	scanf("%d", &numberOfStudents);
	numberOfStudents++;

	int *student = new int[numberOfStudents];
	for (int i = 0; i < numberOfStudents; i++)
		student[i] = 0;
	for (int i = 1; i < 4; i++)
		student[i] = i;


	int indexOfStudent = -1;
	int fromWhomCopied = -1;
	printf("Enter the number of student and from whom copied (start from 4)\n");
	int k = 4;
	while (k <numberOfStudents) {
		scanf("%d %d", &indexOfStudent, &fromWhomCopied);
		student[indexOfStudent] = fromWhomCopied;
		k++;
	}

	for (int i = 1; i < numberOfStudents; i++)
		student[i] = expose(student,i);

	printf("Kick:\n");
	bool isSomeoneKicked = false;
	for (int i = 4; i < numberOfStudents; i++) {
		if (student[i] == -1) {
			printf("%d\n", i);
			isSomeoneKicked = true;
		}
	}
	if (!isSomeoneKicked)
		printf("no one\n");

	printf("Copied:\n");
	for (int i = 1; i < numberOfStudents; i++)
		if (student[i] > 0)
			printf("student %d copied from %d\n", i, student[i]);

	scanf("%d", &numberOfStudents);
	return 0;
}