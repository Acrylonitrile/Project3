#include"checkStreamState.h"
#include"constants.h"
#include<iostream>


// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose: 
// This is a Helper function to check stream state after input and clear the 
// stream

using namespace std;

bool checkStreamState()
{
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(NUM_IGNORE, '\n');
        return false;
    }
    else
    {
        return true;
    }
}