#include"getSingleString.h"
#include"constants.h"
#include<iostream>
#include<string>

using namespace std;


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