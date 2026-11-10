#include"getTwoIntInputs.h"
#include"constants.h"
#include"checkStreamState.h"
#include<iostream>

using namespace std;

bool getTwoIntInputs(int &input1, int &input2)
{
    cin >> input1 >> input2;
    return checkStreamState();
}