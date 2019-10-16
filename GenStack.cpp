#include "GenStack.h"
#include <iostream>

using namespace std;

template <typename E> GenStack<E>::GenStack() //default constructor
{
  myStack = new E[128];
  size = 128;
  top = -1;
}

template <typename E> GenStack<E>::GenStack(int maxSize) //overloaded constructor
{
  myStack = new E[maxSize];
  size = maxSize;
  top = -1;
}

template <typename E> GenStack<E>::~GenStack() //destructor
{
  delete[] myStack;
}

template <typename E> void GenStack<E>::push(const E& e)
{
  if (isFull()) //double the stack size if full
  {
    doubleSize();
    myStack[++top] = e;
  }
}

template <typename E> E& GenStack<E>::pop()
{
  if(isEmpty())
  {
    cout << "Sorry, your stack is empty!" << endl;
  }
  return myStack[top--];
}

template <typename E> const E& GenStack<E>::peek()
{
  if (isEmpty())
  {
    cout << "Sorry, your stack is empty!" << endl;
  }
  return myStack[top];
}

template <typename E> bool GenStack<E>::isFull()
{
  return (top == size-1); //true if full
}

template <typename E> bool GenStack<E>::isEmpty()
{
  return (top == -1); //true if empty
}

template <typename E> void GenStack<E>::doubleSize()
{
  E* doubleStack = new E[size * 2];
  for (int i = 0; i < size; i++)
  {
    doubleStack[i] = myStack[i];
  }
  delete[] myStack;
  size = size*2;
  myStack = new E[size];
  myStack = doubleStack;
  delete[] doubleStack;
}
