#include <iostream>

using namespace std;

template <typename E> class GenStack
{
  public:
    GenStack(); //constructor
    GenStack(int maxSize); //overloaded constructor
    ~GenStack(); //destructor

    void push(const E& e);
    E& pop();
    const E& peek(); //'top'

    bool isFull();
    bool isEmpty();
    void doubleSize();

    int size;
    int top;

    E *myArray; //pointer!!!
};
