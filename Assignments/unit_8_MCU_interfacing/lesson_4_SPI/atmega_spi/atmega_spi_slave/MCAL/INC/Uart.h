/*
 * Uart.h
 *
 * Created: 4/16/2024 8:27:50 AM
 *  Author: Abdelrahman
 */ 

/**
 * @file uart.h
 * @brief UART communication interface
 */

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../HAL/INC/lcd.h"

/**
 * @brief Configuration structure for UART
 */
typedef struct {
    uint8_t data_size;              /**< Data size in bits (5, 6, 7, 8, or 9) */
    uint8_t baudrate;               /**< Baud rate divisor value */
    uint8_t parity_mode;            /**< Parity mode (disabled, even, or odd) */
    uint8_t stop_bits_number;       /**< Number of stop bits (one or two) */
    uint8_t Uart_mode;              /**< UART mode (transmit only, receive only, or both) */
    uint8_t Uart_interrupt_mode;    /**< UART interrupt mode (disabled, transmit complete, receive complete, or both) */
} UART_Config;

/** @name Data size options */
/** @{ */
#define UART_DATA_SIZE_5_BIT           0
#define UART_DATA_SIZE_6_BIT           1
#define UART_DATA_SIZE_7_BIT           2
#define UART_DATA_SIZE_8_BIT           3
#define UART_DATA_SIZE_9_BIT           3 /**< Bit U2X is set for this data size */
/** @} */

/** @name Baud rate options */
/** @{ */
#define UART_BAUDRATE_2400             207
#define UART_BAUDRATE_4800             103
#define UART_BAUDRATE_9600             51
#define UART_BAUDRATE_19200            25
#define UART_BAUDRATE_38400            12
/** @} */

/** @name Parity options */
/** @{ */
#define UART_PARITY_DISABLED           0
#define UART_PARITY_EVEN_PARITY        2
#define UART_PARITY_ODD_PARITY         3
/** @} */

/** @name Stop bits options */
/** @{ */
#define UART_STOP_BIT_ONE_BIT          0
#define UART_STOP_BIT_TWO_BIT          1
/** @} */

/** @name UART mode options */
/** @{ */
#define UART_MODE_Tx_ONLY              1
#define UART_MODE_RX_ONLY              2
#define UART_MODE_Tx_AND_RX            3
/** @} */

/** @name UART interrupt mode options */
/** @{ */
#define UART_INTERRUPT_DISABLE         0
#define UART_INTERRUPT_TXC             1
#define UART_INTERRUPT_RXC             2
#define UART_INTERRUPT_RXC_AND_TXC     3
/** @} */

/**
 * @brief Initialize UART with given configuration
 * @param config Pointer to the configuration structure
 */
void Uart_init(UART_Config *config);

/**
 * @brief Send a single character via UART
 * @param data The character to be sent
 */
void Uart_send_char(uint8_t data);

/**
 * @brief Send a string of characters via UART
 * @param str Pointer to the string
 * @param size Size of the string
 */
void Uart_send_string(uint8_t* str, uint32_t size);

/**
 * @brief Receive a single character via UART
 * @return The received character
 */
uint8_t Uart_receive_char();

/**
 * @brief Receive a string of characters via UART
 * @param str Pointer to the buffer to store the received string
 * @param size Size of the buffer
 */
void Uart_receive_string(uint8_t* str, uint32_t size);

/**
 * @brief Send data asynchronously via UART with interrupts enabled
 * @param data Pointer to the data to be sent
 * @param size Size of the data
 */
void Uart_send_async(uint8_t* data, uint32_t size);

/**
 * @brief Receive data asynchronously via UART with interrupts enabled
 * @param data Pointer to the buffer to store the received data
 */
void Uart_receive_async(uint8_t* data);

#endif /* UART_H_ */
