/*
 ============================================================================
 Name        : startup.c
 Author      : Abdelrahman osama
 Description : startup file for Tiva-c Arm-cortex-M4
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

volatile static unsigned long stack_top[256];

extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;


void (* const (vectors[]))(void) __attribute__((section(".vectors")))=   
{                                                        
    (void(*)(void)) (stack_top + sizeof(stack_top)),
    & reset_Handler,
    & NMI_Handler,
    & H_Handler,
    & MM_Handler,
    & Bus_Handler,
    & Usage_Fault_Handler
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