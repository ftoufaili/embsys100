#include <assert.h>

int swapCharsAsm(char* ch1, char* ch2);

int main(void)
{
  char x = 'a';
    char y = 'b';
    
    int retVal = swapCharsAsm(&x, &y); 
    
    assert (x == 'b');
    assert (y == 'a');
    assert (retVal == 1);
    
    x = 'a';
    y = 'a';
    
    retVal = swapCharsAsm(&x, &y); 
    assert (retVal == 0);
  
  return 0;
}

/*******************************************************************************
Function Name   : swapCharAsm
Description     : Assembly function to swap two characters 
C Prototype     : int swapCharAsm(char* ch1, char* ch2)
                : Where ch1 is a pointer ot the first char
                : and ch2 is a pointer to the second char to 
                : be swapped
Parameters      : R0: pointer to first char 
                : R1: pointer to second char
Return value    : R0 (will be 0 if the two chars are identical or 1 otherwise)
*******************************************************************************/ 
int swapCharsAsm(char* ch1, char* ch2)
{
    asm("PUSH {R4}\n"        // Pushes R4 to the stack to save its value since it
                           // will be used later on for the comparison operation
      
      "MOVS R2, R0\n"      // copy the pointer value of the first  
                           // argument (that is loaded in R0) into R2
      
      // copy the value of the first char to R3
      "LDRB R3, [R2]\n"    // Load 1 byte (i.e. char) from the value that is 
                           //pointed by the pointer address in R2 into R3
      
      //Assign the pointer of the first argument to point to the second argument  
      "LDRB R0, [R1]\n"    // Load LSB (i.e. 1 byte) from the value that is 
                           // pointed to by the second argurement pointer 
                           // (that is loaded in R1) into R0
      "STRB R0, [R2]\n"    // Store the LSB from R0 and store it at the address 
                           // specified by R2
        
      //Assign the pointer to the second argument to point to the first argument
      "STRB R3, [R1]\n"   // Store the LSB from R3 and store it at the address 
                          // specified by R2
       
      //Compare the two characters
      "LDRB R0, [R2]\n"   // Load LSB from the value that is pointed to [R2] 
                          // into into R0
      "LDRB R4, [R1]\n"   // Load LSB from the value that is pointed to [R1] 
                          // into into R4
      "CMP R0, R4\n"      // compare the values of R0 and R4
      "BNE.N ResultNotEQLabel\n" // branch to ResultNotEQ label 
      "MOVS R0, #0\n"     // put 0 in R0 (i.e. function return register) 
                          // if results are equal
      "B ExitLabel\n"     // Go to ExitLabel   
              
"ResultNotEQLabel:\n"     // label
      "MOVS R0, #1\n"     // put 1 in R0 (i.e. function return register) 
                          // if results are not equal  
"ExitLabel:\n"            // exit label
      "POP {R4}\n"        // restore R4 value before existing the function
      "BX LR\n"           // return result in R0     
      "MOVS R0, R0\n"
      );           
}
