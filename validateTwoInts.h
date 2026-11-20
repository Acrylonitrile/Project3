#ifndef VALIDATETWOINTS_H
#define VALIDATETWOINTS_H

#include<string>
using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose:
// Keeps prompting the used to provide 2 inputs until they are valid

void validateTwoInts(int &input1, int &input2, const string &inputPrompt,  
                     const string &errorMessage);

#endif