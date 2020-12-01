/*******************************************************************************
File name       : rcc_ctrl.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    PUBLIC enable_rcc        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : enable_rcc
Description     : - Uses Bit-Band registers at base 0x4200.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void enable_rcc(uint32_t port)
                : Where port indicates wich port to enable the clock for
Parameters      : R0: uint32_t port

Return value    : None
*******************************************************************************/  

// Bitband address calculation formula
// (0x42000000+(0x2104C *32) + (1*4))) = 0x1;

enable_rcc
   
   MOVS R2, R0        //store the port number in R2
   
   MOVS R3, #1       // load 0x01 in R3
   LSLS R3, R3, R2   // left shift the value in R3 (i.e. 0x01) by the port number argument stored in R2
   
   //Enable RCC for GPIOA by setting bit 0 of memory pointed to by address 0x4002 104c to 0x01
   MOVW  R1, #4172    // (#4172 = 0x104c) load the lower 16-bits of the bit-band address in R1 (R1 = 0x0000 104c)  
   MOVT  R1, #16386    // (#16386 = 0x4002) load the upper 16-bits of the bit-band address in R1 ( (R1 & 0xffff ) | (0x4002 << 16) ) R1 now equal 0x4002 104c
   
   STR       R3, [R1] 	// store the R3 value in memory address pointed to by R1 (i.e. the bit-band address) *((uint32_t*)(0x42420994)) = 0x1;

   BX        LR           // Return
   
   END
