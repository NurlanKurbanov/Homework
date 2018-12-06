#pragma once
#include "list.h"

List *fillThePhonebook(const char *path);
char *findNumber(List *list, char name1[]);
char *findName(List *list, char number1[]);
void savePhonebook(List *list);
void deletePhonebook(List *list);
