#ifndef VALIDATESINGLEINT_H
#define VALIDATESINGLEINT_H

#include<string>
using namespace std;


// Keeps prompting the user to provide input until it gets a
// valid input
void validateSingleInt(int &input, const string &inputPrompt, 
                       const string &errorMessage);

#endif