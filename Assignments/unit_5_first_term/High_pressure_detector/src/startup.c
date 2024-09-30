
extern void main(void);
extern unsigned int stack_top;
extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void reset_handler(void);
void NMI_HANDLER(void)__attribute__( (weak , alias("Default_Handler")));
void H_FAULT_HANDLER(void) __attribute__( (weak , alias("Default_Handler")));
void MM_FAULT_HANDLER(void) __attribute__( (weak , alias("Default_Handler")));
void BUS_FAULT(void) __attribute__( (weak , alias("Default_Handler")));
void USAGE_FAULT(void) __attribute__( (weak , alias("Default_Handler")));

//vector table
unsigned int vector_table[] __attribute__((section(".vectors"))) = {
    (unsigned int)&stack_top,
    (unsigned int)&reset_handler,
    (unsigned int)&NMI_HANDLER,
    (unsigned int)&H_FAULT_HANDLER,
    (unsigned int)&MM_FAULT_HANDLER,
    (unsigned int)&BUS_FAULT,
    (unsigned int)&USAGE_FAULT,
};

void reset_handler(void)
{
    //copy data section from flash to ram
    //.data section
    unsigned char *ptr_src = (unsigned char*)&_S_data;
    unsigned char *ptr_dest = (unsigned char*)&_E_data;
    unsigned int size = (unsigned char * )&_E_data - (unsigned char * )&_S_data;

    unsigned int i;

    for(i=0;i<size;i++)
    {
        *(ptr_dest++) = *(ptr_src++);
    }

    //initialize .bss section with 0
    size = (unsigned char * )&_E_bss - (unsigned char * )&_S_bss;
    ptr_dest = (unsigned char*)&_S_bss;
    for(i=0;i<size;i++)
    {
        *(ptr_dest++) = (unsigned char)0;
    }

    main();
}

void Default_Handler(void)
{
    reset_handler();
}