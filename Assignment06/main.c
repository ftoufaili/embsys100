#include <stdint.h>

#define LED_ON 1
#define LED_OFF 0
#define DELAY_DURATION 100000

void control_user_led1(uint8_t state, uint32_t duration);

void main(void)
{    
    while(1)
    {
        control_user_led1(LED_ON, DELAY_DURATION);
        control_user_led1(LED_OFF, DELAY_DURATION);
    }
}
