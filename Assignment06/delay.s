/*******************************************************************************
File name       : delay.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    PUBLIC delay         // Exports symbols to other modules

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
Function Name   : delay
Description     : loops until input value reaches 0, then exits

C Prototype     : void delay(uint8_t duration)
                : Where duration indicates the total number of loops.
Parameters      : R0: uint8_t duration
Return value    : None
*******************************************************************************/  
  
delay
      
   B COMPARE    // Go to COMPARE label and execute instructions there

LOOP:                   // Main delay loop LABEL
   SUBS      R0, R0, #1    // Subtract 1 from first argument (i.e. iteration) 
                           // that is located in R0 and put the results in R0
   
COMPARE:                  // LABEL
   CMP       R0, #0       // Compare value in R0 to 0
   BNE.N     LOOP         // Branch to LOOP label if compare results are not equal
   BX        LR           // Return

    END
