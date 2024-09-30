#include "../include/fileManager.h"


fileManager_Status_t fileManager_Init(fileManager *fm, const char *filepath){
    fm->fptr = fopen(filepath,"r");
    if(fm->fptr == NULL)
        return FILE_NOT_OPENED;
    return FILE_OPENED;
}
void fileManager_getNextRecord(fileManager *fm, char *record){
    fgets(record,MAX_RECORD_SIZE,fm->fptr);
}

fileManager_Status_t fileManager_hasNext(fileManager *fm){
    if(feof(fm->fptr))
        return FILE_EOF;
    return FILE_HAS_NEXT;
}

fileManager_Status_t fileManager_closeFile(fileManager *fm){
    if(!fclose(fm->fptr))
        return FILE_CLOSED;
    return FILE_NOT_CLOSED;
}
