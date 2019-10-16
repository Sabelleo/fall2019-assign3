#include "check.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

Check::Check() //constructor
{
  lastSequence = ""; //create empty variables
  message = "";
}

Check::~Check() //destructor
{
}

void Check::getFile(string file)
{
  cout << "Checking " << file << " for mismatched delimiters: " << endl;

// run the get the file of delimiters Program, saving values
// run the return the first error Program, saving values
//tell user if syntax was ok, or where the error was.
// if files are OK::::

  while (m_choice != "Yes" && m_choice != "No")
  {
    cout << "Since your file delimiters were ok, would you like to enter another file? Type 'Yes', or 'No' to exit. " << endl;
    cin >> m_choice;
  }

  while (m_choice == "Yes")
  {
    cout << "Enter the name of the file you would like to analyze: " << endl;
    cin >> file;

    // run the get the file of delimiters Program, saving values
    // run the return the first error Program, saving values
    //tell user if syntax was ok, or where the error was.
    // if files are OK::::

    while (m_choice != "Yes" && m_choice != "No")
    {
      cout << "Since your file delimiters were ok, would you like to enter another file? Type 'Yes' or 'No' to exit. " << endl;
      cin >> m_choice;
    }
  }
}

void Check::addDelimiters(string file)
{
  string totalFile = "";
  ifstream fl;
  string line;
  fl.open(file);
  if (fl.is_open())
  {
    while(getline(fl, line, '\n')) // go through file line by line
    {
      string line_cleaned = "";
      for (int i = 0; i < line.size(); ++i) //go through each line in file
      {
        char myChar = line[i]; //DOES THIS WORK TO CONVERT????
        switch(myChar) //add symbol to new string if delimiter
        {
          case '[':
          {
            line_cleaned += '[';
            continue;
          }
          case ']':
          {
            line_cleaned += ']';
            continue;
          }
          case '{':
          {
            line_cleaned += '{';
            continue;
          }
          case '}':
          {
            line_cleaned += '}';
            continue;
          }
          case '(':
          {
            line_cleaned += '(';
            continue;
          }
          case ')':
          {
            line_cleaned += ')';
            continue;
          }
          default: //char is not delimiter
          {
            continue;
          }
        }
      }
      //add delimiters from line to string
      totalFile += line_cleaned;
    }
    fl.close();
  }

  if (matchCheck(totalFile)) //no errors found
  {
    cout << message << endl;
  }
  else //delimiter error found
  {
    cout << message << endl;

    //still need to find the line number that the error was on!!!
    fl.open(file);
    int lineNum = 0;
    if (file.is_open())
    {
      while(getline(fl, line, '\n')) //loop through lines in file
      {
        for (int i = 0; i < line.size(); ++i) //iterate through chars in a line
        {
          //we use lastSequence to find the line that the mess up happens on in the file
        }
        lineNum++;
      }
      fl.close();
      //print line number
      cout << "Error is on line " << lineNum << endl;
    }
  }
}




bool Check::matchCheck(string delimStr)
{
  GenStack<char> delimStack(delimStr.size()); //create empty stack
  for (int i = 0; i < delimStr.size(); ++i) //for loop through string, 0 through size-1
  {
    // This prior sequence string will capture delimiters to help us locate errors
    lastSequence += delimStr.at(i);
    //if it's an opening symbol, push to stack
    if (delimStr.at(i) == '(' || delimStr.at(i) == '[' || delimStr.at(i) == '{')
    {
      delimStack.push(delimStr.at(i));
    }
    //else if it's a closing grouping symbol then see if it matchs stack peek
    else if (delimStr.at(i) == ')' || delimStr.at(i) == ']' || delimStr.at(i) == '}')
    {
      //if stack is empty, missing a delimiter and return false
      if (delimStack.isEmpty())
      {
        if (delimStr.at(i) == ')')
        {
          message = "You are missing a '(' to match your ')'.";
          return false;
        }
        else if (delimStr.at(i) == ']')
        {
          message = "You are missing a '[' to match your ']'.";
          return false;
        }
        else if (delimStr.at(i) == '}')
        {
          message = "You are missing a '{' to match your '}'.";
          return false;
        }
      }

      //if top() doesn't match char, wrong delimiter type & return false
      if (delimStack.peek() != '(' && delimStr.at(i) == ')' ) //mismatched ')' has 2 cases, [ and {
      {
        if (delimStack.peek() == '[')
        {
          message = "Error! You have a mismatched pair. It should either be '()' or '[]'. ";
          return false;
        }
        else if (delimStack.peek() == '{')
        {
          message = "Error! You have a mismatched pair. It should either be '()' or '{}'. ";
          return false;
        }
      }
      if (delimStack.peek() != '[' && delimStr.at(i) == ']' ) //mismatched ']' has 2 cases, { and (
      {
        if (delimStack.peek() == '{')
        {
          message = "Error! You have a mismatched pair. It should either be '{}' or '[]'. ";
          return false;
        }
        else if (delimStack.peek() == '(')
        {
          message = "Error! You have a mismatched pair. It should either be '()' or '[]'. ";
          return false;
        }
      }
      if (delimStack.peek() != '{' && delimStr.at(i) == '}' ) //mismatched '}' has 2 cases, [ and (
      {
        if (delimStack.peek() == '(')
        {
          message = "Error! You have a mismatched pair. It should either be '()' or '{}'. ";
          return false;
        }
        else if (delimStack.peek() == '[')
        {
          message = "Error! You have a mismatched pair. It should either be '{}' or '[]'. ";
          return false;
        }
      }
      delimStack.pop(); //if valid, pop
    }
  }
  if (delimStack.isEmpty()) //if empty, every delimiter is matched
  {
    message = "All delimiters have matches! Your code has no issues with delimiters.";
    return true;
  }
  else
  {
    message = "At least a few delimiters don't have matches at the end of your code. Fix the issue and try again!";
    return false;
  }
}
