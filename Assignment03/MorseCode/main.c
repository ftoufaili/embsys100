#include <stdio.h>
#include <stdbool.h>
#include "morseCode.h"

#define RCC_BASE 0x40021000     // RCC Base
#define GPIOA_BASE 0x48000000    //GPIOA Base


#define RCC_AHB2ENR  (*((unsigned int*) (RCC_BASE + 0x4C)))     // RCC_AHB2ENR: Enable clock to GPIOA
#define GPIO_MODER   (*((unsigned int*)(GPIOA_BASE + 0x0)))              
#define GPIOx_ODR     (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define ORD5  (1 << 5)  // for setting the 5th bit in the GPIOx_ORD to toggle 


const unsigned int  DOT_LENGTH_1U                        = 1;
const unsigned int  DASH_LENGTH_3U                       = 3;
const unsigned int  DELAY_BETWEEN_PARTS_LENGTH_1U        = 1;
const unsigned int  DELAY_BETWEEN_LETTERS_LENGTH_3U      = 3;
const unsigned int  DELAY_BETWEEN_WORDS_LENGTH_7U        = 7;


volatile int counter = 0;

/*
 * Function:  Delay 
 * --------------------
 * Delays the execution of the next instruction by using a simple counter
 *
 *  seconds: how long delay in seconds (note: it is not very accurate measure
 *  of seconds but close enough estimation
 *
 *  returns: none
 */
void Delay( unsigned int seconds)
{
    unsigned counter = 0;
    
    while( counter < 150000*seconds )
      {     
            counter++;
      }  
}

/*
 * Function:  Init 
 * --------------------
 * Initialize the hardware registers to enable the clock and GPIO moder 
 * so we can turn the LED On and OFF
 *
 *  Parameters: none
 *
 *  returns: none
 */
void Init()
{
    // RCC_AHB2ENR: Enable clock to GPIOA
    RCC_AHB2ENR |= 0x1; 
   
    // Set bits 10 and 11 to 1 and 0 respectively to enable general purpose 
    // output mode (original GPOI Moder value for Port A is 0xABFFFFFF)
    GPIO_MODER &= 0xABFFF7FF; 
}

/*
 * Function:  SetLED 
 * --------------------
 * Turns the LED ON or OFF
 *
 *  turnOn: boolean to determine whether to turn the LED On or Off
 *
 *  returns: none
 */
void SetLED( bool turnOn )
{
    turnOn ? (GPIOx_ODR |= ORD5) : (GPIOx_ODR &= ~ORD5);	
}

/*
 * Function:  DisplayDot 
 * --------------------
 * Displays the "Dot" character in Morse code on the LED
 *
 *  Parameters: none
 *
 *  returns: none
 */
void DisplayDot()
{
    SetLED( 1 );
    Delay ( DOT_LENGTH_1U );
    SetLED( 0 );
}

/*
 * Function:  DisplayDash 
 * --------------------
 * Displays the "Dash" character in Morse code on the LED
 *
 *  Parameters: none
 *
 *  returns: none
 */

void DisplayDash()
{
    SetLED( 1 );
    Delay(DASH_LENGTH_3U);
    SetLED( 0 );
}

/*
 * Function:  EncodeChar
 * --------------------
 * Takes a char and encode it into Morse code then display that code on the LED
 *
 *  char2Encode: The alphanumeric character to encode
 *
 *  returns: none
 */
void EncodeChar( char char2Encode)
{
    if(!char2Encode || char2Encode == '\0') 
        return;
    
    char* code = GetMorseCode(char2Encode);
     
    if (code[0] == '\0') //nothing to do here
        return;
    
    int i = 0; 
    
    while( code[i] != '\0' )
    {
        if (code[i] == '.' )
        {
            DisplayDot();
        }
        else if ( code[i] == ' ' )
        {
            Delay(DELAY_BETWEEN_PARTS_LENGTH_1U);
        }
        else if ( code[i] == '-' )
        {
            DisplayDash();      
        }
        
        ++i;
    }
}

/*
 * Function:  EncodeName
 * --------------------
 * Encodes a string of alph-numeric characters from the ASCII set into
 * their equivalent Morse code then turn the LED ON and OFF to show the 
 * morse code on the LED
 *
 *  _name: string of chars to encode into Morse code
 *
 *  returns: None
 */
void EncodeName(char* _name)
{
    for(int i = 0; _name[i] != '\0'; ++i)
    {
        if (_name[i] == ' ')
        {
            Delay(DELAY_BETWEEN_WORDS_LENGTH_7U);
        }
        else
        {            
            EncodeChar(_name[i]);
                            
            // Reached end of the displaying the Morse code for 
            //one letter so we should add delay of 3 parts 
            Delay(DELAY_BETWEEN_LETTERS_LENGTH_3U);
        }
    }
}

int main()
{
    Init();   
    
    EncodeName("Feras");
    
    return 0;
}