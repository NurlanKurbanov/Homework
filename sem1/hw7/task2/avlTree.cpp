#define _CRT_SECURE_NO_WARNINGS
#include "avlTree.h"

Tree *createTree()
{
	Tree *newTree = new Tree;
	newTree->root = nullptr;
	return newTree;
}


void addTreeLeaf(TreeNode* &currentTreeNode, ElementType x)
{
	TreeNode *newTreeNode = new TreeNode;
	newTreeNode->leftChild = nullptr;
	newTreeNode->rightChild = nullptr;
	newTreeNode->value = x;
	newTreeNode->height = 1;
	currentTreeNode = newTreeNode;
}


void addTreeNode(TreeNode *&currentTreeNode, ElementType x)
{
	if (x == currentTreeNode->value)
		return;
	if (x < currentTreeNode->value) {
		if (currentTreeNode->leftChild != nullptr) {
			addTreeNode(currentTreeNode->leftChild, x);
			updateHeight(currentTreeNode);
			balance(currentTreeNode);
			updateHeight(currentTreeNode);
		}
		else {
			addTreeLeaf(currentTreeNode->leftChild, x);
			if (currentTreeNode->height == 1)
				currentTreeNode->height = 2;
		}
	}
	else {
		if (currentTreeNode->rightChild != nullptr) {
			addTreeNode(currentTreeNode->rightChild, x);
			updateHeight(currentTreeNode);
			balance(currentTreeNode);
			updateHeight(currentTreeNode);
		}
		else {
			addTreeLeaf(currentTreeNode->rightChild, x);
			if (currentTreeNode->height == 1)
				currentTreeNode->height = 2;
		}
	}
}


void addTreeNode(Tree *tree, ElementType x)
{
	if (tree->root == nullptr) {
		addTreeLeaf(tree->root, x);
		return;
	}
	addTreeNode(tree->root, x);
	return;
}


bool exist(TreeNode *currentTreeNode, ElementType x)
{
	if (!currentTreeNode)
		return false;
	if (x == currentTreeNode->value)
		return true;
	if (x < currentTreeNode->value)
		return exist(currentTreeNode->leftChild, x);
	else
		return exist(currentTreeNode->rightChild, x);
}


bool exist(Tree *tree, ElementType x)
{
	return exist(tree->root, x);
}


TreeNode **deleteMin(TreeNode *&currentTreeNode)
{
	if (currentTreeNode->leftChild == nullptr)
		return &currentTreeNode;
	return deleteMin(currentTreeNode->leftChild);
}


void deleteTreeNode(TreeNode *&currentTreeNode, ElementType x)
{
	if (currentTreeNode->value > x) {
		deleteTreeNode(currentTreeNode->leftChild, x);
		updateHeight(currentTreeNode);
		balance(currentTreeNode);
		updateHeight(currentTreeNode);
		return;
	}
	if (currentTreeNode->value < x) {
		deleteTreeNode(currentTreeNode->rightChild, x);
		updateHeight(currentTreeNode);
		balance(currentTreeNode);
		updateHeight(currentTreeNode);
		return;
	}
	if (currentTreeNode->leftChild == nullptr && currentTreeNode->rightChild == nullptr) {
		delete currentTreeNode;
		currentTreeNode = nullptr;
	}
	else if ((currentTreeNode->leftChild != nullptr && currentTreeNode->rightChild == nullptr) || (currentTreeNode->leftChild == nullptr && currentTreeNode->rightChild != nullptr)){
		if (currentTreeNode->leftChild != nullptr) {
			TreeNode *temp = currentTreeNode->leftChild;
			delete currentTreeNode;
			currentTreeNode = temp;
		}
		else {
			TreeNode *temp = currentTreeNode->rightChild;
			delete currentTreeNode;
			currentTreeNode = temp;
		}
	}
	else {
		TreeNode **temp = deleteMin(currentTreeNode->rightChild);
		currentTreeNode->value = (*temp)->value;
		deleteTreeNode(*temp, (*temp)->value);
	}
}


void deleteTreeNode(Tree *tree, ElementType x)
{
	if (!tree->root) {
		printf("Error. Tree is empty\n");
		return;
	}
	if (!exist(tree, x)) {
		printf("Error. There is no such element\n");
		return;
	}
	return deleteTreeNode(tree->root, x);
}


