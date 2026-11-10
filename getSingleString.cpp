#include"getSingleString.h"
#include"constants.h"
#include<iostream>
#include<string>

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose: 
// helper function to get single string input from user
// and validate the stream in the process

bool getSingleString(string &inputString)
{
    if(cin >> inputString)
    {
        return true;
    }
    cin.clear();
    cin.ignore(NUM_IGNORE, '\n');
    return false;
}