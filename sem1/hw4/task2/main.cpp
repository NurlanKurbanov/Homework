#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "phonebook.h"

int main() {
	const char path[] = "doc.txt";
	printf("0 - exit\n");
	printf("1 - add note\n");
	printf("2 - find a phone by name\n");
	printf("3 - find a name by phone\n");
	printf("4 - save current data to file\n");


	List *phonebook = fillThePhonebook(path);
	printf("Choose a number\t");
	int k = 0;
	scanf("%d", &k);

	while (k != 0) {

		switch (k) {
		case 1: {
			char name[maxSize];
			printf("enter the name:\t");
			scanf("%s", name);

			char number[maxSize];
			printf("enter the number:\t");
			scanf("%s", number);

			add(phonebook, name, number);
			break;
		}

		case 2: {
			char name[maxSize];
			printf("enter the name:\t");
			scanf("%s", name);

			char *number = findNumber(phonebook, name);
			if (number == nullptr)
				printf("Number has not found\n");
			else {
				for (unsigned int i = 0; i < strlen(number); i++)
					printf("%c", number[i]);
			}
			printf("\n");
			break;
		}

		case 3: {
			char number[maxSize];
			printf("enter the number:\t");
			scanf("%s", number);

			char *name = findName(phonebook, number);
			if (name == nullptr)
				printf("Name has not found\n");
			else {
				for (unsigned int i = 0; i < strlen(name); i++)
					printf("%c", name[i]);
			}
			printf("\n");
			break;
		}

		case 4: {
			savePhonebook(phonebook);
			printf("Changes saved\n");
			break;
		}

		default:
			printf("Error. You entered a wrong number\n");
		}

		printf("Choose a number\t");
		scanf("%d", &k);
	}

	deletePhonebook(phonebook);
	return 0;
}


