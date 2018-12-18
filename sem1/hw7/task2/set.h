#pragma once
#include "avlTree.h"

typedef Tree Set;


Set *createSet();
void addSetElement(Set *set, ElementType x);
bool existInSet(Set *set, ElementType x);
void deleteSetElement(Set *set, ElementType x);
void deleteSet(Set *set);
void printSet(Set *set);
void ascendingSetPrint(Set *set);
void descendingSetPrint(Set *set);
