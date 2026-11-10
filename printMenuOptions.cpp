#include"printMenuOptions.h"
#include<string>
#include<iostream>

using namespace std;

void printMenuOptions(const int numOptions,const string optionsList[])
{
    for(int idx = 0; idx < numOptions; idx++)
    {
        cout << optionsList[idx] << endl;
    }
}