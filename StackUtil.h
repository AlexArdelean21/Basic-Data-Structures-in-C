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

void pushStackNode(StackNode** stack, Student* stud) {
	StackNode* node = createStackNode(stud);
	node->next = *stack;
	*stack = node;
}

Student* peekStackNode(StackNode* stack) {
	if (stack == NULL) return NULL;

	return stack->info;
}

Student* popStackNode(StackNode** stack) {
	if (*stack == NULL) return NULL;

	StackNode* tmp = *stack;
	Student* info = tmp->info;
	*stack = tmp->next;
	free(tmp);
	 
	return info;
}

void deleteStack(StackNode** stack) {
	while (stack != NULL) {
		Student* info = popStackNode(stack);
		deleteStudent(info);
	}
}

void printStack(StackNode* stack) {
	printf("\t\tThis is a Stack:\n");

	while (stack->next) {
		printStudent(stack->info);
		stack = stack->next;
	}
	printStudent(stack->info);

	printf("\n");
}

