#include"getSingleIntInput.h"
#include"constants.h"
#include<iostream>
#include<cstdlib>

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose: 
// helper function to get single integer input from user
// and validate the stream in the process

bool getSingleIntInput(int &input)
{
    if(cin >> input)
    {
        return true;
    }
    if(cin.eof())
    {
        cout << "End of file reached" << endl;
        exit(3);
    }
    cin.clear();
    cin.ignore(NUM_IGNORE, '\n');
    return false;
}