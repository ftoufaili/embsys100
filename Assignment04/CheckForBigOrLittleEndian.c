int main()
{
   unsigned int num = 0x0001;
   
   char *lsb = (char *) &num;
   
   int isLittleEndian = lsb[0]; 
   
   return isLittleEndian; 
}
