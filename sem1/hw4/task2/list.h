#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <fstream>
#include <string.h>
#include <cstring>
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
void add(List *list, char name[], char number[]);
void saveList(List *list);
void deleteList(List *list);
