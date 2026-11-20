#include "getTwoIntInputs.h"
#include "constants.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose:
// helper function to get two integer inputs at the same time from user
// and validate the stream in the process

bool getTwoIntInputs(int &input1, int &input2)
{
  if (cin >> input1 >> input2)
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