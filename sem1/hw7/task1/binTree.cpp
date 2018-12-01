#include "binTree.h"

Tree *createTree()
{
	Tree *newTree = nullptr;
	return newTree;
}


Node *createNode(ElementType value)
{
	Node *newNode = new Node;
	newNode->value = value;
	newNode->leftChild = nullptr;
	newNode->rightChild = nullptr;
	return newNode;
}


void add(Tree *&tree, ElementType value)
{
	if (!tree) {
		tree = createNode(value);
		return;
	}
	if (tree->value == value)
		return;
	if (tree->value < value)
		add(tree->rightChild, value);
	else
		add(tree->leftChild, value);
}


ElementType deleteMin(Tree *&tree)
{
	if (!tree->leftChild) {
		int min = tree->value;
		tree = tree->rightChild;
		return min;
	}
	else return deleteMin(tree->leftChild);
}


void deleteNode(Tree *&tree, ElementType value)
{
	if (tree)
	{
		if (tree->value > value)
			deleteNode(tree->leftChild, value);
		else if (tree->value < value)
			deleteNode(tree->rightChild, value);
		else if (tree->leftChild == nullptr && tree->rightChild == nullptr) {
			delete tree;
			tree = nullptr;
		}
		else if (!tree->rightChild) {
			Tree *temp = tree;
			tree = tree->leftChild;
			delete temp;
		}
		else if (!tree->leftChild) {
			Tree *temp = tree;
			tree = tree->rightChild;
			delete temp;
		}
		else
			tree->value = deleteMin(tree->rightChild);
	}
	else printf("error");
}


bool exist(Tree *&tree, ElementType value)
{
	if (!tree)
		return false;
	if (tree->value == value)
		return true;
	if (tree->value < value)
		return exist(tree->rightChild, value);
	return exist(tree->leftChild, value);
}


void  ascendingTreePrint(Tree *tree) 
{
	if (!tree) {
		printf("error");
		return;
	}
	if (tree->leftChild)
		ascendingTreePrint(tree->leftChild);
	printf("%d ", tree->value);
	if (tree->rightChild)
		ascendingTreePrint(tree->rightChild);
}


void descendingTreePrint(Tree *tree)
{
	if (!tree) {
		printf("error");
		return;
	}
	if (tree->rightChild)
		descendingTreePrint(tree->rightChild);
	printf("%d ", tree->value);
	if (tree->leftChild)
		descendingTreePrint(tree->leftChild);
}


void printTree(Tree *tree)
{
	printf("( ");
	printf("%d", tree->value);
	if (tree->leftChild)
		printTree(tree->leftChild);
	else
		printf(" null ");
	if (tree->rightChild)
		printTree(tree->rightChild);
	else
		printf(" null ");
	printf(" )");
}


void deleteTree(Tree *&tree)
{
	if (!tree->rightChild && !tree->rightChild) {
		delete tree;
	}
	else if (!tree->leftChild) {
		Tree *temp = tree;
		tree = tree->rightChild;
		deleteTree(tree);
	}
	else if (!tree->rightChild) {
		tree = tree->leftChild;
		delete(tree);
	}
	else {
		delete(tree->leftChild);
		delete(tree->rightChild);
		delete(tree);
	}
}

