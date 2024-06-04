#pragma onece
#include "DataUtil.h"

typedef struct QueueNode {
	Student* info;
	struct QueueNode* next;
}QueueNode;

QueueNode* createQueueNode(Student* info) {
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->info = info;
	node->next = NULL;
	return node;
}

void enqueue(QueueNode** tail, Student* stud) {
	QueueNode* node = createQueueNode(stud);
	if (*tail == NULL) {
		node->next = node;
	}
	else {
		node->next = (*tail)->next;
		(*tail)->next = node;
	}
	*tail = node;
}

Student* peek(QueueNode* tail) {
	if (tail == NULL) return NULL;

	return tail->next->info;
}

Student* dequeue(QueueNode** tail) {
	if (*tail == NULL) return NULL;

	QueueNode* head = (*tail)->next; // error here
 	Student* info = head->info;

	if (*tail == head) {
		free(head);
		*tail = NULL;
	}
	else {
		(*tail)->next = head->next;
		free(head);
	}

	return info;
}

void printQueue(QueueNode* tail) {
	printf("\t\tThis is a Queue!\n");
	if (tail == NULL) {
		printf("The queue is empty!");
		return;
	}

	QueueNode* head = tail->next;
	while (head != tail) {
		printStudent(head->info);
		head = head->next;
	}
}
// node, createQueueNode, enqueue, peek, dequeue, print