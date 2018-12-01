#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;

const int maxSize = 50;

struct ListElement {
	char name[maxSize];
	char number[maxSize];
	ListElement *next;
};

struct List {
	ListElement *first;
};

List *createList();
List *fillTheList();
void add(List *list, char name1[], char number1[]);
char *findNumber(List *list, char name1[]);
char *findName(List *list, char number1[]);
void saveList(List *list);
void deleteList(List *list);
