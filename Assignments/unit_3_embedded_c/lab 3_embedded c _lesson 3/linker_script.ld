/*
 ============================================================================
 Name        : linker_script.ld
 Author      : Abdelrahman osama
 Description : linker_script file for Stm32f103CX Arm-cortex-M3
 ============================================================================
 */

 MEMORY
 {
    flash(RX)  : ORIGIN = 0x08000000 , LENGTH = 128K
    Sram (RWX) : ORIGIN = 0x20000000 , LENGTH = 20K
 }

 SECTIONS
 {

 .text : 
 {
    *(.vectors)           
    *(.text)
    *(.rodata)
    . = ALIGN(4) ;
    _E_text = . ;
 }> flash

 .data :
 {  
    _S_data = . ;
    *(.data)
    . = ALIGN(4) ;
    _E_data = . ;

 }> Sram AT> flash

 .bss :
 {
    _S_bss = . ;
    *(.bss)
    . = ALIGN(4) ;
    _E_bss = . ;
    . = . + 0x1000;
    _stack_top = .;
 } > Sram 

 }