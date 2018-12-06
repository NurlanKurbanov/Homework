#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list.h"

List *createList()
{
	return new List {nullptr};

}


int size(List *list)
{
	ListElement *current = list->first;
	int length = 0;
	while (current->next != list->first) {
		length++;
		current = current->next;
	}
	return length + 1;
}


void add(List *list, int x)
{
	ListElement *current = list->first;

	if (list->first == nullptr) {
		list->first = new ListElement{ x, nullptr};
		list->first->next = list->first;
		return;
	}
	if (current->number > x) {
		while (current->next != list->first)
			current = current->next;
		ListElement *newElement = new ListElement{ x, current->next };
		current->next = newElement;
		list->first = newElement;
		return;
	}
	while (current->next->number < x) {
		if (current->next == list->first) {
			ListElement *newElement = new ListElement{ x, current->next };
			current->next = newElement;
			return;
		}
		current = current->next;
	}
	ListElement *newElement = new ListElement { x, current->next};
	current->next = newElement;
}


void print(List *list)
{
	ListElement *current = list->first;
	while (current->next != list->first) {
		printf("%d\n", current->number);
		current = current->next;
	}
	printf("%d\n", current->number);
}

void deleteList(List *list) 
{
	ListElement *current = list->first;
	while (size(list) != 1) {
		ListElement *nextElement = current->next;
		delete current;
		current = nextElement;
		list->first = current;
	}
	delete list->first;
	delete list;
}

void killEach(int m, List *list)
{
	int i = 0;
	while (size(list) != 1) {
		ListElement *current = list->first;
		for (int i = 0; i < m - 2; i++)
			current = current->next;
		ListElement *temp = current->next;
		current->next = temp->next;
		delete temp;
		list->first = current->next;
	}
}
