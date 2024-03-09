#ifndef _FIFO_H_
#define _FIFO_H_

#include <stdio.h>
#include <limits.h>

typedef struct
{
    int *head;
    int *tail;
    int *arr; 
    unsigned int length;
    unsigned int count;
}fifo_buffer_t;

/**
 * @brief Initializes a FIFO buffer with the given array and length.
 * 
 * @param fifoBuf Pointer to the FIFO buffer structure.
 * @param arr Pointer to the array used as the buffer.
 * @param length Length of the buffer.
 */
void fifo_set(fifo_buffer_t *fifoBuf,int *arr, unsigned int length);

/**
 * @brief Adds a value to the FIFO buffer.
 * 
 * @param fifoBuf Pointer to the FIFO buffer structure.
 * @param val Value to be enqueued.
 */
void fifo_enqueue(fifo_buffer_t *fifoBuf, int val);

/**
 * @brief Removes and returns the value from the front of the FIFO buffer.
 * 
 * @param fifoBuf Pointer to the FIFO buffer structure.
 * @return The value dequeued from the buffer, or INT_MIN if the buffer is empty.
 */
int fifo_dequeue(fifo_buffer_t *fifoBuf);

/**
 * @brief Checks if the FIFO buffer is empty.
 * 
 * @param fifoBuf Pointer to the FIFO buffer structure.
 * @return True if the buffer is empty, false otherwise.
 */
char fifo_isempty(fifo_buffer_t *fifoBuf);

/**
 * @brief Retrieves the current count of elements in the FIFO buffer.
 * 
 * @param fifoBuf Pointer to the FIFO buffer structure.
 * @return The current count of elements in the buffer.
 */
unsigned int fifo_getCount(fifo_buffer_t *fifoBuf);

/**
 * @brief Empties the FIFO buffer by dequeuing all elements.
 * 
 * @param fifoBuf Pointer to the FIFO buffer structure.
 */
void fifo_dump(fifo_buffer_t *fifoBuf);

#endif // !_FIFO_H_


