#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

int InitStack(void);
int Push(int elem);
int Pop(int* elem); 
int IsStackEmpty();
int IsStackFull();

#endif //STACK_H_INCLUDED