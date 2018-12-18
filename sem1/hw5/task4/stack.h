#pragma once

#include <cstdio>
#include <string>
#include <fstream>
using namespace std;
const int maxLength = 40;

typedef int StackElementType;

struct StackElement {
	char value;
	StackElement *previous;
};

struct Stack {
	StackElement *top;
	int count;
};

Stack *createStack();
bool isEmpty(Stack *stack);
void push(Stack *stack, StackElementType);
void pop(Stack *stack);
void deleteStack(Stack *stack);
StackElementType returnTop(Stack *stack);
