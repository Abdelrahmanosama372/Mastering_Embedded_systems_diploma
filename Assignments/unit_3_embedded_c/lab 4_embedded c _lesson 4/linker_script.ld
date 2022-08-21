/*
 ============================================================================
 Name        : linker_script.ld
 Author      : Abdelrahman osama
 Description : linker_script file for Tiva-c Arm-cortex-M4
 ============================================================================
 */

 MEMORY
 {
    flash(RX)  : ORIGIN = 0x00000000 , LENGTH = 128K
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
 } > Sram 

 }