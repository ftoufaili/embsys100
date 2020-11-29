#include <assert.h>


void SwapPointers(int** xptr, int** yptr)
{
  int* tempPtr = *xptr; 
  *xptr = *yptr;
  *yptr = tempPtr; 
}

int main()
{
  int x = 10; 
  int y = 20; 
  
  int* xPtr = &x; 
  int* yPtr = &y; 
  
  SwapPointers(&xPtr, &yPtr);
  
  assert ( x = 10 );
  assert ( y = 20 ); 
  assert ( xPtr == &y ); 
  assert ( yPtr == &x );  
  assert ( *xPtr == 20 ); 
  assert ( *yPtr == 10 ); 

  return 0;
}
