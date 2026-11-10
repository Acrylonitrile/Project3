#include"getSingleIntInput.h"
#include"constants.h"
#include<iostream>

using namespace std;


bool getSingleIntInput(int &input)
{
    if(cin >> input)
    {
        return true;
    }
    cin.clear();
    cin.ignore(NUM_IGNORE, '\n');
    return false;
}