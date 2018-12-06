#include "list.h"

List *createList()
{
	return new List{ nullptr };
}


void add(List *list, char name1[], char number1[])
{
	ListElement *current = new ListElement;

	strcpy(current->name,name1);
	strcpy(current->number, number1);
	current->next = list->first;
	list->first = current;
}


void saveList(List *list) 
{
	ofstream fout("doc.txt");

	ListElement *current = list->first;
	while (current) {
		fout << current->name << "	" << current->number << endl;
		current = current->next;
	}
	fout.close();
}


void deleteList(List *list)
{
	ListElement *current = list->first;
	while (current) {
		ListElement *next = current->next;
		delete current;
		current = next;
	}
	delete list;
}
