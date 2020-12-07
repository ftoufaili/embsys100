**Question 2**\
**a)** Total ROM the program is using is 390(for code) + 82(for data) =  472 bytes
<br/>**b)** Total RAM program is using is 8,192 bytes
<br/>**c)** The (.o) object files are occupying the majority of the used ROM
<br/>**d)** The "Linker Created" part of the program is using the majority of the RAM, which is result of the creation of the stack for the program

**Question 3**\
Some consideration for optimizing the usage of ROM or RAM resources:\
1- Reduce the Stack size so less RAM can be occupied\
2- If possible, reduce the usage of constants in the program to reduce the ROM consumption\
3- If possible, reduce the number of source files so less ROM will be needed for the object files\
4- Reduce any unecessary code/comments/debugging information to reduce the size of the object and binary files\
5- Use 16-bit Thumb mode vs the 32-bit arm mode\
6- If available and desired, enable the garbage collect option to minimize the ROM and RAM usage but the build image\
7- Comment out any code related to hardware features that are not needed for the embedded device.
