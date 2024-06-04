#define _CRT_SECURE_NO_WARNINGS

#include "ListUtil.h"
#include "StackUtil.h"
#include "QueueUtil.h"
#include "HashUtil.h"

#define LINE_MAX 256

void main() {
	ListNode* head = NULL;
	StackNode* stack = NULL;
	QueueNode* tail = NULL;
	HashNode* hashTable = NULL;
	//memset(hashTable, 0, sizeof(hashTable));

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile) {
		char delimiter[] = ",";
		char* token = NULL;
		float income;
		int ref, index = 0;
		char name[LINE_MAX], buffer[LINE_MAX];
		while (fgets(buffer, sizeof(buffer), pFile)) {
			token = strtok(buffer, delimiter);
			strcpy(name, token);
			token = strtok(NULL, delimiter);
			income = atof(token);
			token = strtok(NULL, delimiter);
			ref = atoi(token);
			Student* stud = createStudent(name, income, ref);


			insertHeadList(&head, stud);
			pushStackNode(&stack, stud);
  			enqueue(&tail, stud);
			pushHT(&hashTable, stud);
		}
		//		Linked List
		//printList(head);
		//deleteNodeByKey(&head, 255);
		//printList(head);

		//		Stack
		//printStack(stack);
		//printStudent(popStackNode(&stack));
		//printf("\n");
		//printStack(stack);
		
		//		Queue
		//printQueue(tail);
		//printStudent(dequeue(tail));
		//printf("\n");
		//printQueue(tail);

		//		HashTable
		// remove the "\n: from printStudent before using this
		printHashTable(hashTable);
		printStudent(getHT(hashTable, "Popa Maria"));
		deleteHTValue(hashTable, "Popa Maria");
		printHashTable(hashTable);
	}
}