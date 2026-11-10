#include"getTwoIntInputs.h"
#include"constants.h"
#include<iostream>

using namespace std;

bool getTwoIntInputs(int &input1, int &input2)
{
    if(cin >> input1 >> input2)
    {
        return true;
    }
    cin.clear();
    cin.ignore(NUM_IGNORE, '\n');
    return false;
}