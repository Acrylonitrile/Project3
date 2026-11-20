#include "getSingleString.h"
#include "constants.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose:
// helper function to get single string input from user
// and validate the stream in the process

bool getSingleString(string &inputString)
{
  if (cin >> inputString)
  {
    return true;
  }
  if (cin.eof())
  {
    cout << ERROR_EOF << endl;
    exit(EXIT_CODE_INPUT_ERROR);
  }
  cin.clear();
  cin.ignore(NUM_IGNORE, '\n');
  return false;
}