#ifndef VALIDATESINGLEINT_H
#define VALIDATESINGLEINT_H

#include<string>
using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose:
// This function Keeps prompting the user to provide input until it gets a
// valid input. Used for instances of the menu where re-prompting is needed.

void validateSingleInt(int &input, const string &inputPrompt, 
                       const string &errorMessage);

#endif