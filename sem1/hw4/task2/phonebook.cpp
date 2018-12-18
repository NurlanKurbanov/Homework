#include "phonebook.h"


Phonebook *fillThePhonebook(const char *path) 
{
	ifstream fin(path);
	List *phonebook = createList();

	while (!fin.eof()) {
		char name[maxSize];
		char number[maxSize];
		fin >> name >> number;
		add(phonebook, name, number);
	}

	fin.close();
	return phonebook;
}


char *findNumber(Phonebook *phonebook, char name[])
{
	ListElement *current = phonebook->first;
	while (strcmp(current->name, name) != 0 && current->next) {
		current = current->next;
	}
	if (strcmp(current->name, name) == 0)
		return current->number;
	else
		return nullptr;
}


char *findName(Phonebook *phonebook, char number[])
{
	ListElement *current = phonebook->first;
	while (strcmp(current->number, number) != 0 && current->next) {
		current = current->next;
	}
	if (strcmp(current->number, number) == 0)
		return current->name;
	else
		return nullptr;
}

void savePhonebook(Phonebook *list)
{
	saveList(list);
}

void deletePhonebook(Phonebook *list)
{
	deleteList(list);
}
