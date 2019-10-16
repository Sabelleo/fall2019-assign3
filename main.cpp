#include "GenStack.h"
#include <iostream>

using namespace std;

int main (int argc, char **argv)
{
  GenStack myStack(20);

  myStack.push('H');
  myStack.push('a');
  myStack.push('p');
  myStack.push('p');
  myStack.push('y');
  myStack.push(' ');
  myStack.push('B');
  myStack.push('i');
  myStack.push('r');
  myStack.push('t');
  myStack.push('h');
  myStack.push('d');
  myStack.push('a');
  myStack.push('y');
  myStack.push('?');

  cout << "popping: " << myStack.pop() << endl;
  cout << "peek-a-boo: " << myStack.peek() << endl;
  myStack.push('!');
  cout << "peek-a-boo: " << myStack.peek() << endl;

  while(!myStack.isEmpty())
  {
    cout << "popping: " << myStack.pop() << endl;
  }

  cout << "is stack empty?" << myStack.isEmpty() << endl;
  return 0;
};
