#define _CRT_SECURE_NO_WARNINGS
#include "set.h"


Set *createSet() {
	Set *set =createTree();
	return set;
}


void addSetElement(Set *set, ElementType x)
{
	addTreeNode(set, x);
}


bool existInSet(Set *set, ElementType x)
{
	return exist(set, x);
}


void deleteSetElement(Set *set, ElementType x)
{
	deleteTreeNode(set, x);
}


void deleteSet(Set *set)
{
	deleteTree(set);
}


void printSet(Set *set)
{
	printTree(set);
}


void ascendingSetPrint(Set *set)
{
	ascendingTreePrint(set);
}


void descendingSetPrint(Set *set)
{
	descendingTreePrint(set);
}