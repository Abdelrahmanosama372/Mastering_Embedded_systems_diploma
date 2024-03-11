#include "student-dataBase.h"
#include <stdio.h>
#include <stdlib.h>


void add_student(struct Student_t** head){
    struct Student_t* allocStudent = NULL;
    allocStudent = (struct Student_t*) malloc(sizeof(struct Student_t));

    if(*head == NULL){
        *head = allocStudent;
    }else{
        struct Student_t* currStudent = *head;
        while (currStudent->PNextStudent) {
            currStudent =currStudent->PNextStudent;
        }
        currStudent->PNextStudent = allocStudent;
    }

    allocStudent->PNextStudent = NULL;
    set_studentData(allocStudent);
}

void set_studentData(struct Student_t* student){
    printf("enter your id: ");
    scanf("%d",&student->data.id);

    printf("enter your name: ");
    scanf("%s",&student->data.name);

    printf("enter your height: ");
    scanf("%f",&student->data.height);
}


void viewAllStudents(struct Student_t* head){
    struct Student_t* currStudent = head;
    while (currStudent) {
        viewStudent(currStudent);
        currStudent = currStudent->PNextStudent;
    }
}

void viewStudent(struct Student_t* student){
    printf("-------------------------------\n");
    printf("student id: %d\n",student->data.id);
    printf("student name: %s\n",student->data.name);
    printf("student height: %.2f\n",student->data.height);
}

int deleteStudent(struct Student_t** head,unsigned int id){
    struct Student_t* currStudent = *head;
    struct Student_t* pervStudent = *head;

    while (currStudent && currStudent->data.id != id) {
        pervStudent = currStudent;
        currStudent = currStudent->PNextStudent;
    }

    // student not exsists
    if(currStudent == NULL)
        return STUDENT_NOT_EXSISTS;

    // deletion of head student
    if(currStudent == pervStudent){
        *head = currStudent->PNextStudent;
    }else{        
        if(currStudent->PNextStudent == NULL){
            // deletion of last student
            pervStudent->PNextStudent = NULL;
        }else{
            pervStudent->PNextStudent = currStudent->PNextStudent;
        }
    }

    free(currStudent);
    return STUDENT_DELETED;
}

unsigned int get_LinkedlistLen_iter(struct Student_t* head){
    struct Student_t* currStudent = head; 
    unsigned int counter = 0;
    while (currStudent) {
        counter++;
        currStudent = currStudent->PNextStudent;
    }
    return counter;
}

unsigned int get_LinkedlistLen_rec(struct Student_t* head){
    if(head == NULL)
        return 0;
    return 1 + get_LinkedlistLen_rec(head->PNextStudent);
}

struct Student_t* get_NthStudent_Front(struct Student_t* head, unsigned int nth){
    struct Student_t* currStudent = head; 
    unsigned int counter = 0;
    while(currStudent){
        counter++;
        if(counter == nth)
            return currStudent;
        currStudent = currStudent->PNextStudent;
    }
    return NULL;
}

struct Student_t* get_NthStudent_End(struct Student_t* head, unsigned int nth){
    struct Student_t* currStudent = head; 
    unsigned int list_lenght = get_LinkedlistLen_iter(currStudent);
    int counter = list_lenght - nth;

    if(counter < 0)
        return NULL;

    while(counter-- > 0){
        currStudent = currStudent->PNextStudent;
    }

    return currStudent;
}


struct Student_t* get_MiddleStudent(struct Student_t* head){
    struct Student_t* slowPtr = head; 

    // no students
    if(slowPtr == NULL)
        return NULL;

    // one student in list
    if(slowPtr->PNextStudent == NULL)
        return slowPtr;

    // intialize fastPtr with second student in list
    struct Student_t* fastPtr = slowPtr->PNextStudent;
    while (fastPtr) {
        fastPtr = fastPtr->PNextStudent;
        if(fastPtr)
            fastPtr = fastPtr->PNextStudent;
        slowPtr = slowPtr->PNextStudent;
    } 

    return slowPtr;
}

void reverseStudentsList(struct Student_t** head){
    struct Student_t* currStudentPtrPtr = *head;
    // no students || one student
    if(!(*head) || (*head)->PNextStudent == NULL)
        return;

    unsigned int studentsNumber = get_LinkedlistLen_iter(*head);
    // reserve array of pointers to pointers to students of size = size of ptr * number of students
    struct Student_t** students = (struct Student_t**) malloc(sizeof(struct Student_t**) * studentsNumber);
    for(int i=0; i<studentsNumber; i++){
        students[i] = currStudentPtrPtr;
        currStudentPtrPtr = currStudentPtrPtr->PNextStudent;
    }

    // set head to last student
    *head = students[studentsNumber-1];
    for(int i=studentsNumber-1; i>=1; i--){
        (students[i])->PNextStudent = students[i-1];
    }

    students[0]->PNextStudent = NULL;
}

char loopDetection(struct Student_t* head){
    struct Student_t* currStudentSlow = head;
    struct Student_t* currStudentFast = head;

    // no students || one student
    if(!(head) || (head)->PNextStudent == NULL)
        return 0;

    while (currStudentFast) {
        currStudentFast = currStudentFast->PNextStudent;
        if(currStudentFast)
            currStudentFast = currStudentFast->PNextStudent;
        currStudentSlow = currStudentSlow->PNextStudent;
        if(currStudentFast->data.id == currStudentSlow->data.id)
            return 1;
    }

    return 0;
}

void deleteAllStudents(struct Student_t* head){
    struct Student_t* currStudent = head; 
    struct Student_t* nextStudent = head; 

    while (currStudent) {
        nextStudent = currStudent->PNextStudent;
        free(currStudent);
        currStudent = nextStudent;
    }
}