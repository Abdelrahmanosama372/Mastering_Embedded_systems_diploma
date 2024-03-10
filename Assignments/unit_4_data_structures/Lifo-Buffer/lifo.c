#include "lifo.h"


void lifo_push(lifo_buffer_t *lifoBuf, int val){
    if(lifoBuf->count < lifoBuf->length){
         lifoBuf->top++;
        *lifoBuf->top = val;
        lifoBuf->count++;
    }
}

void lifo_pop(lifo_buffer_t *lifoBuf){
    if(lifoBuf->count > 0){
        lifoBuf->count--;
        lifoBuf->top--;
    }
}


int lifo_top(lifo_buffer_t *lifoBuf){
    if(lifoBuf->count > 0)
        return *lifoBuf->top;
    return INT_MIN;
}


char lifo_isempty(lifo_buffer_t *lifoBuf){
    return lifoBuf->count == 0;
}

void lifo_dump(lifo_buffer_t *lifoBuf){
    int i;
    for(i = lifoBuf->count; i > 0 ; i--){
        printf("%d ", *lifoBuf->top);
        lifo_pop(lifoBuf);
    }
}
