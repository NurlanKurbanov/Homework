#include "phonebook.h"


List *fillThePhonebook(const char *path) 
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


char *findNumber(List *list, char name1[]) 
{
	ListElement *current = list->first;
	while (strcmp(current->name, name1) != 0 && current->next) {
		current = current->next;
	}
	if (strcmp(current->name, name1) == 0)
		return current->number;
	else
		return nullptr;
}


char *findName(List *list, char number1[])
{
	ListElement *current = list->first;
	while (strcmp(current->number, number1) != 0 && current->next) {
		current = current->next;
	}
	if (strcmp(current->number, number1) == 0)
		return current->name;
	else
		return nullptr;
}

void savePhonebook(List *list)
{
	saveList(list);
}

void deletePhonebook(List *list)
{
	deleteList(list);
}
