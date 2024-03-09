#include "fifo.h"

void fifo_set(fifo_buffer_t *fifoBuf,int *arr, unsigned int length){
    fifoBuf->head = arr;
    fifoBuf->tail = arr;
    fifoBuf->arr = arr;
    fifoBuf->length = length;
    fifoBuf->count = 0;
}

void fifo_enqueue(fifo_buffer_t *fifoBuf, int val){
    if(fifoBuf->count == fifoBuf->length)
        return;
    *fifoBuf->head = val;
    fifoBuf->count++;
    if(fifoBuf->head == fifoBuf->arr + fifoBuf->length -1)
        fifoBuf->head = fifoBuf->arr;
    else
        fifoBuf->head++;
}

int fifo_dequeue(fifo_buffer_t *fifoBuf){
    int ret_val;

    if(fifoBuf->count == 0)
        return INT_MIN;

    ret_val = *fifoBuf->tail;
    if(fifoBuf->tail == fifoBuf->arr + fifoBuf->length -1)
        fifoBuf->tail = fifoBuf->arr;
    else
        fifoBuf->tail++;
    fifoBuf->count--;

    return ret_val;
}

char fifo_isempty(fifo_buffer_t *fifoBuf){
    return fifoBuf->count == 0;
}

unsigned int fifo_getCount(fifo_buffer_t *fifoBuf){
    return fifoBuf->count;
}   

void fifo_dump(fifo_buffer_t *fifoBuf){
    int num = fifoBuf->count;
    for(int i=0; i < num; i++){
        printf("%d ",fifo_dequeue(fifoBuf)); 
    }
    printf("\n");
}
