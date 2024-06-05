#define _CRT_SECURE_NO_WARNINGS

#include "ListUtil.h"
#include "StackUtil.h"
#include "QueueUtil.h"
#include "HashUtil.h"
#include "TreeUtil.h"

#define LINE_MAX 256

void main() {
	ListNode* head = NULL;
	//StackNode* stack = NULL;
	//QueueNode* tail = NULL;
	//HashNode* hashTable = NULL;
	//memset(hashTable, 0, sizeof(hashTable));
	TreeNode* root = NULL;

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
			//pushStackNode(&stack, stud);
  	//		enqueue(&tail, stud);
			//pushHT(&hashTable, stud);
			insertTreeNode(&root, stud);
		}
		//		Linked List
		//printList(head);
		//deleteNodeByKeyList(&head, 255);
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
		//printHashTable(hashTable);
		//printf("\n");
		//printStudent(getHT(hashTable, "Petre Laura"));

		//deleteHTValue(hashTable, "Petre Laura");
		//printHashTable(hashTable);

		//		Tree
		DisplayTree(root, 0);
		printf("\n");
		printStudent(getMax(root));
		printf("\n");
		deleteNodeByKey(root, 4323.2); // doesn't work
		DisplayTree(root, 0);
	}
}