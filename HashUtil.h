#pragma once
#include "DataUtil.h"

#define HASH_SIZE 26

typedef struct HashNode {
	Student* info;
	struct HashNode* next;
}HashNode;

int fHash(const char* key) {
	return key[0] % HASH_SIZE;
}

HashNode* createHashNode(Student* info) {
	HashNode* node = (HashNode*)malloc(sizeof(HashNode));
	node->info = info;
	node->next = NULL;
	return node;
}

void pushHT(HashNode*** hashTable, Student* stud) {
	if (*hashTable == NULL) {
		(*hashTable) = (HashNode**)malloc(sizeof(HashNode*) * HASH_SIZE);
		memset((*hashTable), 0, sizeof(HashNode*) * HASH_SIZE);
	}

	HashNode* node = createHashNode(stud);
	int hashValue = fHash(stud->name);
	node->next = (*hashTable)[hashValue];
	(*hashTable)[hashValue] = node;
}

Student* getHT(HashNode** hashTable, const char* key) {
	int hashValue = fHash(key);
	HashNode* head = hashTable[hashValue];
	
	while (head) {
		if (strcmp(head->info->name, key) == 0) {
			return head->info;
		}
		head = head->next;
	}
	
	return NULL;
}

void deleteHTValue(HashNode** hashTable, const char* key) {
	int hashValue = fHash(key);
	HashNode* head = hashTable[hashValue];

	if (!head) return;

	if (strcmp(head->info->name, key) == NULL) {
		hashTable[hashValue] = head->next;
		deleteStudent(head->info);
		free(head);
	}
	else {
		while (head && head->next) {
			if (strcmp(head->next->info->name, key) == 0) {
				HashNode* tmp = head->next;
				head->next = tmp->next;
				//deleteStudent(tmp->info); this is the error, idk why
				free(tmp);
			}
			head = head->next;
		}
	}
}

// create a function to print the hashtable

void printHashTable(HashNode** hashTable) {
	printf("\t\tThis is a HashTable!\n");
	if (hashTable == NULL) {
		printf("The HashTable is empty!");
		return;
	}

	for (int i = 0; i < HASH_SIZE; i++) {
		HashNode* head = hashTable[i];

		if (head == NULL) printf("The key %d is empty!\n", i);

		while (head) {
			printf("\n");
			printStudent(head->info);
			int keyVal = fHash(head->info->name);
			printf("  ==>  with the key %d \n\n", keyVal);
			head = head->next;
		}
	}

}