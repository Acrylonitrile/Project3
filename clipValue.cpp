#include"clipValue.h"

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
