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
// (0x42000000+(0x2104C *32) + (0*4))) = 0x1;
// bit_band_base = 0x42000000 
// bit_offset = 0x2104c
// bit_number = 0 
// bit_word_address = 0x42000000 + (0x2104C*32) + (0*4) = 0x42420994
 
enable_rcc

   MOV R1, #4           // Store 4 in R1
   MUL R0, R0, R1       // multiple the port number (stored in R0) by 4 (stored in R1) and store the result in R0
   
   // Set the value of the R1 register to 0x42420980 (= 0x42000000+(0x2104C *32)) 
   MOVW  R1, #0x0980    // Set the lower 16-bits of R1 to 0x0x0980 (R1 = 0x0000'0980)  
   MOVT  R1, #0x4242    // Set the upper 16-bits of R1 to 0x4242  ( (R1 & 0xffff ) | (0x4242 << 16) ) R1 now equal 0x4242'0980
   
   ADD R0, R0, R1      // Add the port number stored in R0 to R1 and store result back in R0
  
   MOV R2, #0x1        // Store 0x01 in R2

   STR R2, [R0]        // Set the value of the address pointed to by R0 to 0x01 
   
   BX        LR        // Return
   
   END
