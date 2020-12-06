/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file
    EXTERN enable_rcc
    PUBLIC control_user_led1        // Exports symbols to other modules

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
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

GPIOA_BASE  EQU 0x48000000
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x20

control_user_led1
   // Back up the R3-R7 registers and LR
   PUSH      {R3-R5, LR}		// push R3-R7 and LR to stack to save their values since we will be branching later on
   
   MOVS      R4, R0		    // move the first argument (i.e. LED state) in R0 to R4 so we can use R0 
   MOVS      R5, R1		    // move the second argument to R5 (i.e. delay duration) so we can use R1
  
   // call the RCC enable function but load the port in R0 so it can be used in enable_rcc function as the first argument
   MOVS R0, #0
   BL enable_rcc
  
  // Update GPIO_MODER at address 0x48000000 by setting bits 10 and 11 to 1 and 0 respectively to
  // enable general purpose output mode ((*((unsigned int*)(0x48000000))) &= 0xABFFF7FF;) Original GPOIA Moder value is 0xABFFFFFF
  MOVW  R1, #0x0000  // R1 = 0x00000000
  MOVT  R1, #0x4800  // R1 = 0x48000000
  LDR   R2, [R1]  	 // load value at memory address 0x48000000 in R2
  
  // update R0 register value to 0xabfff7ff
  MOVW  R0, #0xf7ff     // Set lower 16-bits of R0 to 0xf7ff) (R0 = 0x0000 f7ff)  
  MOVT  R0, #0xabff     // Set upper 16-bits of R0 to0xabff) R0 = ( (R0 & 0xffff ) | (0xabff << 16) ) R0 now equal 0xabfff7ff
  
  ANDS  R2, R2, R0	  // R2 &= R0
  STR   R2, [R1]	  // Update GPIOA Moder value in memory
  
   // loading the GPIOA->ODR address in register R2 so it can be used to turn LED1 ON or OFF
   MOVW  R2, #0x0014       // (R2 = 0x0000 0014)  
   MOVT  R2, #0x4800       //  R2 = ( (R2 & 0xffff ) | (0x4800 << 16) ) R2 now equal 0x4800'0014
   LDR   R3, [R2]	   // load GPIOA->ODR value pointed to by R2 in R3
   
   // compare the state parameter to see if we are turning the LED on or OFF
   CMP       R4, #1
   BNE.N     TURN_OFF_LED_LABEL	// if not equal, go to TURN_OFF_LED_LABEL label to turn off the LED
    
   // Updating the GPIOA ODR to turn on the LED ON (GPIOA->ODR |= GPIO_ODR_OD5) 
   ORRS.W    R3, R3, #0x20        //GPIOA->ODR |= 0x20
   STR       R3, [R2]			// Store R3 value in address specified by R2 
   BL        EXIT_FUNC_LABEL    // branch to EXIT_FUNC_LABEL
   
TURN_OFF_LED_LABEL:	
   BICS.W    R3, R3, #32         //GPIOA->ODR &= ~GPIO_ODR_OD5
   STR       R3, [R2]

EXIT_FUNC_LABEL:   
   // load the delay duration in R0 before we call the delay function
   MOVS R0, R5
   
   // call the delay function
   BL delay
   
   POP       {R0, R4, R5, PC }
   BX        LR
   MOVS      R0, R0

   END
