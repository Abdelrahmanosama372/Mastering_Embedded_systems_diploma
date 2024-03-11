#include <stdio.h>
#include <stdlib.h>

#define STUDENT_DELETED  1     
#define STUDENT_NOT_EXSISTS 2 

typedef struct
{
    unsigned int id;
    char name[50];
    float height;
}StudentData_t;

struct Student_t
{
    StudentData_t data;
    struct Student_t* PNextStudent;
};

/**
 * @brief Adds a new student to the linked list.
 * 
 * @param head Pointer to a pointer to the head of the linked list.
 */
void add_student(struct Student_t** head);

/**
 * @brief Sets the data of a student.
 * 
 * @param student Pointer to the student whose data will be set.
 */
void set_studentData(struct Student_t* student);

/**
 * @brief Displays information about all students in the linked list.
 * 
 * @param head Pointer to the head of the linked list.
 */
void viewAllStudents(struct Student_t* head);

/**
 * @brief Displays information about a specific student.
 * 
 * @param student Pointer to the student whose information will be displayed.
 */
void viewStudent(struct Student_t* student);

/**
 * @brief Deletes a student from the linked list based on the given ID.
 * 
 * @param head Pointer to a pointer to the head of the linked list.
 * @param id ID of the student to be deleted.
 * @return STUDENT_DELETED if the student was deleted successfully, 
 *         STUDENT_NOT_EXSISTS if the student does not exist.
 */
int deleteStudent(struct Student_t** head, unsigned int id);

/**
 * @brief Calculates the length of the linked list iteratively.
 * 
 * @param head Pointer to the head of the linked list.
 * @return The length of the linked list.
 */
unsigned int get_LinkedlistLen_iter(struct Student_t* head);

/**
 * @brief Calculates the length of the linked list recursively.
 * 
 * @param head Pointer to the head of the linked list.
 * @return The length of the linked list.
 */
unsigned int get_LinkedlistLen_rec(struct Student_t* head);

/**
 * @brief Retrieves the Nth student from the front of the linked list.
 * 
 * @param head Pointer to the head of the linked list.
 * @param nth Index of the student to retrieve.
 * @return Pointer to the Nth student from the front, or NULL if not found.
 */
struct Student_t* get_NthStudent_Front(struct Student_t* head, unsigned int nth);

/**
 * @brief Retrieves the Nth student from the end of the linked list.
 * 
 * @param head Pointer to the head of the linked list.
 * @param nth Index of the student to retrieve.
 * @return Pointer to the Nth student from the end, or NULL if not found.
 */
struct Student_t* get_NthStudent_End(struct Student_t* head, unsigned int nth);

/**
 * @brief Retrieves the middle student of the linked list.
 * 
 * @param head Pointer to the head of the linked list.
 * @return Pointer to the middle student, or NULL if the list is empty.
 */
struct Student_t* get_MiddleStudent(struct Student_t* head);

/**
 * @brief Reverses the order of students in the linked list.
 * 
 * @param head Pointer to a pointer to the head of the linked list.
 */
void reverseStudentsList(struct Student_t** head);

/**
 * @brief Detects if there is a loop in the linked list.
 * 
 * @param head Pointer to the head of the linked list.
 * @return 1 if a loop is detected, 0 otherwise.
 */
char loopDetection(struct Student_t* head);

/**
 * @brief Deletes all students from the linked list.
 * 
 * This function deletes all students from the linked list starting from the head
 * node and frees the memory allocated for each student.
 * 
 * @param head Pointer to the head of the linked list of students.
 */
void deleteAllStudents(struct Student_t* head);