
#ifndef FIFO_H_
#define FIFO_H_

#include "student.h"

#define FIFO_SIZE 10

/**
 * @brief Structure representing a First-In-First-Out (FIFO) queue of students.
 * 
 * This structure maintains a queue of students using a Array approach. It contains
 * pointers to the head and tail of the queue, an array to store student objects, and a count
 * of the number of students in the queue.
 */
typedef struct
{
   Student_t *head;                  ///< Pointer to the head of the queue.
   Student_t *tail;                  ///< Pointer to the tail of the queue.
   Student_t students[FIFO_SIZE];    ///< Array to store student objects.
   unsigned int count;               ///< Number of students in the queue.
} FIFO_t;

/**
 * @brief Enumeration representing the status of FIFO operations.
 * 
 * This enumeration defines possible status values that can occur during FIFO operations,
 * such as adding, finding, or deleting students from the queue.
 */
typedef enum {
    FIFO_STUDENT_EXIST,        ///< The student exists in the FIFO.
    FIFO_STUDENT_NOT_EXIST,    ///< The student does not exist in the FIFO.
    FIFO_FULL,                 ///< The FIFO is full and cannot accept more students.
    FIFO_NOT_INITIALIZED,      ///< The FIFO has not been initialized.
    FIFO_STUDENT_DELETED       ///< The student has been successfully deleted from the FIFO.
} FIFO_Status_t;


// -------------------- APIs --------------------
/**
 * @brief Initializes the FIFO data structure.
 * 
 * @param fifo Pointer to the FIFO structure to be initialized.
 */
void FIFO_Init(FIFO_t *fifo);

/**
 * @brief Adds a student to the FIFO.
 * 
 * @param fifo Pointer to the FIFO structure.
 * @param firstName Pointer to the first name of the student.
 * @param lastName Pointer to the last name of the student.
 * @param payroll The payroll number of the student.
 * @param GPA The GPA of the student.
 * @param coursesId Pointer to an array of course IDs.
 * @param courses_number The number of courses the student is enrolled in.
 * @return FIFO_Status_t Status of the operation (SUCCESS, FIFO_FULL, or FIFO_NOT_INITIALIZED).
 */
FIFO_Status_t add_student(FIFO_t *fifo,char *firstName, char *lastName, unsigned int payroll, 
                        float GPA, unsigned int *coursesId, unsigned int courses_number);

/**
 * @brief Finds a student in the FIFO based on a custom search function.
 * 
 * @param fifo Pointer to the FIFO structure.
 * @param student Pointer to the pointer that will store the found student.
 * @param search Pointer to a function that defines the search criteria.
 * @param searchData Data used by the search function.
 * @param start_from_student Pointer to the student from which to start the search (optional).
 * @return FIFO_Status_t Status of the operation (FIFO_STUDENT_EXIST or FIFO_STUDENT_NOT_EXIST).
 */
FIFO_Status_t find_student(FIFO_t *fifo, Student_t **student,FIFO_Status_t (*search)(Student_t *, void *), void *searchData, Student_t *start_from_student);

/**
 * @brief Deletes a student from the FIFO based on a custom search function.
 * 
 * @param fifo Pointer to the FIFO structure.
 * @param search Pointer to a function that defines the deletion criteria.
 * @param searchData Data used by the search function.
 * @return FIFO_Status_t Status of the operation (FIFO_STUDENT_DELETED or FIFO_STUDENT_NOT_EXIST).
 */
FIFO_Status_t delete_student(FIFO_t *fifo, FIFO_Status_t (*search)(Student_t *, void *), void *searchData);

/**
 * @brief Displays the students in the FIFO.
 * 
 * @param fifo Pointer to the FIFO structure.
 */
void display_fifo(FIFO_t *fifo);

#endif /* FIFO_H_ */