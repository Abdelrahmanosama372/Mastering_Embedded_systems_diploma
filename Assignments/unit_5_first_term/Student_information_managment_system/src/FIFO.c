#include "../include/FIFO.h"


// -------------------- Helper Functions Declaration--------------------
void swap_studentData(Student_t *prev_student, Student_t *student);


// -------------------- APIs Implementation --------------------
void FIFO_Init(FIFO_t *fifo){
    fifo->head = fifo->students;
    fifo->tail = fifo->students;
    fifo->count = 0;
}

FIFO_Status_t add_student(FIFO_t *fifo,char *firstName, char *lastName, unsigned int payroll, 
                        float GPA, unsigned int *coursesId, unsigned int courses_number){

    if(fifo->count == FIFO_SIZE)
        return FIFO_FULL;

    if(fifo->head == NULL)
        return FIFO_NOT_INITIALIZED;
    
    // to do check student set errors
    set_studentData(fifo->head, firstName, lastName, payroll, GPA, coursesId, courses_number);

    fifo->head++;
    if(fifo->head == fifo->students + FIFO_SIZE) 
        fifo->head = fifo->students;

    fifo->count++;
}

FIFO_Status_t find_student(FIFO_t *fifo, Student_t **student,FIFO_Status_t (*search)(Student_t *, void *), void *searchData, Student_t *start_from_student){

    Student_t *student_ptr;
    if(start_from_student == NULL){
        student_ptr = fifo->tail;
    }else{
        student_ptr = start_from_student;
        if(student_ptr == fifo->students + FIFO_SIZE)
            student_ptr = fifo->students;
    }

    int i;
    for(i=0; i<fifo->count; i++){
        if(lambda(student_ptr, searchData) == FIFO_STUDENT_EXIST){
            *student = student_ptr;
            return FIFO_STUDENT_EXIST;
        }
        student_ptr++;
        if(student_ptr == fifo->students + FIFO_SIZE)
            student_ptr = fifo->students;

        if(student_ptr == fifo->head)
            break;
    }

    return FIFO_STUDENT_NOT_EXIST;
}

FIFO_Status_t delete_student(FIFO_t *fifo, FIFO_Status_t (*search)(Student_t *, void *), void *searchData){
    Student_t *student;
    if(find_student(fifo,&student,search,searchData,NULL) == FIFO_STUDENT_NOT_EXIST)
        return FIFO_STUDENT_NOT_EXIST;

    // shift the array
    Student_t *prev_student;

    for(prev_student = student -1;; prev_student--, student-- ){
        if(prev_student == fifo->students -1)
            prev_student = &(fifo->students[FIFO_SIZE-1]);

        if(student == fifo->students -1)
            student = &(fifo->students[FIFO_SIZE-1]);

        swap_studentData(prev_student,student);
        if(student == fifo->tail)
            break;
    }

    fifo->tail++;
    if(fifo->tail == fifo->students + FIFO_SIZE) 
        fifo->tail = fifo->students;
    fifo->count = fifo->count - 1;
}

void display_fifo(FIFO_t *fifo){
    Student_t *tail_ptr = fifo->tail;
    int i,j;
    for(i=0; i<fifo->count; i++){
        printf("-----------------------------\n");
        printf("the student payroll: %d\n", tail_ptr->payroll);
        printf("the student first name: %s\n", tail_ptr->firstName);
        printf("the student last name: %s\n", tail_ptr->lastName);
        printf("the student gpa: %f\n", tail_ptr->GPA);
        printf("the student courses number: %d\n", tail_ptr->courses_number);
        printf("the student courses id:\n");
        for(j=0; j<tail_ptr->courses_number; j++){
            printf("    course id %d\n",tail_ptr->coursesId[j]);
        }
        tail_ptr++;
        if(tail_ptr == fifo->students + FIFO_SIZE)
            tail_ptr = fifo->students;
    }

}

// -------------------- Helper Functions Implementation --------------------
void swap_studentData(Student_t *prev_student, Student_t *student){
    stpcpy(student->firstName, prev_student->firstName);
    stpcpy(student->lastName, prev_student->lastName);
    student->GPA = prev_student->GPA;
    student->payroll = prev_student->payroll;
    
    int i;
    for(i=0; i<(prev_student->courses_number);i++){
        student->coursesId[i] = prev_student->coursesId[i];
    }
    student->courses_number = prev_student->courses_number;
}


