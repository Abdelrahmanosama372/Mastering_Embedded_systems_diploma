#ifndef FILE_MANAGER_H_
#define FILE_MANAGER_H_

#include <stdio.h>
#define MAX_RECORD_SIZE 100

typedef struct 
{
    FILE *fptr;
}fileManager;

typedef enum {
    FILE_OPENED,
    FILE_NOT_OPENED,
    FILE_HAS_NEXT,
    FILE_EOF,
    FILE_CLOSED,
    FILE_NOT_CLOSED
}fileManager_Status_t;

fileManager_Status_t fileManager_Init(fileManager *fm, const char *filepath);
void fileManager_getNextRecord(fileManager *fm, char *record);
fileManager_Status_t fileManager_hasNext(fileManager *fm);
fileManager_Status_t fileManager_closeFile(fileManager *fm);


#endif /* FILE_MANAGER_H_ */