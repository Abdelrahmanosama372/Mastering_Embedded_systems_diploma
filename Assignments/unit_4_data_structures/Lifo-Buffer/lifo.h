#ifndef _LIFO_H_
#define _LIFO_H_

#include <stdio.h>
#include <limits.h>

typedef struct
{
    int *top;
    int *arr; 
    unsigned int length;
    int count;
}lifo_buffer_t;

/**
 * @brief Pushes a value onto the LIFO buffer.
 *
 * @param lifoBuf Pointer to the LIFO buffer.
 * @param val Value to be pushed onto the LIFO buffer.
 */
void lifo_push(lifo_buffer_t *lifoBuf, int val);

/**
 * @brief Pops a value from the LIFO buffer.
 *
 * @param lifoBuf Pointer to the LIFO buffer.
 */
void lifo_pop(lifo_buffer_t *lifoBuf);

/**
 * @brief Returns the top value of the LIFO buffer without removing it.
 *
 * @param lifoBuf Pointer to the LIFO buffer.
 * @return The top value of the LIFO buffer, or INT_MIN if the buffer is empty.
 */
int lifo_top(lifo_buffer_t *lifoBuf);

/**
 * @brief Checks if the LIFO buffer is empty.
 *
 * @param lifoBuf Pointer to the LIFO buffer.
 * @return Returns 1 if the LIFO buffer is empty, 0 otherwise.
 */
char lifo_isempty(lifo_buffer_t *lifoBuf);

/**
 * @brief Prints the contents of the LIFO buffer.
 *
 * @param lifoBuf Pointer to the LIFO buffer.
 */
void lifo_dump(lifo_buffer_t *lifoBuf);

#endif // !_LIFO_H_


