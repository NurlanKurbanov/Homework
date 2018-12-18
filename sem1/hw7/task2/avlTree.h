#pragma once
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

typedef int ElementType;

struct TreeNode
{
	ElementType value;
	int height;
	TreeNode *leftChild;
	TreeNode *rightChild;
};


struct Tree
{
	TreeNode *root;
};


Tree *createTree();
void addTreeNode(Tree *tree, ElementType x);
bool exist(Tree *tree, ElementType x);
void deleteTreeNode(Tree *tree, ElementType x);
void deleteTree(Tree *tree);
void printTree(Tree *tree);
void ascendingTreePrint(Tree *tree);
void descendingTreePrint(Tree *tree);

void updateHeight(TreeNode *currentNode);
int balanceFactor(TreeNode *rootNode);
void balance(TreeNode *&rootNode);
void smallLeftRotate(TreeNode *&rootNode);
void smallRightRotate(TreeNode *&rootNode);
void bigLeftRotate(TreeNode *&rootNode);
void bigRightRotate(TreeNode *&rootNode);