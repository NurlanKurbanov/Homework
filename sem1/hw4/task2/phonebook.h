#pragma once
#include "list.h"

typedef List Phonebook;

Phonebook *fillThePhonebook(const char *path);
char *findNumber(Phonebook *phonebook, char name[]);
char *findName(Phonebook *phonebook, char number[]);
void savePhonebook(Phonebook *list);
void deletePhonebook(Phonebook *list);
