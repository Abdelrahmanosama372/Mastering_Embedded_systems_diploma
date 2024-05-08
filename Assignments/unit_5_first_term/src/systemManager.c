
#include "../include/systemManager.h"

// -------------------- Global Variables --------------------
unsigned int G_CourseID;


// -------------------- Helper Functions Declaration --------------------
void get_data(char*message, void *data, Student_Info_t property);

void set_dataFromRecord(char *record, char *firstName, char *lastName, unsigned int *payroll, 
                        float *GPA, unsigned int *courses_number, unsigned int *coursesId);

FIFO_Status_t check_PayrollExsists(SystemManager_t *sysManager, unsigned int payroll);



// -------------------- APIs Implementation --------------------
void SystemManager_Init(SystemManager_t *sysManager){
    FIFO_Init(&(sysManager->students_fifo));
}

SystemManager_Status_t SystemManager_addStudent(SystemManager_t *sysManager){

    char firstName[NAME_LEN];
    char lastName[NAME_LEN];
    unsigned int payroll, courses_number;
    float student_GPA; 
    unsigned int coursesId[10];

    printf("Add the Student Details\n");
    printf("-------------------------\n");
    get_data("Enter the payroll of the student: ", &payroll, PAYROLL);
    get_data("Enter the first name of the student: ", firstName, FIRSTNAME);
    get_data("Enter the last name of the student: ", lastName, LASTNAME);
    get_data("Enter the GPA grade of the student: ", &student_GPA, GPA);
    get_data("Enter the Number of courses Registered: ", &courses_number, COURSESNUMBER);

    if(courses_number > COURSES_MAX_NUM)
        courses_number = COURSES_MAX_NUM;
    if(courses_number > 0){
        coursesId[0] = courses_number; //transfer courses number to get_data()
        get_data("Enter the student courses id:\n",coursesId, COURSEIDS);
    }
    
    if(check_PayrollExsists(sysManager, payroll) == FIFO_STUDENT_EXIST){
        printf("\033[31m[ERROR] Roll Number %d is already taken\033[0m\n",payroll);
        return SYS_STUDENT_IS_NOT_ADDED;
    }

    if(add_student(&(sysManager->students_fifo),firstName,lastName,payroll,student_GPA,coursesId,courses_number) == FIFO_FULL){
        display("Can't add another Student -> the FIFO is full",ERROR); 
        return SYS_STUDENT_IS_NOT_ADDED;
    }
    
    display("Student is added successfully",SUCCESS); 
    return SYS_STUDENT_IS_ADDED;
}

SystemManager_Status_t SystemManager_addStudentFromFile(SystemManager_t *sysManager, const char *fileName){
    fileManager fm;
    if(fileManager_Init(&fm, fileName) == FILE_NOT_OPENED){
        display("Error opening the file",ERROR);
        return SYS_STUDENT_IS_NOT_ADDED;
    }
    
    char firstName[NAME_LEN];
    char lastName[NAME_LEN];
    unsigned int payroll, courses_number;
    float GPA; 
    unsigned int coursesId[10];

    while (fileManager_hasNext(&fm) == FILE_HAS_NEXT)
    {
        char record[MAX_RECORD_SIZE];
        fileManager_getNextRecord(&fm, record);
        set_dataFromRecord(record, firstName, lastName, &payroll, &GPA, &courses_number, coursesId);
        if(check_PayrollExsists(sysManager, payroll) == FIFO_STUDENT_EXIST){
            printf("\033[31m[ERROR] Roll Number %d is already taken\033[0m\n",payroll);
            continue;
        }
        // to do handle errors here
        add_student(&(sysManager->students_fifo),firstName, lastName, payroll, GPA, coursesId, courses_number); 
        printf("\033[32m[SUCCESS] Student %s with payroll %d is added successfully\033[0m\n",firstName,payroll);
    }
    return SYS_STUDENT_IS_ADDED;
}

Student_t* SystemManager_findStudent(SystemManager_t *sysManager, Student_Info_t property, Student_t *start_from_student){
    Student_t *student;
    FIFO_Status_t status = FIFO_STUDENT_NOT_EXIST;
    if(property == FIRSTNAME){
        char firstName[NAME_LEN];
        get_data("Enter the first name of the student: ", firstName, property);
        status = find_student(&(sysManager->students_fifo), &student, search_with_firstName, &firstName, start_from_student);
    }else if(property == PAYROLL) {
        unsigned int payroll;
        get_data("Enter the payroll of the student: ", &payroll, property);
        status = find_student(&(sysManager->students_fifo), &student, search_with_payroll, &payroll, start_from_student);
    }else if(property == COURSEID) {
        unsigned int courseId;
        if(start_from_student == NULL){
            get_data("Enter the Course ID: ", &courseId, property);
            G_CourseID = courseId;
        }else {
            courseId = G_CourseID;
        }
        status = find_student(&(sysManager->students_fifo), &student, search_with_courseId, &courseId, start_from_student);
    }
    if(status == FIFO_STUDENT_EXIST)
        return student;
    return NULL;
}

