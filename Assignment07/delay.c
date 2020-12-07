#include "delay.h"

extern int g_sysTickCount;

void delay(int milliSecondDelay)
{
    g_sysTickCount = milliSecondDelay;
  
    while (g_sysTickCount > 0)
    {
        //wait until the milliseconds count end
    }
}