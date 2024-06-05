#pragma once
#include "main.h" 

typedef struct Student {
	char* name;
	float income;
	int reference;
}Student;

inline Student* createStudent(char* name, float income, int ref) {
	Student* stud = NULL;
	stud = (Student*)malloc(sizeof(Student));
	stud->name = (char*)malloc(sizeof(name) + 1);
	strcpy_s(stud->name, strlen(name) + 1, name);
	stud->income = income;
	stud->reference = ref;
	return stud;
}

inline void printStudent(Student* stud) {
	if (stud != NULL) {
		printf("Name: %s, income: %f, reference: %d\n", stud->name, stud->income, stud->reference);
	}
}

inline void deleteStudent(Student* stud) {
	if (stud != NULL) {
		free(stud->name); // error here when i delete a student  from the hash table
		free(stud);
	} 
}