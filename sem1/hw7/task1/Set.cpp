#include "set.h"

Tree *createSet()
{
	Tree *newSet = createTree();
	return newSet;
}


void addToSet(Tree *&set, ElementType value)
{
	add(set, value);
}


void deleteSetElement(Tree *&set, ElementType value)
{
	deleteNode(set, value);
}


bool existAtSet(Tree *set, ElementType value)
{
	return exist(set, value);
}


void ascendingSetPrint(Tree *set)
{
	ascendingTreePrint(set);
}


void descendingSetPrint(Tree *set)
{
	descendingTreePrint(set);
}


void printSet(Tree *set)
{
	printTree(set);
}


void deleteSet(Tree *&set)
{
	deleteTree(set);
}