#include"validateSingleInt.h"
#include"getSingleIntInput.h"
#include"constants.h"
#include<iostream>
#include<string>

using namespace std;



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