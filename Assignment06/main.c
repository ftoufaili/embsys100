#include "stm32l475xx.h"

int main()
{  
   // Enable RCC clock to GPIOA
   RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
      
  // Set bits 10 and 11 to 1 and 0 to enable general purpose 
  // output mode
  GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
  GPIOA->MODER |= GPIO_MODER_MODE5_0;
  
  int counter = 0;
  
  while(1)
      {     
          counter = 0; 
          
          while( counter < 40000 )
          {     
                counter++;
          } 
                
          // Toggle ODR LED1 bit 5 using XOR logic
          GPIOA->ODR ^= GPIO_ODR_OD5;
      }     
  
  return 0;
}
