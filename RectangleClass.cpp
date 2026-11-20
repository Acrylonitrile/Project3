#include"RectangleClass.h"
#include"ColorClass.h"
#include"constants.h"
#include"validateSingleInt.h"
#include"validateTwoInts.h"
#include"getSingleIntInput.h"
#include"printMenuOptions.h"
#include"RowColumnClass.h"
#include"checkRange.h"
#include<string>
#include<iostream>

using namespace std;


// Programmer: Anhad Bhati
// Date: November 10, 2026
//
// Purpose:
// Encodes information on a given rectangle, including starting row, column, 
// height, width, filled or not filled, color. 

RectangleClass::RectangleClass(): height(0), width(0), startRow(0), startCol(0),
                                  isFilled(false)
{
  ColorClass whiteColor;
  rectangleColor = whiteColor;
}

int RectangleClass::getStartRow() const
{
  return startRow;
}

int RectangleClass::getStartCol() const
{
  return startCol;
}

bool RectangleClass::getIsFilled() const
{
  return isFilled;
}

ColorClass RectangleClass::getRectangleColor() const
{
  return rectangleColor;
}

bool RectangleClass::getValueAtLocation(const RowColumnClass &inRowCOl) const
{
  int rowIndex = inRowCOl.getRow();
  int colIndex = inRowCOl.getCol();

  bool isInRange = checkRange(rowIndex, IMG_MIN_ROW_INDEX,
                              IMG_MIN_ROW_INDEX + height - 1) &&
                   checkRange(colIndex, IMG_MIN_COL_INDEX,
                              IMG_MIN_COL_INDEX + width - 1);

  // should be in range and on the boundary or else within the boundary
  // and filled to have color
  if(isInRange && 
    (isFilled || 
    rowIndex == 0 || rowIndex == height - 1 ||
    colIndex == 0 || colIndex == width - 1))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool RectangleClass::readRectanglefromInput(string &errorMessage)
{
  int inputOption;
  // variable to keep track of whether all the inputs are satisfactory
  bool isValidOption = false;

  while(!isValidOption)
  {
    // Prints menu for user to choose how to provide inputs
    printMenuOptions(NUM_RECTANGLE_OPTIONS,RECTANGLE_MENU_OPTIONS);
    cout << PROMPT_RECTANGLE_OPTION;
    bool isOptionValid = getSingleIntInput(inputOption);
    
    // Error in case of out of bounds input of failed stream
    if(!isOptionValid || 
       !checkRange(inputOption, MIN_MENU_CHOICE, NUM_RECTANGLE_OPTIONS))
    {
      cout << ERROR_INVALID_MENU << endl;
    }
    else 
    {
      isValidOption = true;
    }
  }
  if(inputOption == RECTANGLE_CORNER_OPTION)
  {
    int upLeftRow, upLeftCol, lowRightRow, lowRightCol;

    validateTwoInts(upLeftRow,upLeftCol,
                    PROMPT_RECTANGLE_INPUT_1_1, 
                    ERROR_DATA);
    validateTwoInts(lowRightRow,lowRightCol,
                    PROMPT_RECTANGLE_INPUT_1_2, 
                    ERROR_DATA);
    startRow = upLeftRow;
    startCol = upLeftCol;
    height = lowRightRow - upLeftRow + 1;
    width = lowRightCol - upLeftCol + 1;
  }

  // When one corner and width height are specified
  else if(inputOption == RECTANGLE_DIMENSIONS_OPTION)
  {
    validateTwoInts(startRow,startCol,
                    PROMPT_RECTANGLE_INPUT_2_1, 
                    ERROR_DATA);
    validateSingleInt(height, PROMPT_RECTANGLE_INPUT_2_2, ERROR_DATA);
    validateSingleInt(width, PROMPT_RECTANGLE_INPUT_2_3, ERROR_DATA);
  }

  // When user specified the center and half of width and height
  else if(inputOption == RECTANGLE_CENTRE_OPTION)
  {
    int rowCenter, colCenter, halfWidth, halfHeight;
    validateTwoInts(rowCenter,colCenter,
                    PROMPT_RECTANGLE_INPUT_3_1, 
                    ERROR_DATA);
    validateSingleInt(halfHeight, PROMPT_RECTANGLE_INPUT_3_2, ERROR_DATA);
    validateSingleInt(halfWidth, PROMPT_RECTANGLE_INPUT_3_3, ERROR_DATA);
  
    height = 2 * halfHeight + 1;
    width = 2 * halfWidth + 1;
    startRow = rowCenter - halfHeight;
    startCol = colCenter - halfWidth;
  }
  // Check if calculated heightand width are valid
  if(height > 0 && width > 0)
  {
    // Makes the used choose the color which they want to use
    
    rectangleColor.chooseColorFromMenu(PROMPT_RECTANGLE_COLOR);

    // Makes the user choose the fill options, and checks for bad input
    bool isValidFillValue = false;
    int fillValue;
    while(!isValidFillValue)
    {
      printMenuOptions(NUM_FILL_OPTIONS, RECTANGLE_FILL_OPTIONS);
      cout << PROMPT_RECTANGLE_FILL;
      isValidFillValue = getSingleIntInput(fillValue) &&
                        (fillValue == FILL_NO || fillValue == FILL_YES);
      if(!isValidFillValue)
      {
        cout << ERROR_INVALID_MENU << endl;
      }
    }
    isFilled = (fillValue == FILL_YES);

    return true;
  }
  else
  {
    errorMessage = ERROR_RECTANGLE_DIMENSIONS;
    return false;
  }
}