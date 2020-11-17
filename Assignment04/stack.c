#include "stack.h"

enum _STACK_SIZE { STACK_SIZE = 128, INIT_VALUE = -1};   // Predefined Stack size of 128 integers
static int Stack[STACK_SIZE];
static int top = -1; 

int InitStack(void)
{
  for( unsigned int num = 0; num < STACK_SIZE; ++num )
  {
    Stack[num] = INIT_VALUE;
  }

  top = -1;
  
  return 1;
}

int Push(int elem)
{
  int retVal = 0;
  
  if ( top >= STACK_SIZE - 1 ) // Stack is full return -1
  {
    retVal = -1;
  }
  else // push element to stack 
  {
    ++top; 
    Stack[top] = elem;     
    retVal = 1;
  }

  return retVal;
}

int Pop(int* elem)
{
  int retVal = 0;
  
  if ( top < 0 ) // Stack is empty so return -1
  {
    retVal = -1;
  }
  else if (top >= STACK_SIZE)  // Stack is over flow return -1 ( top == -1 )  // Stack is empty push the element to the first cell 
  {
    retVal = -1;
  }
  else 
  {    
    *elem = Stack[top];
    
    // Reset the value in the popped cell
    Stack[top] = INIT_VALUE;
    
    top--; 
    retVal = 1;
  }

  return retVal;
}

int IsStackEmpty()
{
  return ( top < 0 ? 1 : -1 );
}

int IsStackFull()
{
  return (top >= (STACK_SIZE - 1) );
}