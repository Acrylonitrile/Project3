#include"validateSingleInt.h"
#include"getSingleIntInput.h"
#include"constants.h"
#include<iostream>
#include<string>

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose: 
// This function Keeps prompting the user to provide input until it gets a
// valid input. 

void validateSingleInt(int &input, const string &inputPrompt, const 
                       string &errorMessage)
{
    bool isValid = false;
    while(!isValid)
    {
        cout << inputPrompt;
        isValid = getSingleIntInput(input);
        if(!isValid)
        {
            cout << errorMessage << endl;
        }
    }
}