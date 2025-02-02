**Question 1**\
**a)** The new value of the "counter" variable from the "Locals" window is decimal -2147483648\
**b)** The new value of the "counter" varial from the "Registers" window is Hex 0x80000000\
**c)** Both N and V flags are set to 1 to indicate that the result of the previous operation is negative and there's an overflow respectively. The N flag is set because the result is negative (N is set to the two's complement sign bit of the result i.e. bit 31). The V flag is set when the result of an signed operation overflows the 32-bit result register. Since 0x7fffffff is the largest positive two's complement integer that can be represented in 32 bits, 0x7fffffff + 0x00000001 triggers a signed overflow, but not an unsigned overflow (or carry).


<br/>**Question 2**\
**a)** When counter is increamented by 1 after setting its value to 0xffffffff, the new value of counter in the Locals window is 0x00000000 (Hex) or 0 decimal. This is because 0xffffffff is -1 decimal from two's complement signed-arithmetic viewpoint\
**b)** The N and V flags are set to 0 since the previous operation didn't result in a negative number or overflow. The result of the operation is 0x100000000, but the top bit is lost because it does not fit into the 32-bit destination register and so the real result is 0x00000000.


<br/>**Question 3**\
**a)** After changing the counter type to unsigned int and injecting 0x7fffffff value in that variable, once the counter variable is incremented by 1, its new value is now 0x80000000\
**b)** Both N & V bits are set to 1 since N bit is set to represent the two's complement sign bit of the result (i.e. bit 31). The V bit is also set to 1 since this bit is based on signed operations. Since 0x7fffffff is the largest positive two's complement integer that can be represented in 32 bits, adding 1 to 0x7fffffff will trigger a signed overflow.


<br/>**Question 4**\
**a)** After changing the counter type to unsigned int and injecting 0xffffffff value in that variable, once the counter variable is incremented by 1, its new value is now 0x00000000\
**b)** Both N & V bits are set to 0 after incrementing the counter by 1. The N bit is set to 0 because 0xffffffff represents -1 in two's complement so adding 1 to it results in 0x00000000, which is not a negative number. Similarly, the V bit is set to zero since there's no signed carry in the two's complement operation.


<br/>**Question 5**\
**a)** When counter variable is defined outside of main, it's scope is now global and it is saved in data segment (i.e. SRAM) instead of the code segment.\
**b)** The counter variable is not visible in the "Locals" view anymore since it is stored in a different memory (i.e. data segment in RAM)\
**c)** Global variables including counter can be viewed in the "Memory" window.\
**d)** The address of the counter variable in memory is 0x20000000


<br/>**Question 6**\
**a)** The value of "counter" is 0x0004 at the end of the program.\
**b)** The counter value was changed because the ++(*p_int) instruction will increment the dereferenced value of counter, which is pointed to by the p_int pointer by 1. This operation is repeated 3 times, which results in counter value to become 3. The last instruction before the return statement increment the counter value directly again by 1, which results in 4 (i.e. 3 + 1 = 4)


<br/>**Question 7**\
**a)** "counter" is stored at address 0x20000000.\
**b)** counter variable is defined as a global variable so it is stored in RAM.\
**c)** Similar to the previous question, th evalue of "counter" at the end of the program is 4.
