#pragma once
#include "binTree.h"

typedef int ElementType;

 Tree *createSet();
 void addToSet(Tree *&set, ElementType value);
 void deleteSetElement(Tree *&set, ElementType value);
 bool existAtSet(Tree *set, ElementType value);
 void ascendingSetPrint(Tree *set);
 void descendingSetPrint(Tree *set);
 void printSet(Tree *set);
 void deleteSet(Tree *&set);