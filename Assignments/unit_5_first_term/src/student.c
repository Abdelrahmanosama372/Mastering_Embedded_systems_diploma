#include "../include/student.h"

Status_t set_studentData(Student_t* student, char *firstName, char *lastName, unsigned int payroll, 
                        float GPA, unsigned int *coursesId, unsigned int courses_number){

    if(set_firstName(student, firstName) == FIRST_NAME_SET_FAILURE)
        return FIRST_NAME_SET_FAILURE;

    if(set_LastName(student, lastName) == LAST_NAME_SET_FAILURE)
        return LAST_NAME_SET_FAILURE;

    if(set_payRoll(student, payroll) == PAYROLL_SET_FAILURE)
        return PAYROLL_SET_FAILURE;

    if(set_GPA(student, GPA) == GPA_SET_FAILURE)
        return GPA_SET_FAILURE;

    if(set_coursesID(student, coursesId, courses_number) == COURSES_ID_SET_FAILURE)
        return COURSES_ID_SET_FAILURE;

    return SUCCESS;
}

Status_t set_firstName(Student_t* student, char *name){
    if(student == NULL || strlen(name) > (NAME_LEN -1))
        return FIRST_NAME_SET_FAILURE;
    strcpy(student->firstName, name);
    return SUCCESS;
}

Status_t set_LastName(Student_t* student, char *name){
    if(student == NULL || strlen(name) > (NAME_LEN -1))
        return LAST_NAME_SET_FAILURE;
    strcpy(student->lastName, name);
    return SUCCESS;
}

Status_t set_payRoll(Student_t* student, unsigned int payroll){
    if(student == NULL)
        return PAYROLL_SET_FAILURE;
    student->payroll = payroll;
    return SUCCESS;
}

Status_t set_GPA(Student_t* student, float GPA){
    if(student == NULL || GPA > 4)
        return GPA_SET_FAILURE;
    student->GPA = GPA;
    return SUCCESS;
}

Status_t set_coursesID(Student_t* student, unsigned int *ids, unsigned int courses_number){
    if(student == NULL || courses_number > COURSES_MAX_NUM)
        return COURSES_ID_SET_FAILURE;
    int i;
    for(i=0; i<courses_number; i++){
        student->coursesId[i] = ids[i];
    }
    return SUCCESS;
}