#include "GenStack.h"
#include <iostream>

using namespace std;

template <typename E> GenStack<E>::GenStack() //default constructor
{
  myArray = new E[128];
  size = 128;
  top = -1;
}

template <typename E> GenStack<E>::GenStack(int maxSize) //overloaded constructor
{
  myArray = new E[maxSize];
  size = maxSize;
  top = -1;
}

template <typename E> GenStack<E>::~GenStack() //destructor
{
  delete[] myArray;
}

template <typename E> void GenStack<E>::push(const E& e)
{
  if (isFull()) //double the stack size if full
  {
    doubleSize();
    myArray[++top] = e;
  }
}

template <typename E> E& GenStack<E>::pop() //throw(StackEmpty)
{
  if(isEmpty())
  {
    cout << "Sorry, your stack is empty!" << endl; //replace with something else
  }
  return myArray[top--];
}

template <typename E> const E& GenStack<E>::peek() //const throw(StackEmpty)
{
  if (isEmpty())
  {
    cout << "Sorry, your stack is empty!" << endl; //replace with something else
  }
  return myArray[top];
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
  E* doubleArray = new E[size * 2];
  for (int i = 0; i < size; i++)
  {
    doubleArray[i] = myArray[i];
  }
  delete[] myArray;
  size = size*2;
  myArray = new E[size];
  myArray = doubleArray;
  delete[] doubleArray;
}
