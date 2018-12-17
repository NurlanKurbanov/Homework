#pragma once
#include <cstdio>
#include <string.h>
#include <iostream> //только для проверки 
using namespace std;

struct String {
	char *string;
	int length;
};

String *createString();
String *createNewString(char *line);
void addToString(String *string, char *line);
void deleteString(String *string);
String *clone(String *string);
void compare(String *string, String *line);
int length(String *string);
bool isEmpty(String *string);
char *selectSubstring(String *string, int beginning, int end);
char *stringToChar(String *string);