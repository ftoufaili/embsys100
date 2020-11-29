**Question 1**\
**a)** In order to swap the pointers, the main function has to pass the **address of the pointers** so that the swap function can swap the pointers variables and not the values that they point to. 

**b)** When SwapPointer function is called, R0 and R1 register values hold the **addresses** of the xPtr and yPtr respectively as can be seen in image below.

![R0 and R1 values before calling the swap function](https://github.com/ftoufaili/embsys310/blob/main/Assignment05/Images/Before.jpg)

**c)** The snapshot below shows the the local variables inside of main after returning from the SwapPointer function. As illustrated in the output, the pointers are swapped but not the values they point to. 

![Local varaible after returning to main](https://github.com/ftoufaili/embsys310/blob/main/Assignment05/Images/After.jpg)


<br/>**Question 2**\
**a)** The calling function func2 passes the values to the called function func1 by loading the value of these values in R0 through R3 registers as captured in the image below. Since we're passing more varaibles that registers R0 through R3 can hold, the 5th value was stored in memory that is pointed to by the Stack Pointer SP as can be seen in the image below.\
**b)** Before calling the function func1 with multiple arguments, the compiler created extra code to update the link register before calling Branch to Label (i.e. BL) instruction to change the value of the PC register.

**c)** With the multiple list of arguments, the compiler generated code to retrieve the 5th argument value that is stored in the SP register before adding all the values
