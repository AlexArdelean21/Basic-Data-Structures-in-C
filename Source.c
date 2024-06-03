#define _CRT_SECURE_NO_WARNINGS

#include "ListUtil.h"
#include "StackUtil.h"
#include "QueueUtil.h"
#define LINE_MAX 256

void main() {
	//Node* head = NULL;
	//StackNode* stack = NULL;
	QueueNode* tail = NULL;
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
			//insertHeadSL(&head, stud);
			//pushNode(&stack, stud);
  			enqueue(&tail, stud);
		}
		//printList(head);
		//printStack(stack);
		printQueue(tail);
	}
}