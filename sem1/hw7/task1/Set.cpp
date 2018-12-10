#define _CRT_SECURE_NO_WARNINGS
#include "set.h"

Set *createSet()
{
	Set *newSet = new Set;
	newSet->root = nullptr;
	return newSet;
}


void addLeaf(SetNode *&currentSetNode, ElementType x)
{
	SetNode *newSetNode = new SetNode;
	newSetNode->lowerElement = nullptr;
	newSetNode->greaterElement = nullptr;
	newSetNode->value = x;
	currentSetNode = newSetNode;
}


void addToSet(SetNode *currentSetNode, ElementType x)
{
	if (x == currentSetNode->value)
		return;
	if (x < currentSetNode->value) {
		if (currentSetNode->greaterElement != nullptr)
			return addToSet(currentSetNode->greaterElement, x);
		else {
			addLeaf(currentSetNode->greaterElement, x);
			return;
		}
	}
	else {
		if (currentSetNode->greaterElement != nullptr)
			return addToSet(currentSetNode->greaterElement, x);
		else {
			addLeaf(currentSetNode->greaterElement, x);
			return;
		}
	}
}


void addToSet(Set *set, ElementType x)
{
	if (set->root == nullptr) {
		addLeaf(set->root, x);
		return;
	}
	return addToSet(set->root, x);
}


bool exist(SetNode *currentSetNode, ElementType x)
{
	if (currentSetNode == nullptr)
		return false;
	if (x == currentSetNode->value)
		return true;
	if (x < currentSetNode->value)
		return exist(currentSetNode->lowerElement, x);
	else
		return exist(currentSetNode->greaterElement, x);
}


bool exist(Set *set, ElementType x)
{
	return exist(set->root, x);
}


ElementType deleteMin(SetNode *&currentSetNode)
{
	if (!currentSetNode->lowerElement) {
		ElementType min = currentSetNode->value;
		currentSetNode = currentSetNode->greaterElement;
		return min;
	}
	else return deleteMin(currentSetNode->lowerElement);
}


void deleteFromSet(SetNode *&currentSetNode, ElementType x) {
	if (currentSetNode->value > x)
		deleteFromSet(currentSetNode->lowerElement, x);
	else if (currentSetNode->value < x)
		deleteFromSet(currentSetNode->greaterElement, x);
	else if (currentSetNode->lowerElement == nullptr && currentSetNode->greaterElement == nullptr) {
		delete currentSetNode;
		currentSetNode = nullptr;
	}
	else if (!currentSetNode->greaterElement) {
		SetNode *temp = currentSetNode;
		currentSetNode = currentSetNode->lowerElement;
		delete temp;
	}
	else if (!currentSetNode->lowerElement) {
		SetNode *temp = currentSetNode;
		currentSetNode = currentSetNode->greaterElement;
		delete temp;
	}
	else currentSetNode->value = deleteMin(currentSetNode->greaterElement);
}


void deleteFromSet(Set *set, ElementType x)
{
	if (!set->root) {
		printf("error/tree is empty");
		return;
	}
	return deleteFromSet(set->root, x);
}


void deleteSet(SetNode *currentSetNode)
{
	if (currentSetNode == nullptr)
		return;
	deleteSet(currentSetNode->lowerElement);
	deleteSet(currentSetNode->greaterElement);
	delete currentSetNode;
}


void deleteSet(Set *set)
{
	deleteSet(set->root);
	delete set;
}


void printSet(SetNode *currentSetNode)
{
	printf("(");
	printf("%d ", currentSetNode->value);
	if (currentSetNode->lowerElement)
		printSet(currentSetNode->lowerElement);
	else
		printf("null ");
	if (currentSetNode->greaterElement)
		printSet(currentSetNode->greaterElement);
	else
		printf("null ");
	printf(")");
}


void printSet(Set *set)
{
	if (set->root == nullptr) {
		printf("Set is empty\n");
		return;
	}
	printSet(set->root);
	printf("\n");
}


void ascendingSetPrint(SetNode *currentSetNode)
{
	if (currentSetNode == nullptr)
		return;
	ascendingSetPrint(currentSetNode->lowerElement);
	printf("%d ", currentSetNode->value);
	ascendingSetPrint(currentSetNode->greaterElement);
}


void ascendingSetPrint(Set *set)
{
	if (set->root == nullptr) {
		printf("Set is empty\n");
		return;
	}
	ascendingSetPrint(set->root);
	printf("\n");
}


void descendingSetPrint(SetNode *currentSetNode)
{
	if (currentSetNode == nullptr)
		return;
	descendingSetPrint(currentSetNode->greaterElement);
	printf("%d ", currentSetNode->value);
	descendingSetPrint(currentSetNode->lowerElement);
}


void descendingSetPrint(Set *set)
{
	if (set->root == nullptr) {
		printf("Set is empty\n");
		return;
	}
	descendingSetPrint(set->root);
	printf("\n");
}
