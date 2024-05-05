#include <stdio.h>
#include <string.h>

#define NAME_LEN 50
#define COURSES_MAX_NUM 10

typedef struct
{
    char firstName[NAME_LEN];
    char lastName[NAME_LEN];
    unsigned int payroll;
    float GPA;
    unsigned int coursesId[COURSES_MAX_NUM];
}Student_t;

typedef enum {
    FIRST_NAME_SET_FAILURE,
    LAST_NAME_SET_FAILURE,
    PAYROLL_SET_FAILURE,
    GPA_SET_FAILURE,
    COURSES_ID_SET_FAILURE,
    SUCCESS
}Status_t;

// -------------------- APIs --------------------
Status_t set_studentData(Student_t* student, char *firstName, char *lastName, unsigned int payroll, float GPA, unsigned int *coursesId, unsigned int courses_number);
Status_t set_firstName(Student_t* student, char *name);
Status_t set_LastName(Student_t* student, char *name);
Status_t set_payRoll(Student_t* student, unsigned int payroll);
Status_t set_GPA(Student_t* student, float GPA);
Status_t set_coursesID(Student_t* student, unsigned int *ids, unsigned int courses_number);