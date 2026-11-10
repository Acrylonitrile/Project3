#include"validateTwoInts.h"
#include"getTwoIntInputs.h"
#include"constants.h"
#include<iostream>
#include<string>

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose: 
// Keeps prompting the used to provide 2 inputs until they are valid
void validateTwoInts(int &input1, int &input2, const string &inputPrompt, 
                     const string &errorMessage)
{
    bool isValid = false;
    while(!isValid)
    {
        cout << inputPrompt;
        isValid = getTwoIntInputs(input1, input2);
        if(!isValid)
        {
            cout << errorMessage << endl;
        }
    }
}