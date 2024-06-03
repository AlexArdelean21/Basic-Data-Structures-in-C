#pragma once
#include "DataUtil.h"
typedef struct ListNode {
	Student* info;
	struct Node* next;
	struct Node* prev;
}ListNode;

ListNode* createListNode(Student* info) {
	ListNode* node = NULL;
	node = (ListNode*)malloc(sizeof(ListNode));
	node->info = info;
	node->next = node->prev = NULL;
	return node;
}

void insertHeadList(ListNode** head, Student* stud) {
	ListNode* node = createListNode(stud);
	node->next = (*head);
	*head = node;
}

void insetTailDL(ListNode** head, Student* stud) {
	ListNode* node = createListNode(stud);
	if (*head == NULL) *head = node;
	else {
		ListNode* tmp = (*head);
		while (tmp->next) {
			tmp = tmp->next;
		}
		node->prev = tmp;
		tmp->next = node;
		free(tmp);
	}
}

void printList(ListNode* head) {
	printf("\t\tThis is a Linked list:\n");

	if (head == NULL) {
		printf("The list is empty!");
		return;
	}

	while (head->next) {
		printStudent(head->info);
		head = head->next;
	}
	printStudent(head->info);
	printf("\n");
}

void deleteNode(ListNode* node) {
	if (node == NULL) return;

	deleteStudent(node->info);
	free(node);
}

void deleteList(ListNode** head) {
	if ((*head) == NULL) return;

	while (*head != NULL) {
		ListNode* tmp = *head;
		*head = tmp->next;
		deleteNode(tmp);
	}
}

void deleteNodeByKey(ListNode** head, int key) {
	ListNode** current = head;

	while (*current) {
		if ((*current)->info->reference == key) {
			ListNode* tmp = *current;
			*current = (*current)->next;
			free(tmp);
		}
		current = &((*current)->next);
	}
}

// Node, createlistnode, insetheadsl, insettaildl, printlist, deleteNode, deleteList
