
#ifndef STUDENT_H_
#define STUDENT_H_

#include <stdio.h>
#include <string.h>

#define NAME_LEN 50
#define COURSES_MAX_NUM 10

/**
 * @brief Structure representing a student's information.
 * 
 * This structure holds various attributes of a student including their first name, last name,
 * payroll number, GPA, and course IDs.
 */
typedef struct
{
    char firstName[NAME_LEN];       ///< First name of the student.
    char lastName[NAME_LEN];        ///< Last name of the student.
    unsigned int payroll;           ///< Payroll number of the student.
    float GPA;                      ///< Grade Point Average (GPA) of the student.
    unsigned int coursesId[COURSES_MAX_NUM];   ///< Array of course IDs taken by the student.
    unsigned int courses_number;    ///< Number of courses taken by the student.
} Student_t;

/**
 * @brief Enumeration representing the status of setting student data.
 * 
 * This enumeration defines possible status values that can occur when setting
 * data for a student object.
 */
typedef enum {
    FIRST_NAME_SET_FAILURE,    ///< Failure to set the first name for the student.
    LAST_NAME_SET_FAILURE,     ///< Failure to set the last name for the student.
    PAYROLL_SET_FAILURE,       ///< Failure to set the payroll number for the student.
    GPA_SET_FAILURE,           ///< Failure to set the GPA for the student.
    COURSES_ID_SET_FAILURE,    ///< Failure to set the course IDs for the student.
    SUCCESSFULL_SET            ///< Successful setting of student data.
} Status_t;

// -------------------- APIs --------------------

/**
 * @brief Sets the data of a student.
 * 
 * @param student Pointer to the Student_t structure to set the data for.
 * @param firstName Pointer to the first name of the student.
 * @param lastName Pointer to the last name of the student.
 * @param payroll The payroll of the student.
 * @param GPA The GPA of the student.
 * @param coursesId Pointer to an array of course IDs for the student.
 * @param courses_number The number of courses for the student.
 * @return Status_t The status of the operation.
 */
Status_t set_studentData(Student_t* student, char *firstName, char *lastName, unsigned int payroll, float GPA, unsigned int *coursesId, unsigned int courses_number);

/**
 * @brief Sets the first name of a student.
 * 
 * @param student Pointer to the Student_t structure.
 * @param name Pointer to the first name to set.
 * @return Status_t The status of the operation.
 */
Status_t set_firstName(Student_t* student, char *name);

/**
 * @brief Sets the last name of a student.
 * 
 * @param student Pointer to the Student_t structure.
 * @param name Pointer to the last name to set.
 * @return Status_t The status of the operation.
 */
Status_t set_lastName(Student_t* student, char *name);

/**
 * @brief Sets the payroll of a student.
 * 
 * @param student Pointer to the Student_t structure.
 * @param payroll The payroll to set.
 * @return Status_t The status of the operation.
 */

Status_t set_payRoll(Student_t* student, unsigned int payroll);

/**
 * @brief Sets the GPA of a student.
 * 
 * @param student Pointer to the Student_t structure.
 * @param GPA The GPA to set.
 * @return Status_t The status of the operation.
 */
Status_t set_GPA(Student_t* student, float GPA);

/**
 * @brief Sets the course IDs of a student.
 * 
 * @param student Pointer to the Student_t structure.
 * @param ids Pointer to an array of course IDs.
 * @param courses_number The number of courses.
 * @return Status_t The status of the operation.
 */
Status_t set_coursesID(Student_t* student, unsigned int *ids, unsigned int courses_number);

/**
 * @brief Displays the details of a student.
 * 
 * @param student Pointer to the Student_t structure to display.
 */
void display_student(Student_t* student);

#endif /* STUDENT_H_ */