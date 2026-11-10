#include"clipValue.h"

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose: 
// clips an Input value between minimum and maximum value
bool clipValue(int &inputVal, const int maxValue, const int minValue)
{
    if(inputVal < minValue)
    {
        inputVal = minValue;
        return true;
    }
    if(inputVal > maxValue)
    {
        inputVal = maxValue;
        return true;
    }
    return false;
}
