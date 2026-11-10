#include"printMenuOptions.h"
#include<string>
#include<iostream>

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose: 
// Used to print the memu options from a list of options of length numOptions

void printMenuOptions(const int numOptions,const string optionsList[])
{
    for(int idx = 0; idx < numOptions; idx++)
    {
        cout << optionsList[idx] << endl;
    }
}