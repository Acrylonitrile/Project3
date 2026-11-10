#include"getSingleIntInput.h"
#include"checkStreamState.h"
#include<iostream>

using namespace std;


bool getSingleIntInput(int &input)
{
    cin >> input;
    return checkStreamState();
}