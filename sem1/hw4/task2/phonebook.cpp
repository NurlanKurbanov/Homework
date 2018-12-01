#include "phonebook.h"

List *createList() {
	return new List{ nullptr };
}


List *fillTheList() {
	ifstream fin("doc.txt");
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

void add(List *list, char name1[], char number1[]) {
	ListElement *current = new ListElement;

	for (unsigned int i = 0; i <= strlen(name1); i++)
		current->name[i] = name1[i];
	for (unsigned int i = 0; i <= strlen(number1); i++)
		current->number[i] = number1[i];

	current->next = list->first;
	list->first = current;
}

char *findNumber(List *list, char name1[]) {
	ListElement *current = list->first;
	while (strcmp(current->name, name1) != 0 && current->next) {
		current = current->next;
	}
	if (strcmp(current->name, name1) == 0)
		return current->number;
	else
		return nullptr;
}

char *findName(List *list, char number1[]) {
	ListElement *current = list->first;
	while (strcmp(current->number, number1) != 0 && current->next) {
		current = current->next;
	}
	if (strcmp(current->number, number1) == 0)
		return current->name;
	else
		return nullptr;
}

void saveList(List *list) {
	ofstream fout("doc.txt");

	ListElement *current = list->first;
	while (current) {
		fout << current->name << "	" << current->number << endl;
		current = current->next;
	}
	fout.close();
}

void deleteList(List *list) {
	ListElement *current = list->first;
	while (current) {
		ListElement *next = current->next;
		delete current;
		current = next;
	}
	delete list;
}
