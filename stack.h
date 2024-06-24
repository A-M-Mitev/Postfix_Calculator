#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
	double value;
	struct StackNode *next;
}stack_node_t;

typedef struct Stack {
	struct StackNode *head;
	size_t size;
}stack_t;

stack_t* initStack();
stack_node_t* createStackNode(double value);
void pushback(stack_t* stack, double value);
double popback(stack_t* stack);
void releaseStack(stack_t* stack);

void printStack(stack_t* stack);
#endif