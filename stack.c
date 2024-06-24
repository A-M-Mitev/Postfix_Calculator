#include "stack.h"

stack_t* initStack() {
	stack_t* newStack = (stack_t*)malloc(sizeof(stack_t));
	if(newStack == NULL) {
		printf("\nError when allocating memory for stack\n");
		exit(1);
	}
	newStack->head = NULL;
	newStack->size = 0;
	return newStack;
}

stack_node_t* createStackNode(int value) {
	stack_node_t* newNode = (stack_node_t*)malloc(sizeof(stack_node_t));
	if(newNode == NULL) {
		printf("\nError when allocating memory for stack_node\n");
		exit(1);
	}
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}

void pushback(stack_t* stack, int value) {
	if(stack == NULL) return ;
	if(stack->head == NULL) {
		stack->head = createStackNode(value);
		stack->size++;
		return ;
	}
	stack_node_t* curr = stack->head;
	while(curr->next) {
		curr = curr->next;
	}
	curr->next = createStackNode(value);
	stack->size++;
}

int popback(stack_t* stack) {
	if(stack == NULL) return 0;
	if(stack->head == NULL) {
		printf("\nStack is empty\n");
		return 0;
	}
	int result;
	if(stack->head->next == NULL) {
		result = stack->head->value;
		free(stack->head);
		stack->head = NULL;
		stack->size--;
		return result;
	}

	stack_node_t* curr = stack->head;
	stack_node_t* next = curr->next;
	while(next->next) {
		curr = next;
		next = next->next;
	}
	result = next->value;
	free(next);
	curr->next = NULL;
	stack->size--;
	return result;
}

void releaseStack(stack_t* stack) {
	while(stack->head) {
		popback(stack);
	}
}

void printStack(stack_t* stack) {
	stack_node_t* curr = stack->head;
	printf("\nStack values:");
	while(curr) {
		printf(" %d", curr->value);
		curr = curr->next;
	}
	printf("\n%d elements in stack\n", stack->size);
}