SystemManager_Status_t SystemManager_updateStudentInfo(SystemManager_t *sysManager, Student_Info_t info){

    Student_t *student = SystemManager_findStudent(sysManager,PAYROLL,NULL);
    if(student == NULL)
        return SYS_STUDENT_NOT_EXISTS;

    switch (info)
    {
        case PAYROLL:
            unsigned int payroll;
            get_data("Enter the student new payroll: ",&payroll, PAYROLL);
            set_payRoll(student,payroll);
            break;

        case FIRSTNAME:
            char firstName[NAME_LEN];
            get_data("Enter the student new first name: ",firstName, FIRSTNAME);
            set_firstName(student,firstName);
            break;

        case LASTNAME:
            char lastName[NAME_LEN];
            get_data("Enter the student new last name: ",lastName, LASTNAME);
            set_lastName(student,lastName);
            break;

        case GPA:
            float student_GPA;
            get_data("Enter the student new GPA: ",&student_GPA, GPA);
            set_GPA(student,student_GPA);
            break;

        case COURSEID:
            unsigned int courses_number;
            get_data("Enter the student new courses number: ",&courses_number, COURSESNUMBER);
            unsigned int coursesId[COURSES_MAX_NUM];
            coursesId[0] = courses_number;
            get_data("Enter the student new courses id: ",coursesId, COURSEIDS);
            set_coursesID(student,coursesId,courses_number);
            break;
    }
    return SYS_STUDENT_INFO_IS_UPDATED;
}

SystemManager_Status_t SystemManager_deleteStudent(SystemManager_t *sysManager){ 
    unsigned int payroll;
    get_data("Enter the payroll of the student: ", &payroll, PAYROLL);
    if(delete_student(&(sysManager->students_fifo),search_with_payroll,&payroll) == FIFO_STUDENT_DELETED)
        return SYS_STUDENT_IS_DELETED;
    return SYS_STUDENT_NOT_EXISTS;
}

unsigned int SystemManager_getStudentsCount(SystemManager_t *sysManager){
    return sysManager->students_fifo.count;
}

void SystemManager_displayAllStudents(SystemManager_t *sysManager){
    unsigned int i;
    display_fifo(&(sysManager->students_fifo));
}

void SystemManager_displayStudent(SystemManager_t *sysManager, Student_t* student){
    display_student(student);
}

void display(char *messsage, Display_Status_t status){
    if(status == ERROR)
        printf("\033[31m[ERROR] %s\033[0m\n",messsage);
    else if(status == SUCCESS)
        printf("\033[32m[SUCCESS] %s\033[0m\n",messsage);
    else // WARNING
        printf("\033[33m[WARNING] %s\033[0m\n",messsage);
}

// -------------------- Search APIs Implementation --------------------
FIFO_Status_t search_with_firstName(Student_t *student, void *name){
    if(strcmp(student->firstName,(char*)name) == 0)
        return FIFO_STUDENT_EXIST;
    return FIFO_STUDENT_NOT_EXIST;
}

FIFO_Status_t search_with_payroll(Student_t *student, void *payroll){
    if(student->payroll == *((int*)payroll))
        return FIFO_STUDENT_EXIST;
    return FIFO_STUDENT_NOT_EXIST;
}

FIFO_Status_t search_with_courseId(Student_t *student, void *courseId){
    int i;
    for(i=0; i<student->courses_number; i++){
        if(*((int*)courseId) == student->coursesId[i])
            return FIFO_STUDENT_EXIST;
    }
    return FIFO_STUDENT_NOT_EXIST;
}



// -------------------- Helper Functions Implementation --------------------

void get_data(char*message, void *data, Student_Info_t property){
    printf("%s",message);

    if(property == FIRSTNAME || property == LASTNAME){
        fflush(stdin);
        scanf("%s", (char*)data);
    }
    else if(property == PAYROLL || property == COURSEID || property == COURSESNUMBER){
        scanf("%d", (unsigned int*)data);
    }
    else if(property == GPA){
        scanf("%f", (float*)data);
    }
    else if(property == COURSEIDS) {
        int courses_number = ((int*)data)[0];
        int i;
        for (i = 0; i < courses_number; i++){
            printf("course id: ");
            scanf(" %d", ((int*)data)+i);
        }
        
    }
}

void set_dataFromRecord(char *record, char *firstName, char *lastName, unsigned int *payroll, 
                        float *GPA, unsigned int *courses_number, unsigned int *coursesId){
    
    char *token = strtok(record," ");
    *payroll = atoi(token);
    
    token = strtok(NULL, " ");
    strcpy(firstName,token);

    token = strtok(NULL, " ");
    strcpy(lastName,token);

    token = strtok(NULL, " ");
    *GPA = atof(token);

    token = strtok(NULL, " ");
    *courses_number = atoi(token);

    int i;
    for (i=0; i < *courses_number; i++)
    {
        token = strtok(NULL, " ");
        coursesId[i] = atoi(token);
    }
    
    
}

FIFO_Status_t check_PayrollExsists(SystemManager_t *sysManager, unsigned int payroll){
    Student_t *student = NULL;
    return find_student(&(sysManager->students_fifo),&student,search_with_payroll,&payroll,NULL);    
}