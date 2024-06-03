#pragma once
#include "DataUtil.h"

typedef struct StackNode {
	Student* info;
	struct StackNode* next;
}StackNode;

StackNode* createStackNode(Student* info) {
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	node->info = info;
	node->next = NULL;
	return node;
}

void pushNode(StackNode** stack, Student* info) {
	StackNode* node = createStackNode(info);
	node->next = *stack;
	*stack = node;
}

Student* peekNode(StackNode* stack) {
	Student* stud = NULL;
	if (stack != NULL) {
		stud = stack->info;
	}
	return stud;
}

Student* popNode(StackNode** stack) {
	Student* stud = NULL;
	if (stack != NULL) {
		stud = (*stack)->info;
		StackNode* tmp = *stack;
		*stack = tmp->next;
		free(tmp);
	}
	return stud;
}

void deleteStack(StackNode** stack) {
	while (*stack) {
		popNode(stack);
	}
}

// write a function to print the stack
void printStack(StackNode* stack) {
	printf("This is a stack!\n\n");
	if (stack == NULL) printf("The stack is empty!");
	while (stack) {
		printStudent(stack->info);
		stack = stack->next;
	}
}