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
	(*tail) = node;
}

Student* peeK(QueueNode* tail) {
	Student* result = NULL;
	if(tail != NULL) result = tail->next->info;
	return result;
}

Student* dequeue(QueueNode** tail) {
	Student* result = NULL;
	if (*tail != NULL) {
		result = (*tail)->info;

		if (*tail == (*tail)->next) {
			free(*tail);
			(*tail) = NULL;
		}
		else {
			QueueNode* tmp = (*tail);
			(*tail) = tmp->next;
			free(tmp);
		}
	}
	return result;
}

void printQueue(QueueNode* tail) {
	QueueNode* tmp = tail;
	if (tmp != NULL) {
		do {
			printStudent(tmp->next->info);
			tmp = tmp->next;
		} while (tmp != tail);
	}
}