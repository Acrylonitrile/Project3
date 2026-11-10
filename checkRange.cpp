#include"checkRange.h"


// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose: 
// This function checks whether the input value falls in the range 
// (minValue, maxValue)


bool checkRange(const int inValue, const int minValue, const int maxValue)
{
    if(inValue < minValue || inValue > maxValue)
    {
        return false;
    }
    else
    {
        return true;
    }
}