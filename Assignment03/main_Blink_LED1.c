#if 1

#define RCC_BASE 0x40021000     // RCC Base
#define GPIOA_BASE 0x48000000    //GPIOA Base


#define RCC_AHB2ENR  (*((unsigned int*) (RCC_BASE + 0x4C)))             // RCC_AHB2ENR: Enable clock to GPIOA
#define GPIO_MODER   (*((unsigned int*)(GPIOA_BASE + 0x0)))             // 
#define GPIOx_ODR     (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define ORD5  (1 << 5)  // for setting the 5th bit in the GPIOx_ORD to toggle LED1

volatile int counter = 0;

int main()
{
    // RCC_AHB2ENR: Enable clock to GPIOA
    RCC_AHB2ENR |= 0x1; 
  
 
    // Set bits 10 and 11 to 1 and 0 respectively to enable general purpose 
    // output mode (original GPOI Moder value for Port A is 0xABFFFFFF)
    GPIO_MODER &= 0xABFFF7FF;   
  
      while(1)
      {     
          counter = 0; 
          
          while( counter < 200000 )
          {     
                counter++;
          } 
                
          // Toggle LED1 bit 5 using XOR logic
          GPIOx_ODR ^= ORD5;      
      }
      
      return 0;
}
#endif