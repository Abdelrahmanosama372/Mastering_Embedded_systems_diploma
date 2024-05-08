#ifndef SYSTEM_MANAGER_H_
#define SYSTEM_MANAGER_H_

#include <stdlib.h>
#include "student.h"
#include "FIFO.h"
#include "fileManager.h"

/**
 * @brief Structure representing the System Manager.
 */
typedef struct
{
    FIFO_t students_fifo; /**< FIFO structure to manage students. */
} SystemManager_t;

/**
 * @brief Enumeration representing different types of student information.
 */
typedef enum {
    PAYROLL, /**< Payroll information. */
    FIRSTNAME, /**< First name information. */
    LASTNAME, /**< Last name information. */
    GPA, /**< GPA information. */
    COURSEID, /**< Course ID information. */
    COURSEIDS, /**< Course IDs information. */
    COURSESNUMBER /**< Number of courses information. */
} Student_Info_t;

/**
 * @brief Enumeration representing different statuses of System Manager operations.
 */
typedef enum {
    SYS_STUDENT_IS_ADDED, /**< Student is successfully added. */
    SYS_STUDENT_IS_NOT_ADDED, /**< Student could not be added. */
    SYS_STUDENT_INFO_IS_UPDATED, /**< Student information is successfully updated. */
    SYS_STUDENT_NOT_EXISTS, /**< Student does not exist. */
    SYS_STUDENT_IS_DELETED /**< Student is successfully deleted. */
} SystemManager_Status_t;


typedef enum {
    SUCCESS, /**< Success status. */
    WARNING, /**< Warning status. */
    ERROR /**< Error status. */
} Display_Status_t;

// -------------------- APIs --------------------

/**
 * @brief Initializes the System Manager.
 * 
 * @param sysManager Pointer to the System Manager structure.
 */
void SystemManager_Init(SystemManager_t *sysManager);

/**
 * @brief Adds a student to the system.
 * 
 * @param sysManager Pointer to the System Manager structure.
 * @return SystemManager_Status_t Status of the operation.
 */
SystemManager_Status_t SystemManager_addStudent(SystemManager_t *sysManager);

/**
 * @brief Adds students from a file to the system.
 * 
 * @param sysManager Pointer to the System Manager structure.
 * @param fileName Name of the file containing student records.
 * @return SystemManager_Status_t Status of the operation.
 */
SystemManager_Status_t SystemManager_addStudentFromFile(SystemManager_t *sysManager, const char *fileName);

/**
 * @brief Updates student information in the system.
 * 
 * @param sysManager Pointer to the System Manager structure.
 * @param info Type of information to update.
 * @return SystemManager_Status_t Status of the operation.
 */
SystemManager_Status_t SystemManager_updateStudentInfo(SystemManager_t *sysManager, Student_Info_t info);

/**
 * @brief Deletes a student from the system.
 * 
 * @param sysManager Pointer to the System Manager structure.
 * @return SystemManager_Status_t Status of the operation.
 */
SystemManager_Status_t SystemManager_deleteStudent(SystemManager_t *sysManager);

/**
 * @brief Finds a student in the system based on the specified criteria.
 * 
 * @param sysManager Pointer to the System Manager structure.
 * @param property Type of information to search for.
 * @param start_from_student Pointer to the student to start the search from (optional).
 * @return Student_t* Pointer to the found student, or NULL if not found.
 */
Student_t* SystemManager_findStudent(SystemManager_t *sysManager, Student_Info_t property, Student_t *start_from_student);

/**
 * @brief Gets the total number of students in the system.
 * 
 * @param sysManager Pointer to the System Manager structure.
 * @return unsigned int Total number of students.
 */
unsigned int SystemManager_getStudentsCount(SystemManager_t *sysManager);

/**
 * @brief Displays information about all students in the system.
 * 
 * @param sysManager Pointer to the System Manager structure.
 */
void SystemManager_displayAllStudents(SystemManager_t *sysManager);

/**
 * @brief Displays information about a specific student.
 * 
 * @param sysManager Pointer to the System Manager structure.
 * @param student Pointer to the student whose information is to be displayed.
 */
void SystemManager_displayStudent(SystemManager_t *sysManager, Student_t* student);

/**
 * @brief Displays a message with a specified status.
 * 
 * @param message Message to be displayed.
 * @param status Status of the message (SUCCESS, WARNING, ERROR).
 */
void display(char *messsage, Display_Status_t status);

// -------------------- Search APIs --------------------
/**
 * @brief Searches for a student by their first name.
 * 
 * This function compares the first name of the provided student with the specified name.
 * 
 * @param student Pointer to the student structure to be searched.
 * @param name Pointer to the first name string to search for.
 * @return FIFO_Status_t Status of the search operation (FIFO_STUDENT_EXIST if found, FIFO_STUDENT_NOT_EXIST otherwise).
 */
FIFO_Status_t search_with_firstName(Student_t *student, void *name);

/**
 * @brief Searches for a student by their payroll number.
 * 
 * This function compares the payroll number of the provided student with the specified payroll number.
 * 
 * @param student Pointer to the student structure to be searched.
 * @param payroll Pointer to the payroll number to search for.
 * @return FIFO_Status_t Status of the search operation (FIFO_STUDENT_EXIST if found, FIFO_STUDENT_NOT_EXIST otherwise).
 */
FIFO_Status_t search_with_payroll(Student_t *student, void *payroll);

/**
 * @brief Searches for a student by their course ID.
 * 
 * This function searches for the specified course ID in the courses ID array of the provided student.
 * 
 * @param student Pointer to the student structure to be searched.
 * @param courseId Pointer to the course ID to search for.
 * @return FIFO_Status_t Status of the search operation (FIFO_STUDENT_EXIST if found, FIFO_STUDENT_NOT_EXIST otherwise).
 */
FIFO_Status_t search_with_courseId(Student_t *student, void *courseId);


#endif