#pragma once
#include <cstdio>
using namespace std;

typedef int ElementType;

struct Node {
	ElementType value;
	Node *leftChild;
	Node *rightChild;
};


typedef Node Tree;

Tree *createTree();
Node *createNode(ElementType value);
void add(Tree *&tree, ElementType value);
ElementType deleteMin(Tree *&tree);
void deleteNode(Tree *&tree, ElementType value);
bool exist(Tree *&tree, ElementType value);
void ascendingTreePrint(Tree *tree);
void descendingTreePrint(Tree *tree);
void printTree(Tree *tree);
void deleteTree(Tree *&tree);