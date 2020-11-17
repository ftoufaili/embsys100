#include <assert.h>
#include "stack.h"

  int result1;
  int result2; 
  
  
// **************************************************
// Test: Retrive item from an empty Stack
// **************************************************
void TestRetriveFromEmptyStack()
{
  // Arrange:
  result1 = 42;
  int element = 7; 
  InitStack(); 
  
  // Act:
  result1 = Pop(&element); 
    
  // Assert:
  assert( -1 == result1); 
  assert( 7 == element); 
}

// **************************************************
// Test: Push an item to stack then pop it back 
// **************************************************
void TestPushAndPop()
{
  // Arrange:
  result1 = -1;
  result2 = -1; 
  
  int element = 7; 
  InitStack(); 
  
  // Act:
  result1 = Push(42); 
  result2 = Pop(&element); 
   
  // Assert:
  assert( 1 == result1); 
  assert( 1 == result2); 
  assert( 42 == element); 
}


// **************************************************
// Test: Fill the Stack with values 
// **************************************************
void TestFillStack()
{
  // Arrange:
  result1 = -1;
  result2 = -1; 
  
  InitStack(); 
  
  int num = 0;
  
  while( IsStackFull() != 1)
  {
    //Act:
    result1 = Push(num);
    
    // Assert: 
    assert( 1 == result1); 
      
    num++;
  }
  
  // Act:
  result2 = IsStackEmpty(); 
  
  // Assert: 
  assert( -1 == result2); 
   
    // Act:
  result1 = Push(2); 
  
  // Assert: 
  assert( -1 == result1); 
}


// **************************************************
// Test: Filling out the Stack then pop all its values 
// **************************************************
void TestEmptyStack()
{
  // Arrange:
  result1 = -1;
  result2 = -1; 
  
  InitStack(); 
  
  int num = 0;
  int value = -1; 
  
  // Act:
  // fill out the stack first
  while( IsStackFull() != 1)
  {
    //Act:
    result1 = Push(num);
    
    // Assert: 
    assert( 1 == result1); 
      
    num++;
  }
  
  // test popping the results now
  while( IsStackEmpty() == -1)
  {
    num--;
    
    //Act:
    result2 = Pop(&value);
    
    // Assert: 
    assert( 1 == result2); 
    assert (value == num );
  }
   
  //Act:
  result1 = Push(num);

  // Assert: 
  assert( 1 == result1); 

  //act
  result2 = Pop(&value);
  
  // Assert: 
  assert( value == num);
  assert( 1 == result2);
}
