**Question 1**\
**a)** When using bit banding, the compiler produces 3 instructions as follows:\
*i)* first instruction to load the value (i.e. 1) into R0\
*ii)* decond instruction for loading the targeted register *address value* into R1\
*iii)* third instruction for writing/storing the value in R0 (i.e. 1) directly to the address pointed to by R1

<br/>**b)** When writing to the register without using bit banding, the compiler produced 4 instructions as follows:\
*i)* first instruction to load the targeted register address into R0\
*ii)* second instruction for loading the value pointed to by the R0 address into R1 register\
*iii)* third instruction for performing the OR operation and updating the R1 register with the new value\
*iv)* fourth instruction for writing/storing the value in R1 into the address pointed to by R0. 

The described instructions above are captured in the image below:
![Bit Banding Vs No Bit Banding](https://github.com/ftoufaili/embsys310/blob/main/Assignment04/Images/BitBandingVsNoBitBanding.jpg)


**Question 2**
