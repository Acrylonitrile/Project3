#include "PatternClass.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "checkRange.h"
#include "constants.h"
#include "validateSingleInt.h"
#include "validateTwoInts.h"
#include "getSingleString.h"
#include "printMenuOptions.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose:
// Encodes information on a given pattern, using height, widths, values 1/0
// and the color the user would like to draw the pattern in

PatternClass::PatternClass() : height(0), width(0), startRow(0), 
                               startCol(0), patternValues(0)
{ ; }

PatternClass::PatternClass(const int inHeight, const int inWidth):
                           height(inHeight), width(inWidth)
{
  initializePattern(inHeight,inWidth);
}

void PatternClass::initializePattern(const int inHeight, const int inWidth)
{
  clearPattern();
  height = inHeight;
  width = inWidth;
  patternValues = new int *[height];
  for (int rowIndex = 0; rowIndex < height; rowIndex++)
  {
    patternValues[rowIndex] = new int[width];
  }
}

PatternClass::~PatternClass()
{
  clearPattern();
}

void PatternClass::clearPattern()
{
  if (patternValues != 0)
  {
    for (int rowIndex = 0; rowIndex < height; rowIndex++)
    {
      delete[] patternValues[rowIndex];
    }
    delete[] patternValues;
  }
  patternValues = 0;
}

int PatternClass::getStartRow() const
{
  return startRow;
}

int PatternClass::getStartCol() const
{
  return startCol;
}

void PatternClass::readPatternAttributes()
{
  // reading and validating position input
  validateTwoInts(startRow, startCol,
                  PROMPT_ENTER_PATTERN_POSITION,
                  ERROR_DATA);

  // choosing color from menu
  patternColor.chooseColorFromMenu(PROMPT_PATTERN_COLOR);
}

bool PatternClass::readPatternFromFile(ifstream &inFile,
                                       string &errorMessage)
{
  inFile >> width >> height;

  // Validating width and height
  if (inFile.fail())
  {
    errorMessage = ERROR_INCORRECT_DIMENSIONS;
    inFile.close();
    return false;
  }
  if (!checkRange(width, MIN_DIMENSION_VALUE, MAX_DIMENSION_VALUE) ||
      !checkRange(height, MIN_DIMENSION_VALUE, MAX_DIMENSION_VALUE))
  {
    errorMessage = ERROR_DIMENSIONS_RANGE;
    inFile.close();
    return false;
  }
  //validation successful
  else
  {
    initializePattern(height, width);
    for (int rowIndex = 0; rowIndex < height; rowIndex++)
    {
      for (int colIndex = 0; colIndex < width; colIndex++)
      {
        // Checking if the values are 0/1 or missing
        if (!(inFile >> patternValues[rowIndex][colIndex]) ||
            !checkRange(patternValues[rowIndex][colIndex],
                        MIN_PATTERN_VALUE,
                        MAX_PATTERN_VALUE))
        {
          errorMessage = ERROR_PATTERN_FILE_VALUES;
          inFile.close();
          return false;
        }
      }
    }
  }
  
  // Checking if there are more values than necessary
  string extraValue;
  if (inFile >> extraValue)
  {
    inFile.close();
    errorMessage = ERROR_EXTRA_VALUES_PATTERN;
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

  if (isInRange)
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

void PatternClass::setPatternColor(const ColorClass &inColor)
{
  patternColor = inColor;
}

