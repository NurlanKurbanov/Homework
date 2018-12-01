#include "stack.h"

Stack *createStack()
{
	return new Stack{ nullptr, 0 };

}


bool isEmpty(Stack *stack)
{
	return stack->count == 0;
}


void push(Stack *stack, char value)
{
	stack->top = new StackElement{ value, stack->top };
	stack->count++;
}


void pop(Stack *stack)
{
	StackElement *current = stack->top;
	stack->top = stack->top->previous;
	delete current;
	stack->count--;
}

void deleteStack(Stack *stack)
{
	while (stack->count > 0) {
		pop(stack);
		stack->count--;
	}
	delete stack;
}

char returnTop(Stack *stack)
{
	if (stack->top == nullptr)
		return 0;
	return stack->top->value;
}