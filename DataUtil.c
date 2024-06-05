#include "DataUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student* createStudent(char* name, float income, int reference){
    struct Student* stud = (struct Student*)malloc(sizeof(struct Student));
    stud->name = strdup(name);
    stud->income = income;
    stud->reference = reference;
    return stud;
}

void deleteStudent(struct Student* stud) {
    if (stud) {
        free(stud->name);
        free(stud);
    }
}

void printStudent(struct Student* stud) {
    if (stud) {
        printf("Student: %s, Income: %.2f, Age: %d\n", stud->name, stud->income, stud->reference);
    }
}
