#include"checkRange.h"

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