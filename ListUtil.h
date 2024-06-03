#pragma once
#include "DataUtil.h"

typedef struct Node {
	Student* info;
	struct Node* next;
	struct Node* prev;
}Node;

Node* createListNode(Student* stud) {
	Node* node = NULL;
	node = (Node*)malloc(sizeof(Node));
	node->info = stud;
	node->next = node->prev = NULL;
	return node;
}
void insertHeadSL(Node** head, Student* stud) {
	Node* node = createListNode(stud);
	node->next = *head;
	*head = node;
}

Node* insetTailDl(Node* head, Student* stud) {
	Node* node = createListNode(stud);
	if (head == NULL) {
		return node;
	}
	else {
		Node* tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		node->prev = tmp;
		tmp->next = node;
		return head;
	}
}

void printList(Node* head) {
	printf("This is a linked list!\n\n");
	if (head == NULL) printf("The list is empty!");
	else {
		while (head) {
			printStudent(head->info);
			head = head->next;
		}
	}
}