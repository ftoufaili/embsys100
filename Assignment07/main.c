#include "delay.h"
#include "stm32l475xx.h"
#include "stm32l4xx_it.h"

#define SYS_CLOCK_HZ 4000u   // Default clock after startup set to 4000 clock 
                             // cycles or 1 millisecond since clock runs at 4 MHz
                             // Section 3.11 in STM32L475 datasheet DS10969

int g_sysTickCount = 0;

void SysTick_Init();

int main()
{  
  // Enable RCC clock to GPIOA
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
      
  // Set bits 10 and 11 to 1 and 0 to enable general purpose 
  // output mode
  GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
  GPIOA->MODER |= GPIO_MODER_MODE5_0;
  
  SysTick_Init();
  
  while(1)
  { 
      
    // Toggle ODR LED1 bit 5 using XOR logic
    GPIOA->ODR ^= GPIO_ODR_OD5;
    
    delay(500); //500 msec delay for each LED state
  }     
}

void SysTick_Init()
{
    SysTick->LOAD = SYS_CLOCK_HZ - 1;       // 0xE000E014 - Counts down to 0.
    SysTick->VAL = 0x0;                     // 0xE000E018 - Clears initial value
    SysTick->CTRL = 0x7;                    // 0xE000E010 - Enable interrupts
}

void SysTick_Handler(void)
{
     __disable_irq();
     
     // decrement the global sysTick count by 1 every 1 milli second
     g_sysTickCount--;
      
    __enable_irq();
}
