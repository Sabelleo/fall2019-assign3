#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "GenStack.h"

using namespace std;

class Check
{
  public:
    Check(); //constructor
    ~Check(); //destructor

    // use 1 or 2 methods
    bool matchCheck(string delimStr);
    void addDelimiters(string file);
    //method that gets initial file and runs other methods, asking for more files if the previous is okay.
    void getFile(string file);

    // Used to store sequence of symbols before we encounter an error
    string lastSequence;
    // Used to store status message
    string message;

    string m_choice;
    string m_file_name;


};
