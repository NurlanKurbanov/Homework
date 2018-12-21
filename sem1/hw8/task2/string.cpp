#define _CRT_SECURE_NO_WARNINGS
#include "string.h"

String *createString()
{
	/*String *string = new String;
	string->string = nullptr;
	string->length = 0;*/
	return new String{ nullptr, 0 };
}


int length(String *string)
{
	return string->length;
}


String *createNewString(char *line)
{
	String *string = createString();
	addToString(string, line);
	return string;
}


void addToString(String *string, char *line)
{
	int lengthOfLine = strlen(line);

	if (string->string == nullptr) {
		char *newString = new char[lengthOfLine + 1];
		for (int i = 0; i < lengthOfLine + 1; i++)
			newString[i] = line[i];
		if (newString[lengthOfLine - 1] == '\n')
			newString[lengthOfLine - 1] = '\0';
		string->string = newString;
		string->length = strlen(string->string);
	}
	else {
		char *newString = new char[string->length + lengthOfLine + 1];
		int i = 0;
		while (i < string->length) {
			newString[i] = string->string[i];
			i++;
		}
		int k = 0;
		while (i < string->length + lengthOfLine + 1) {
			newString[i] = line[k];
			i++;
			k++;
		}
		if (newString[string->length + lengthOfLine - 1] == '\n')
			newString[string->length + lengthOfLine - 1] = '\0';
		char *temp = string->string;
		string->string = newString;
		string->length = strlen(string->string);
		delete[] temp;
	}
}


bool isEmpty(String *string)
{
	return (string->string == nullptr);
}


void deleteString(String *string)
{
	if (!isEmpty(string))
		delete[] string->string;
	delete[] string;
}


String *clone(String *string)
{
	String *line = createNewString(string->string);
	return line;
}


void compare(String *string, String *line)
{
	char *s = stringToChar(string);
	char *l = stringToChar(line);
	if (strcmp(s, l) == 0) {
		printf("Are equal");
		return;
	}
	if (strlen(s) > strlen(l)) {
		printf("The first string is longer");
		return;
	}
	else printf("The second string is longer");
}


char *selectSubstring(String *string, int beginning, int end)
{
	char *selectedSubstring = new char[end - beginning + 2];
	int k = 0;
	for (int i = beginning; i <= end; i++) {
		selectedSubstring[k] = string->string[i];
		k++;
	}
	selectedSubstring[k] = '\0';
	return selectedSubstring;
}


char *stringToChar(String *string)
{
	int lengthOfLine = string->length + 1;
	char *newString = new char[lengthOfLine];
	for (int i = 0; i < lengthOfLine; i++)
		newString[i] = string->string[i];
	return newString;
}