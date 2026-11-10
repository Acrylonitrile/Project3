#include"checkStreamState.h"
#include"constants.h"
#include<iostream>

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