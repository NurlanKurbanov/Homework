#pragma once

struct ListElement {
	int number;
	ListElement *next;
};

struct List {
	ListElement *first;
};

List *createList();

void add(List *list, int number);
void print(List *list);
int size(List *list);
void deleteList(List *list);
void deleteElement(List *list, int number);
void shiftList(List *list);
void deleteListFirstElement(List *list);