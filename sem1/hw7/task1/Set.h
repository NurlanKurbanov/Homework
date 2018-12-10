#pragma once
#include <cstdio>
using namespace std;

typedef int ElementType;

struct SetNode
{
	int value;
	SetNode *lowerElement; 
	SetNode *greaterElement;
};

struct Set
{
	SetNode *root;
};


Set *createSet();
void addToSet(Set *set, ElementType x);
bool exist(Set *set, ElementType x);
void deleteFromSet(Set *set, ElementType x);
void printSet(Set *set);
void ascendingSetPrint(Set *set);
void descendingSetPrint(Set *set);
void deleteSet(Set *set);