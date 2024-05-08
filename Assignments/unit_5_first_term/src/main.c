#include "../include/student.h"
#include "../include/systemManager.h"


#define FILEPATH "/home/abdelrahman/E/github-repos/Mastering_Embedded_systems_diploma/Assignments/unit_5_first_term/src/data"

int main() {

    char choice;
    SystemManager_t sm;
    SystemManager_Init(&sm);
    Student_t *student;

    printf("Welcome to the Student Management System\n");
    while (1)
    {
        printf("----------------------------------------------\n");
        printf("Choose the task that you want to perfrom\n");
        printf("1- Add the student manually\n");
        printf("2- Add the students from text file\n");
        printf("3- Find the student by Roll Number\n");
        printf("4- Find the student by First Name\n");
        printf("5- Find the students by Course Id\n");
        printf("6- Find the Total number of Students\n");
        printf("7- Delete the Student by Roll Number\n");
        printf("8- Update the Student details by Roll Number\n");
        printf("9- show all information\n");
        printf("10- Exit\n");
        printf("Enter your choice: ");

        fflush(stdin);
        scanf(" %d",(int*)(&choice));
        
        switch (choice)
        {
            case 1:
                SystemManager_addStudent(&sm);
                break;
            case 2:
                SystemManager_addStudentFromFile(&sm, FILEPATH);
               break;
            case 3:
                student = SystemManager_findStudent(&sm, PAYROLL, NULL);
                if(student == NULL){
                    display("The student with this payroll doen't Exsist",ERROR);
                    continue;
                }
                SystemManager_displayStudent(&sm,student);
               break;

            case 4:
                student = SystemManager_findStudent(&sm, FIRSTNAME, NULL);
                if(student == NULL){
                    display("The student with this first name doen't Exsist",ERROR);
                    continue;
                }
                SystemManager_displayStudent(&sm,student);  
                break;

            case 5:
                student = SystemManager_findStudent(&sm, COURSEID, NULL);
                while (student != NULL)
                {
                    SystemManager_displayStudent(&sm,student);  
                    student = SystemManager_findStudent(&sm, COURSEID, student + 1);
                }
                break;  
                
            case 6:
                printf("\033[34m[INFO] the number of students is: %d\033[0m\n",SystemManager_getStudentsCount(&sm));
                break;

            case 7:
                SystemManager_deleteStudent(&sm);
                break;

            case 8:
                printf("Enter the Info you want to update:\n");
                printf("1- First name\n");
                printf("2- Last name\n");
                printf("3- PayRoll\n"); // check here
                printf("4- GPA\n");
                printf("5- Courses\n");

                scanf(" %d",(int*)(&choice));
                switch (choice)
                {
                    case 1:
                       SystemManager_updateStudentInfo(&sm,FIRSTNAME);
                        break;

                    case 2:
                        SystemManager_updateStudentInfo(&sm,LASTNAME);
                        break;

                    case 3:
                        SystemManager_updateStudentInfo(&sm,PAYROLL);
                        break;
                    
                    case 4:
                        SystemManager_updateStudentInfo(&sm,GPA);
                        break;
                    
                    case 5:
                        SystemManager_updateStudentInfo(&sm,COURSEID);
                        break;
                }
                break;


            case 9:
                SystemManager_displayAllStudents(&sm);
                break;

            case 10:
                exit(0);
        }
    }
    
    return 0; 
}




