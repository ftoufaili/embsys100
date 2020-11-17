//#include<assert.h>
#include "stack.c"

#include "TestCases.c"

int main()
{
  // Test Stack
  TestRetriveFromEmptyStack();
  TestPushAndPop(); 
  TestFillStack(); 
  TestEmptyStack();
  
  return 0;
}
