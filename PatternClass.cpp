#include"PatternClass.h"
#include"ColorClass.h"
#include"RowColumnClass.h"
#include"checkRange.h"
#include"constants.h"
#include<fstream>
#include<string>
#include<iostream>

using namespace std;

PatternClass::PatternClass(): height(0), width(0), patternValues(0)
{ ; }

void PatternClass::initializePattern(const int inHeight, const int inWidth)
{
    height = inHeight;
    width = inWidth;
    patternValues = new int*[height];
    for(int rowIndex = 0; rowIndex < height; rowIndex++)
    {
        patternValues[rowIndex] = new int[width];
    }

}

PatternClass::~PatternClass()
{
    for(int rowIndex = 0; rowIndex < height; rowIndex++)
    {
        delete [] patternValues[rowIndex];
    }
    delete [] patternValues;
}

bool PatternClass::readPatternFromFile(string &inputFileName, 
                                       string &errorMessage)
{
    ifstream inFile;
    inFile.open(inputFileName.c_str());
    if(inFile.fail())
    {
        errorMessage = ERROR_OPEN_PATTERN_FILE + inputFileName;
        inFile.close();
        return false;
    }
    else
    {
        inFile >> width >> height;

        //Validating width and height
        if(inFile.fail())
        {
            errorMessage = ERROR_INCORRECT_DIMENSIONS;
            inFile.close();
            return false;
        }
        if(!checkRange(width,MIN_DIMENSION_VALUE,MAX_DIMENSION_VALUE) || 
           !checkRange(height,MIN_DIMENSION_VALUE,MAX_DIMENSION_VALUE))
        {
            errorMessage = ERROR_DIMENSIONS;
            inFile.close();
            return false;
        }
        else
        {
            initializePattern(height, width);
            for(int rowIndex = 0; rowIndex < height; rowIndex++)
            {
                for(int colIndex = 0; colIndex < width; colIndex++)
                {
                    // Checking if the values are 0/1 
                    if(!(inFile >> patternValues[rowIndex][colIndex]) ||
                       !checkRange(patternValues[rowIndex][colIndex],           
                                   MIN_PATTERN_VALUE, 
                                   MAX_PATTERN_VALUE))
                    {
                        errorMessage = ERROR_DATA;
                        inFile.close();
                        return false;
                    }
                }
            }
        }
    }
    // Checking if there are more values than necessary
    string extraValue;
    if(inFile >> extraValue)
    {
        inFile.close();
        return false;
    }
    inFile.close();
    return true;
}

bool PatternClass::getValueAtLocation(const RowColumnClass &inRowCOl, 
                                      int &outValue) const
{
    int rowIndex = inRowCOl.getRow();
    int colIndex = inRowCOl.getCol();


    bool isInRange = checkRange(rowIndex, IMG_MIN_ROW_INDEX, 
                                IMG_MIN_ROW_INDEX + height - 1) &&
                     checkRange(colIndex, IMG_MIN_COL_INDEX, 
                                IMG_MIN_COL_INDEX + width - 1);

    if(isInRange)
       {
            outValue = patternValues[rowIndex][colIndex];
            return true;
       }
       else
       {
        return false;
       }
}

ColorClass PatternClass::getPatternColor() const
{
    return patternColor;
}

void PatternClass::setPatternValue(const int inValue, 
                                  const int rowIndex,
                                  const int colIndex)
{
    patternValues[rowIndex][colIndex] = inValue;
}

void PatternClass::setPatternColor(ColorClass &inColor)
{
    patternColor = inColor;
}


void PatternClass::setToRectangle(const bool isFilled)
{
    for(int rowIndex = 0; rowIndex < height; rowIndex++)
    {
        for(int colIndex = 0; colIndex < width; colIndex++)
        {
            // if filled, then the entire pattern is just 1's,
            // Otherwise only the border, forming a rectangle.
            if(isFilled || 
               rowIndex == 0 || rowIndex == height - 1 ||
               colIndex == 0 || colIndex == width - 1)
            {
                patternValues[rowIndex][colIndex] = 1;
            }
            else
            {
                patternValues[rowIndex][colIndex] = 0;
            }
        }
    }
}