void deleteTree(TreeNode *currentTreeNode)
{
	if (currentTreeNode == nullptr)
		return;
	deleteTree(currentTreeNode->leftChild);
	deleteTree(currentTreeNode->rightChild);
	delete currentTreeNode;
}


void deleteTree(Tree *tree)
{
	deleteTree(tree->root);
	delete tree;
}


void updateHeight(TreeNode *currentTreeNode)
{
	if (currentTreeNode->rightChild != nullptr && currentTreeNode->leftChild != nullptr)
		currentTreeNode->height = max(currentTreeNode->leftChild->height, currentTreeNode->rightChild->height) + 1;
	else if (currentTreeNode->rightChild == nullptr && currentTreeNode->leftChild == nullptr)
		currentTreeNode->height = 1;
	else if (currentTreeNode->rightChild == nullptr)
		currentTreeNode->height = currentTreeNode->leftChild->height + 1;
	else
		currentTreeNode->height = currentTreeNode->rightChild->height + 1;
}


void smallLeftRotate(TreeNode *&currentTreeNode)
{
	TreeNode *right = currentTreeNode->rightChild;
	currentTreeNode->rightChild = right->leftChild;
	right->leftChild = currentTreeNode;
	currentTreeNode = right;
	updateHeight(currentTreeNode->leftChild);
	updateHeight(currentTreeNode);
}


void smallRightRotate(TreeNode *&currentTreeNode)
{
	TreeNode *left = currentTreeNode->leftChild;
	currentTreeNode->leftChild = left->rightChild;
	left->rightChild = currentTreeNode;
	currentTreeNode = left;
	updateHeight(currentTreeNode->rightChild);
	updateHeight(currentTreeNode);
}


void bigLeftRotate(TreeNode *&currentTreeNode)
{
	smallRightRotate(currentTreeNode->rightChild);
	smallLeftRotate(currentTreeNode);
}


void bigRightRotate(TreeNode *&currentTreeNode)
{
	smallLeftRotate(currentTreeNode->leftChild);
	smallRightRotate(currentTreeNode);
}


void balance(TreeNode *&currentTreeNode)
{
	if (balanceFactor(currentTreeNode) == 2) {
		if (balanceFactor(currentTreeNode->rightChild) >= 0)
			smallLeftRotate(currentTreeNode);
		else
			bigLeftRotate(currentTreeNode);
	}
	else if (balanceFactor(currentTreeNode) == -2) {
		if (balanceFactor(currentTreeNode->leftChild) <= 0)
			smallRightRotate(currentTreeNode);
		else
			bigRightRotate(currentTreeNode);
	}
}


int balanceFactor(TreeNode *currentTreeNode)
{
	int leftNodeHeight = 0;
	int rightNodeHeight = 0;
	if (currentTreeNode->leftChild != nullptr)
		leftNodeHeight = currentTreeNode->leftChild->height;
	if (currentTreeNode->rightChild != nullptr)
		rightNodeHeight = currentTreeNode->rightChild->height;
	return rightNodeHeight - leftNodeHeight;
}


void printTree(TreeNode *currentTreeNode)
{
	printf("(");
	printf("%d ", currentTreeNode->value);
	if (currentTreeNode->leftChild != nullptr)
		printTree(currentTreeNode->leftChild);
	else
		printf("null ");
	if (currentTreeNode->rightChild != nullptr)
		printTree(currentTreeNode->rightChild);
	else
		printf("null");
	printf(")");
}


void printTree(Tree *tree)
{
	printTree(tree->root);
	printf("\n");
}


void ascendingTreePrint(TreeNode *currentTreeNode)
{
	if (currentTreeNode == nullptr)
		return;
	ascendingTreePrint(currentTreeNode->leftChild);
	printf("%d ", currentTreeNode->value);
	ascendingTreePrint(currentTreeNode->rightChild);
}


void ascendingTreePrint(Tree *tree)
{
	ascendingTreePrint(tree->root);
	printf("\n");
}


void descendingTreePrint(TreeNode *currentTreeNode)
{
	if (currentTreeNode == nullptr)
		return;
	descendingTreePrint(currentTreeNode->rightChild);
	printf("%d ", currentTreeNode->value);
	descendingTreePrint(currentTreeNode->leftChild);

}


void descendingTreePrint(Tree *tree)
{
	descendingTreePrint(tree->root);
	printf("\n");
}