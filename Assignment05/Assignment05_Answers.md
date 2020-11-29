**Question 1**\
**a)** In order to swap the pointers, the main function has to pass the **address of the pointers** so that the swap function can swap the pointers variables and not the values that they point to. 

**b)** When SwapPointer function is called, R0 and R1 register values hold the **addresses** of the xPtr and yPtr respectively as can be seen in image below.

![R0 and R1 values before calling the swap function](https://github.com/ftoufaili/embsys310/blob/main/Assignment05/Images/Before.jpg)

**c)** The snapshot below shows the the local variables inside of main after returning from the SwapPointer function. As illustrated in the output, the pointers are swapped but not the values they point to. 

![Local varaible after returning to main](https://github.com/ftoufaili/embsys310/blob/main/Assignment05/Images/After.jpg)

