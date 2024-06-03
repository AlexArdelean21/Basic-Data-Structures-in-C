#pragma once
#include "DataUtil.h"
// Node, createlistnode, insetheadsl, insettaildl, printlist, deleteNode, deleteList
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

void deleteNode(Node* node) {
	if (node != NULL) {
		deleteStudent(node->info);
		free(node);
	}
}

void deleteList(Node** head) {
	while ((*head) != NULL) {
		Node* tmp = *head;
		*head = tmp->next;
		deleteStudent(tmp->info);
		free(tmp);
	}
}

void deleteNodeByKey(Node** head, int key) {
	if (*head == NULL) return;

	Node* temp = *head;
	if ((*head)->info->reference == key && temp != NULL){
		(*head) = temp->next;
		free(temp);
		return;
	}

	Node* prev = NULL;
	while (temp != NULL && temp->info->reference != key) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) return;

	prev->next = temp->next;
	free(temp);

}