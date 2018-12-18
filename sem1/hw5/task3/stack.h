#pragma once

#include <cstdio>
#include <string>
#include <fstream>
using namespace std;

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
void push(Stack *stack, char value);
void pop(Stack *stack);
void deleteStack(Stack *stack);
char returnTop(Stack *stack);