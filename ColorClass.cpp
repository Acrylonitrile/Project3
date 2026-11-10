#include"ColorClass.h"
#include"clipValue.h"
#include"constants.h"
#include"checkRange.h"
#include<iostream>
#include<fstream>

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose: 
// Objects of this class represent a pixel, with RGB values and functionality to
// be set to a desired colour and read pixel values from input file

bool ColorClass::clipColorValues()
{
    bool isRedClipped, isGreenClipped, isBlueClipped;

    // Clip RGB values and return true when at least one of the values has 
    // been clipped
    isRedClipped = clipValue(redValue, MAX_COLOR_VALUE, MIN_COLOR_VALUE);
    isBlueClipped = clipValue(blueValue, MAX_COLOR_VALUE, MIN_COLOR_VALUE);
    isGreenClipped = clipValue(greenValue, MAX_COLOR_VALUE, MIN_COLOR_VALUE);

    return (isRedClipped || isBlueClipped || isGreenClipped);
}

ColorClass::ColorClass():redValue(MAX_COLOR_VALUE),
                         greenValue(MAX_COLOR_VALUE),
                         blueValue(MAX_COLOR_VALUE)
{ ; }

ColorClass::ColorClass(const int intRed, const int inGreen, const int inBlue):
                       redValue(intRed), greenValue(inGreen),blueValue(inBlue)
{
    clipColorValues();
}


bool ColorClass::readColorFromFile(ifstream &inFile, string &errorMessage)
{

    inFile >> redValue >> greenValue >> blueValue;
    if(inFile.fail())
    {
        errorMessage = ERROR_INVALID_COLORS;
        return false;
    }

    bool isColorInRange = checkRange(redValue,
                                    MIN_COLOR_VALUE,
                                    MAX_COLOR_VALUE)
                        && checkRange(greenValue,
                                    MIN_COLOR_VALUE,
                                    MAX_COLOR_VALUE)
                        && checkRange(blueValue,
                                    MIN_COLOR_VALUE,
                                    MAX_COLOR_VALUE);
    if(isColorInRange)
    {
        setTo(redValue,greenValue,blueValue);
        return true;
    }
    else
    {
        errorMessage = ERROR_COLOR_OUT_OF_RANGE;
        return false;
    }
}

bool ColorClass::setTo(const int inRed, const int inGreen, const int inBlue)
{
    bool isColorClipped;
    redValue = inRed;
    greenValue = inGreen;
    blueValue = inBlue;
    isColorClipped = clipColorValues();
    return isColorClipped;
}

bool ColorClass::setTo(const ColorClass &inColor)
{
    bool isColorClipped;
    isColorClipped = setTo(inColor.redValue, 
                           inColor.greenValue, 
                           inColor.blueValue);
    return isColorClipped;
}

bool ColorClass::compareColor(const ColorClass &rhsColor) const
{
    return (redValue == rhsColor.redValue) && 
           (greenValue == rhsColor.greenValue) &&
           (blueValue == rhsColor.blueValue);
}


void ColorClass::setToBlack()
{
    setTo(MIN_COLOR_VALUE,MIN_COLOR_VALUE,MIN_COLOR_VALUE);
}

void ColorClass::setToRed()
{
    setTo(MAX_COLOR_VALUE,MIN_COLOR_VALUE,MIN_COLOR_VALUE);
}

void ColorClass::setToGreen()
{
    setTo(MIN_COLOR_VALUE,MAX_COLOR_VALUE,MIN_COLOR_VALUE);
}

void ColorClass::setToBlue()
{
    setTo(MIN_COLOR_VALUE,MIN_COLOR_VALUE,MAX_COLOR_VALUE);
}

void ColorClass::setToWhite()
{
    setTo(MAX_COLOR_VALUE,MAX_COLOR_VALUE,MAX_COLOR_VALUE);
}

void ColorClass::printComponentValues(ofstream &outFile) const
{
    outFile << redValue 
         << " " << greenValue 
         << " " << blueValue;
}

void ColorClass::setToUserOption(int userOption)
{
    if(userOption == NUM_RED_OPTION)
    {
        setToRed();
    }
    else if(userOption == NUM_GREEN_OPTION)
    {
        setToGreen();
    }
    else if(userOption == NUM_BLUE_OPTION)
    {
        setToBlue();
    }
    else if(userOption == NUM_BLACK_OPTION)
    {
        setToBlack();
    }
    else if(userOption == NUM_WHITE_OPTION)
    {
        setToWhite();
    }
}
