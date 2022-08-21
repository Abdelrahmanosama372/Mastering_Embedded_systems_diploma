/*
 ============================================================================
 Name        : startup.c
 Author      : Abdelrahman osama
 Description : startup file for Stm32f103CX Arm-cortex-M3
 ============================================================================
 */

#include <stdint.h>

void reset_Handler(void);
void Default_Handler();

void NMI_Handler (void)__attribute__((weak,alias("Default_Handler")));
void H_Handler (void)__attribute__((weak,alias("Default_Handler")));
void MM_Handler (void)__attribute__((weak,alias("Default_Handler")));
void Bus_Handler (void)__attribute__((weak,alias("Default_Handler")));
void Usage_Fault_Handler (void)__attribute__((weak,alias("Default_Handler")));

extern unsigned int _stack_top;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;


uint32_t vectors[] __attribute__((section(".vectors")))=   // to put vectors[] at .vectors section which is in flash
{                                                        // putting sp at begining to be at address 0X08000000
    (uint32_t) & _stack_top,
    (uint32_t) & reset_Handler,
    (uint32_t) & NMI_Handler,
    (uint32_t) & H_Handler,
    (uint32_t) & MM_Handler,
    (uint32_t) & Bus_Handler,
    (uint32_t) & Usage_Fault_Handler
};

void reset_Handler (void)
{
    int i; // for loop counter

    // copy data from rom to ram
    unsigned int data_size = (unsigned char *) &_E_data - (unsigned char *) &_S_data;
    unsigned char * ptr_src = (unsigned char *) &_E_text;
    unsigned char * ptr_den = (unsigned char *) &_S_data;
    for ( i = 0; i < data_size; i++)
    {
        *(ptr_den++) = *(ptr_src++);
    }

    // init bss with 0 in ram
    unsigned int bss_size = (unsigned char *) &_E_bss - (unsigned char *) &_S_bss;
    ptr_den = (unsigned char *) &_S_bss;
    for ( i = 0; i < bss_size; i++)
    {
        *(ptr_den++) = (unsigned char) 0;
    }

    // moving to main()
    main();
}

void Default_Handler()
{
    reset_Handler();
}